#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
    ray.origin = camera.e;
    
    double r = (double)camera.width / 2;
    double l = -r;
    
    double t = (double)-camera.height / 2;
    double b = -t;
    
    double u = l + (r - l) * (j + 0.5) / width;
    double v = b + (t - b) * (i + 0.5) / height;
    
    ray.direction = -camera.d * camera.w + camera.u * u + camera.v * v;
}

