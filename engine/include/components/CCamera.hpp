#ifndef CCAMERA_HPP
#define CCAMERA_HPP

#include <cstddef>
#include <raylib.h>

struct CCamera
{
  Camera2D m_camera = {};
  std::size_t m_target = 0;
};

#endif // !CCAMERA_HPP
