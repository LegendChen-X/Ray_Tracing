#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>
#include <math.h>

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
    
    Eigen::Vector3d rgb = Eigen::Vector3d(0,0,0);
    
    Eigen::Vector3d ka = objects[hit_id]->material->ka;
    Eigen::Vector3d kd = objects[hit_id]->material->kd;
    Eigen::Vector3d ks = objects[hit_id]->material->ks;
    double phong_exponent = objects[hit_id]->material->phong_exponent;
    
    Eigen::Vector3d q = ray.origin + t * ray.direction;
    
    rgb += (ka.array() * Eigen::Vector3d(0.1, 0.1, 0.1).array()).matrix();
    
    for(int i=0;i<lights.size();++i)
    {
        Eigen::Vector3d d;
        double max_t;
        lights[i]->direction(q,d,max_t);
        
        Ray shadow;
        shadow.origin = q;
        shadow.direction = d;
        
        int shadow_id;
        double shadow_max;
        Eigen::Vector3d shadow_n;
        
        if(!first_hit(shadow,1.0e-7,objects,shadow_id,shadow_max,shadow_n) || shadow_max>=max_t)
        {
            Eigen::Vector3d v = -ray.direction.normalized();
            Eigen::Vector3d l = shadow.direction.normalized();
            Eigen::Vector3d h = (v+l).normalized();
            
            double n_l = n.dot(l);
            double n_h = n.dot(h);
            
            rgb += (kd.array()*lights[i]->I.array()).matrix()*fmax(0,n_l);
            
            rgb += (ks.array()*lights[i]->I.array()).matrix()*pow(fmax(0,n_h),
            phong_exponent);
        }
    }
    
    return rgb;
  
}
