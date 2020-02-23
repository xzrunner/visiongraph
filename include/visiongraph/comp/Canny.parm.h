#ifndef PARAM_INFO
#error "You must define PARAM_INFO macro before include this file"
#endif

PARAM_INFO(Threshold1,   Float, threshold1,    m_threshold1,    (10))
PARAM_INFO(Threshold2,   Float, threshold2,    m_threshold2,    (100))
PARAM_INFO(ApertureSize, Int,   aperture_size, m_aperture_size, (3))
PARAM_INFO(L2Gradient,   Bool,  l2_gradient,   m_l2_gradient,   (false))
