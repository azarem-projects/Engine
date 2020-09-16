#pragma once

#include "Shader.h"

#include <string>
#include <vector>

namespace api
{
    namespace shaders
    {
        class DefaultShader : public Shader
        {
        private:
        public:
            DefaultShader() : Shader(
                "/home/azarem/Resources/Shaders/Default/vertex.glsl",
                "/home/azarem/Resources/Shaders/Default/fragment.glsl",
                std::vector<std::string> { "u_Projection", "u_View", "u_Model" },
                std::vector<std::string> { "position", "uvs" }
            )
            {
            }
        };
    }
}

