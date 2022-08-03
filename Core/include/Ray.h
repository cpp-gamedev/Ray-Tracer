#pragma once
#ifndef RAYH
#define RAYH
#include "Vec3/vec3.h"

class Ray
{
	lm::vec3 origin, direction;

public:


	Ray();
	Ray(const lm::vec3& a, const lm::vec3& b);
	lm::vec3 lookAt(float& t) const;
	
	lm::vec3 getOrigin() const;
	lm::vec3 getDirection() const;
};

#endif
