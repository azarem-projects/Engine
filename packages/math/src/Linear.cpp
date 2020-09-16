#include "Linear.h"

#include <glm/gtc/matrix_transform.hpp>

api::math::Matrix4x4 api::math::getProjection()
{
    return glm::perspective(glm::radians(70.0f), 16.0f / 9.0f, 0.1f, 1000.0f);
}

void api::math::getModelMatrix(Matrix4x4* out, Vector3& position, Vector3& rotation, Vector3& scale)
{
    *out = glm::identity<glm::mat4x4>();
    *out = glm::translate(*out, position);
    *out = glm::rotate(*out, glm::radians(rotation.z), glm::vec3(0, 0, 1));
    *out = glm::rotate(*out, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    *out = glm::rotate(*out, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    *out = glm::scale(*out, scale);
}
