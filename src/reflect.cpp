#include <Eigen/Core>

Eigen::Vector3d reflect(const Eigen::Vector3d & in, const Eigen::Vector3d & n)
{
    return (2 * (in.dot(n))*n - in).normalized();
}
