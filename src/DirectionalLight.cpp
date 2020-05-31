#include "DirectionalLight.h"
#include <limits>

void DirectionalLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{
    max_t = max_t = (double)0xFFFFFFFFFFFFFFFF;
    
    d = (-this->d).normalized;
}

