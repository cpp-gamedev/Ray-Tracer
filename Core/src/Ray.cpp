#include "../include/Ray.h"

Ray::Ray() {}

Ray::Ray(const lm::vec3& origin, const lm::vec3& direction)
{
	this->origin = origin;
	this->direction = direction;
}

lm::vec3 Ray::lookAt(float& t) const
{
	return origin + t * direction;
}

lm::vec3 Ray::getOrigin() const
{
	return origin;
}

lm::vec3 Ray::getDirection() const
{
	return direction;
}