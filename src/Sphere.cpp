#include "Sphere.h"
#include "Ray.h"
#include <cmath>

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
    Eigen::Vector3d c = center;
    Eigen::Vector3d d = ray.direction;
    Eigen::Vector3d e = ray.origin;
    
    double r = radius;
    double A = d.dot(d);
    double B = 2 * d.dot(e - c);
    double C = (e - c).dot(e - c) - r * r;

    double delta =  B * B - 4 * A * C;
    
    int flag = 0;
    
    if(delta >= 0)
    {
        Eigen::Vector3d point;
        double root_1 = (-B + sqrt(delta)) / (2 * A);
        double root_2 = (-B - sqrt(delta)) / (2 * A);
        
        if(root_1 >= min_t && root_2 < min_t)
        {
            flag = 1;
            t = root_1;
            point = e + t * d;
            n = (point - c) / r;
        }
        
        else if(root_1 >= min_t && root_2 >= min_t)
        {
            flag = 1;
            t = root_2;
            point = e + t * d;
            n = (point - c) / r;
        }
        
        else flag = 0;
    }
    
    return flag;
}
