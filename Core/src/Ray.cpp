#include "../include/Ray.h"

Ray::Ray(const lm::vec3& origin, const lm::vec3& direction) : origin(this->origin), direction(this->direction) {}

lm::vec3 Ray::lookAt(float& t) const
{
	return origin + t * direction;
}

lm::vec3 Ray::get_origin() const
{
	return origin;
}

lm::vec3 Ray::get_direction() const
{
	return direction;
}
