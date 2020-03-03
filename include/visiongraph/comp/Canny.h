#pragma once

#include "visiongraph/Component.h"

namespace vg
{
namespace comp
{

class Canny : public Component
{
public:
    Canny()
    {
        m_imports = {
            {{ CompVarType::Image, "in" }},
        };
        m_exports = {
            {{ CompVarType::Image, "out" }},
        };
    }

    virtual void Execute(const std::shared_ptr<dag::Context>& ctx = nullptr) override;

    RTTR_ENABLE(Component)

#define PARM_FILEPATH "visiongraph/comp/Canny.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // Canny

}
}