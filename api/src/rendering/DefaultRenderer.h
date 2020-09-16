#pragma once

#include <vector>
#include <map>

#include "entities/GameObject.h"
#include "shaders/DefaultShader.h"
#include "components/Mesh.h"

#include "architecture/Macros.h"

namespace api
{
    namespace rendering
    {
        class DefaultRenderer
        {
        SINGLETON(DefaultRenderer, [](auto&) {})

        public:
            static void init();
            static void render();

        private:
            std::vector<entities::GameObject*> renderable;
            shaders::DefaultShader shader;

        };
    }
}