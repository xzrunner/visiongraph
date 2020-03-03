#include "visiongraph/comp/FileInput.h"

#include <opencv2/opencv.hpp>

namespace vg
{
namespace comp
{

void FileInput::Execute(const std::shared_ptr<dag::Context>& ctx)
{
    auto mat = cv::imread(m_filepath);
    if (mat.empty()) {
        m_img.reset();
        return;
    }

    m_img = std::make_shared<cv::Mat>(mat);
}

}
}