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
#include "dualQuatTransform.h"
#include "linearTransform.h"
#include "homothety.h"

#include <iostream>

struct TestTransform
{
    Homothety homothety;
	DualQuatTransform dqTransf;
    LinearTransform residualTranf;

public:
    TestTransform() : homothety(), dqTransf(), residualTranf() {}
    void fromTo(glm::vec3 a3, glm::vec3 b3, glm::vec3 c3,
                    glm::vec2 a2, glm::vec2 b2, glm::vec2 c2);
    glm::vec3 apply(glm::vec3 point) const;
};

TestTransform mix(const TestTransform& a, const TestTransform& b, float t);