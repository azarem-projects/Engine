#include "Transform.h"

#include <glm/vec3.hpp>
#include <glm/gtx/matrix_decompose.hpp>

namespace api
{
    namespace components
    {
        Transform::Transform() : Component("Transform")
        {
            position        = math::Vector3(0);
            rotation        = math::Vector3(0);
            scale           = math::Vector3(1);

            localPosition   = math::Vector3(0);
            localRotation   = math::Vector3(0);
            localScale      = math::Vector3(1);

            parentTransform = new math::Matrix4x4(1);
            localTransform  = new math::Matrix4x4(1);
            globalTransform = new math::Matrix4x4(1);

            parent          = nullptr;            
        }

        void Transform::init()
        {
            
        }

        void Transform::update()
        {
            if (parent)
            {
                math::getModelMatrix(parentTransform, parent->position, parent->rotation, parent->scale);
                math::Vector3 f = localPosition / parent->scale;
                math::getModelMatrix(localTransform, f, localRotation, localScale);

                *globalTransform = (*parentTransform) * (*localTransform);

                math::Quaternion rot;
                math::Vector3 skew;
                math::Vector4 perspective;

                glm::decompose(*globalTransform, scale, rot, position, skew, perspective);

                rotation.x = parent->rotation.x + localRotation.x;
                rotation.y = parent->rotation.y + localRotation.y;
                rotation.z = parent->rotation.z + localRotation.z;
            }
            else
            {
                math::getModelMatrix(globalTransform, position, rotation, scale);
            }            
        }
    }
}
