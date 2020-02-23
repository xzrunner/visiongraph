#pragma once

#include "visiongraph/typedef.h"
#include "visiongraph/CompVarType.h"

#include <dag/Node.h>

#include <map>

namespace vg
{

class Evaluator
{
public:
    // update comp
    void CompChaged(const CompPtr& comp);

    // update components
    void AddComp(const CompPtr& comp);
    void RemoveComp(const CompPtr& comp);
    void ClearAllComps();

    // update comp prop
    void PropChanged(const CompPtr& comp);

    // update comp conn
    void Connect(const dag::Node<CompVarType>::PortAddr& from, const dag::Node<CompVarType>::PortAddr& to);
    void Disconnect(const dag::Node<CompVarType>::PortAddr& from, const dag::Node<CompVarType>::PortAddr& to);
    void RebuildConnections(const std::vector<std::pair<dag::Node<CompVarType>::PortAddr, dag::Node<CompVarType>::PortAddr>>& conns);

    void Update();

private:
    std::map<std::string, CompPtr> m_comps_map;

    bool m_dirty = false;

    size_t m_next_id = 0;

}; // Evaluator

}