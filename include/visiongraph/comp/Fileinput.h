#pragma once

#include "visiongraph/Component.h"

namespace vg
{
namespace comp
{

class FileInput : public Component
{
public:
    FileInput()
    {
        m_exports = {
            {{ CompVarType::Image, "out" }},
        };
    }

    virtual void Execute(const std::shared_ptr<dag::Context>& ctx = nullptr) override;

    RTTR_ENABLE(Component)

#define PARM_FILEPATH "visiongraph/comp/FileInput.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // FileInput

}
}