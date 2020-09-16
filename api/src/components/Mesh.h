#pragma once

#include <string>

#include "entities/Component.h"

#include "graphics/VAO.h"

namespace api
{
    namespace components
    {
        class Mesh : public entities::Component
        {
        public:
            Mesh();

            Mesh* init(const std::string& path);

            graphics::VAO* getVAO() const;

        private:
            graphics::VAO* vao;

        };
    }
}
