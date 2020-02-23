#pragma once

#include "visiongraph/typedef.h"

namespace cv { class Mat; }

namespace vg
{

class CompHelper
{
public:
    static CompPtr GetInputComp(const Component& comp, size_t idx);

    static std::shared_ptr<cv::Mat>
        GetInputImage(const Component& comp, size_t idx);

}; // CompHelper

}