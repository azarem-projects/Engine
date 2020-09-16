#pragma once

#include <string>

#include "graphics/Texture.h"

#include "entities/Component.h"

namespace api
{
    namespace components
    {
        class Material : public entities::Component
        {
        private:
            graphics::Texture* texture;

        public:
            Material();

            Material* init(const std::string& path);

            graphics::Texture* getTexture() const;
        };
    }
}
