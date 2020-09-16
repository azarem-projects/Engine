#pragma once

#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

#include <math/Linear.h>

namespace api
{
    namespace shaders
    {
        class Shader
        {
        protected:
            unsigned int programID;

            Shader(
                const std::string& vertexShaderPath,
                const std::string& fragmentShaderPath,
                std::vector<std::string> uniformVariables,
                std::vector<std::string> inputVariables
            );

        private:
            std::map<std::string, int> locations;
            unsigned int location;

            unsigned int vertexShaderID;
            unsigned int fragmentShaderID;

            void link() const;
            unsigned int createShader(const std::string& shaderCode, const unsigned int& shaderType);

        public:
            void setUniform(const std::string& name, const std::vector<glm::mat4x4>& list) const;
            void setUniform(const std::string& name, const glm::mat4x4& matrix) const;
            void setUniform(const std::string& name, const glm::vec3& vec) const;
            void setUniform(const std::string& name, float* matrix) const;
            void setUniform(const std::string& name, float value) const;
            void setUniform(const std::string& name, bool value) const;

            Shader& operator[] (std::string const& name);

            void operator=(const std::vector<glm::mat4x4>& list) const;
            void operator=(const api::math::Matrix4x4& matrix) const;
            void operator=(const glm::vec3& vec) const;
            void operator=(float* value) const;
            void operator=(float value) const;
            void operator=(bool value) const;

            void createUniform(const std::string& name);

            void bind() const;
            void unbind() const;

            void cleanUp();
        };
    }
}
