#include "visiongraph/CompHelper.h"
#include "visiongraph/Component.h"

namespace vg
{

CompPtr CompHelper::GetInputComp(const Component& comp, size_t idx)
{
    auto& imports = comp.GetImports();
    if (idx < 0 || idx >= imports.size()) {
        return nullptr;
    }

    auto& conns = imports[idx].conns;
    if (conns.empty()) {
        return nullptr;
    }

    assert(imports[idx].conns.size() == 1);
    auto in_comp = imports[idx].conns[0].node.lock();
    assert(in_comp->get_type().is_derived_from<Component>());
    return std::static_pointer_cast<Component>(in_comp);
}

std::shared_ptr<cv::Mat>
CompHelper::GetInputImage(const Component& comp, size_t idx)
{
    auto prev_dev = GetInputComp(comp, idx);
    if (prev_dev) {
        return prev_dev->GetImage();
    } else {
        return nullptr;
    }
}

}