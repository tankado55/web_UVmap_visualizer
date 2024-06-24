#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include "glm/mat3x3.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/dual_quaternion.hpp"

struct LinearTransform
{
	glm::mat4 M;

	LinearTransform() : M(glm::mat4(1.0)) {}
	LinearTransform(glm::mat4 _M);
	LinearTransform(glm::vec3 a3, glm::vec3 b3, glm::vec3 c3,
					glm::vec2 a2, glm::vec2 b2, glm::vec2 c2);
	glm::vec3 apply(glm::vec3 point) const;
};

static LinearTransform mix(LinearTransform a, LinearTransform b, float t)
{
    return LinearTransform(a.M * (1 - t) + b.M * t);
}