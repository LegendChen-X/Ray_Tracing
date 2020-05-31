#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
    double distance_buff = (double)0xFFFFFFFF;
    double t_buff;
    
    Eigen::Vector3d v_buff;
    
    int hit = 0;
    
    for(int i=0;i<objects.size();++i)
    {
        if(objects[i]->intersect(ray,min_t,t_buff,v_buff))
        {
            hit = 1;
            if(t_buff<distance_buff)
            {
                hit_id = i;
                distance_buff = t_buff;
                n = v_buff;
            }
        }
    }
    
    if(hit) t = distance_buff;
    
    return hit;
}

