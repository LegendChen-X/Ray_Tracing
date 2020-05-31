#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
    if(ray.direction.dot(normal) == 0) return false;
    
    double t_buff = -(normal.dot(ray.origin - point)) / normal.dot(ray.direction);
    
    if(t_buff>=min_t)
    {
        t = t_buff;
        n = normal;
        return true;
    }
    
    return false;
}

