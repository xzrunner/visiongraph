#include "visiongraph/comp/Canny.h"
#include "visiongraph/CompHelper.h"

#include <opencv2/opencv.hpp>

namespace vg
{
namespace comp
{

void Canny::Execute()
{
    auto prev_img = CompHelper::GetInputImage(*this, 0);
    if (!prev_img) {
        return;
    }

    cv::Mat img_cny;
    cv::Canny(*prev_img, img_cny, m_threshold1,
        m_threshold2, m_aperture_size, m_l2_gradient);

    m_img = std::make_shared<cv::Mat>(img_cny);
}

}
}