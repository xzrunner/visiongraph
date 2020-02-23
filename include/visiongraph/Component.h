#pragma once

#include "visiongraph/CompVarType.h"

#include <dag/Node.h>

namespace cv { class Mat; }

namespace vg
{

class Component : public dag::Node<CompVarType>
{
public:
    Component() {}

    virtual void Execute() = 0;

    auto GetImage() const { return m_img; }

protected:
    std::shared_ptr<cv::Mat> m_img = nullptr;

    RTTR_ENABLE(dag::Node<CompVarType>)

}; // Component

}