#pragma once

#include <glm/vec3.hpp>

#include "entities/Component.h"

#include <math/Linear.h>

namespace api
{
    namespace components
    {
        class Transform : public entities::Component
        {
        public:
            math::Vector3 position;
            math::Vector3 rotation;
            math::Vector3 scale;

            math::Vector3 localPosition;
            math::Vector3 localRotation;
            math::Vector3 localScale;

	        math::Matrix4x4* parentTransform;
	        math::Matrix4x4* localTransform;
	        math::Matrix4x4* globalTransform;

            Transform* parent;

            Transform();

            virtual void init() override;
            virtual void update() override;
        };
    }
}
