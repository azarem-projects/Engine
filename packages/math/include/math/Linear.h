#pragma once

#include <glm/glm.hpp>

namespace api
{
    namespace math
    {
        typedef glm::mat4x4 Matrix4x4;
        typedef glm::vec3   Vector3;
        typedef glm::vec4   Vector4;
        typedef glm::quat   Quaternion;

        Matrix4x4 getProjection();

        void getModelMatrix(
            Matrix4x4* out,
            Vector3& position,
            Vector3& rotation,
            Vector3& scale
        );
    }
}