#include "visiongraph/Evaluator.h"
#include "visiongraph/Component.h"
#include "visiongraph/typedef.h"

#include <dag/Evaluator.h>

namespace vg
{

void Evaluator::CompChaged(const CompPtr& comp)
{
    dag::Evaluator::SetTreeDirty<CompVarType>(comp);

    m_dirty = true;
}

void Evaluator::AddComp(const CompPtr& comp)
{
    auto name = comp->GetName();
    while (name.empty() || m_comps_map.find(name) != m_comps_map.end())
    {
        if (comp->GetName().empty()) {
            name = "comp" + std::to_string(m_next_id++);
        } else {
            name = comp->GetName() + std::to_string(m_next_id++);
        }
    }
    comp->SetName(name);

    m_comps_map.insert({ name, comp });

    m_dirty = true;
}

void Evaluator::RemoveComp(const CompPtr& comp)
{
    if (m_comps_map.empty()) {
        return;
    }

    auto itr = m_comps_map.find(comp->GetName());
    if (itr == m_comps_map.end()) {
        return;
    }

    dag::Evaluator::SetTreeDirty<CompVarType>(comp);

    m_comps_map.erase(itr);

    m_dirty = true;
}

void Evaluator::ClearAllComps()
{
    if (m_comps_map.empty()) {
        return;
    }

    m_comps_map.clear();

    m_dirty = true;
}

void Evaluator::PropChanged(const CompPtr& comp)
{
    dag::Evaluator::SetTreeDirty<CompVarType>(comp);

    m_dirty = true;
}

void Evaluator::Connect(const dag::Node<CompVarType>::PortAddr& from, const dag::Node<CompVarType>::PortAddr& to)
{
    dag::make_connecting<CompVarType>(from, to);

    auto comp = to.node.lock();
    assert(comp && comp->get_type().is_derived_from<Component>());
    dag::Evaluator::SetTreeDirty<CompVarType>(std::static_pointer_cast<Component>(comp));

    m_dirty = true;
}

void Evaluator::Disconnect(const dag::Node<CompVarType>::PortAddr& from, const dag::Node<CompVarType>::PortAddr& to)
{
    dag::disconnect<CompVarType>(from, to);

    auto comp = to.node.lock();
    assert(comp && comp->get_type().is_derived_from<Component>());
    dag::Evaluator::SetTreeDirty<CompVarType>(std::static_pointer_cast<Component>(comp));

    m_dirty = true;
}

void Evaluator::RebuildConnections(const std::vector<std::pair<dag::Node<CompVarType>::PortAddr, dag::Node<CompVarType>::PortAddr>>& conns)
{
    // update dirty
    for (auto itr : m_comps_map) {
        if (dag::Evaluator::HasNodeConns<CompVarType>(itr.second)) {
            dag::Evaluator::SetTreeDirty<CompVarType>(itr.second);
        }
    }

    // remove conns
    for (auto itr : m_comps_map) {
        itr.second->ClearConnections();
    }

    // add conns
    for (auto& conn : conns)
    {
        auto comp = conn.second.node.lock();
        assert(comp && comp->get_type().is_derived_from<Component>());
        dag::Evaluator::SetTreeDirty<CompVarType>(std::static_pointer_cast<Component>(comp));
        dag::make_connecting<CompVarType>(conn.first, conn.second);
    }

    m_dirty = true;
}

void Evaluator::Update()
{
    if (m_comps_map.empty()) {
        return;
    }

    std::vector<std::shared_ptr<dag::Node<CompVarType>>> comps;
    comps.reserve(m_comps_map.size());
    for (auto itr : m_comps_map) {
        comps.push_back(itr.second);
    }
    auto sorted_idx = dag::Evaluator::TopologicalSorting(comps);

    for (auto& idx : sorted_idx)
    {
        auto comp = comps[idx];
        if (comp->IsDirty()) {
            std::static_pointer_cast<Component>(comp)->Execute();
            comp->SetDirty(false);
        }
    }
}

}