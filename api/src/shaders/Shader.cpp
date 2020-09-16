#include "Shader.h"

#include <files/Importer.h>
#include <assets/Asset.h>
#include <debug/Log.h>

#include <iostream>

namespace api
{
	namespace shaders
	{
		Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, std::vector<std::string> uniformVariables, std::vector<std::string> inputVariables)
		{
 			assets::Asset* vertexShaderAsset = assets::import(vertexShaderPath);
 			assets::Asset* fragmentShaderAsset = assets::import(fragmentShaderPath);

			programID = glCreateProgram();

			vertexShaderID = createShader(vertexShaderAsset->text->content, GL_VERTEX_SHADER);
			fragmentShaderID = createShader(fragmentShaderAsset->text->content, GL_FRAGMENT_SHADER);

			link();

			for (int i = 0; i < uniformVariables.size(); i++)
			{
				createUniform(uniformVariables[i]);
			}

			for (int i = 0; i < inputVariables.size(); i++)
			{
				glBindAttribLocation(programID, i, inputVariables[i].c_str());
			}
		}

		void Shader::link() const
		{
			glLinkProgram(programID);

			if (vertexShaderID != 0)
			{
				glDetachShader(programID, vertexShaderID);
			}

			if (fragmentShaderID != 0)
			{
				glDetachShader(programID, fragmentShaderID);
			}

			glValidateProgram(programID);
		}

		void Shader::createUniform(const std::string& name)
		{
			const int location = glGetUniformLocation(programID, name.c_str());

			locations.insert(std::pair<std::string, int>(name.c_str(), location));
		}

		void Shader::setUniform(const std::string& name, const std::vector<glm::mat4x4>& list) const
		{
			for (unsigned int i = 0; i < list.size(); i++)
			{
				glUniformMatrix4fv(glGetUniformLocation(programID, name.c_str()), list.size(), GL_FALSE, glm::value_ptr(list[0]));
			}
		}

		void Shader::setUniform(const std::string& name, const glm::mat4x4& matrix) const
		{
			glUniformMatrix4fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, &matrix[0][0]);
		}

		void Shader::setUniform(const std::string& name, float* matrix) const
		{
			glUniformMatrix4fv(locations.at(name), 1, GL_FALSE, matrix);
		}

		void Shader::setUniform(const std::string& name, const glm::vec3& vec) const
		{
			glUniform3f(locations.at(name), vec.x, vec.y, vec.z);
		}

		void Shader::setUniform(const std::string& name, float value) const
		{
			glUniform1f(locations.at(name), value);
		}

		void Shader::setUniform(const std::string& name, bool value) const
		{
			glUniform1i(locations.at(name), value ? 1 : 0);
		}

		Shader& Shader::operator[](std::string const& name)
		{
			location = locations.at(name);
			return *this;
		}

		void Shader::operator=(const std::vector<glm::mat4x4>& list) const
		{
			for (unsigned int i = 0; i < list.size(); i++)
			{
				glUniformMatrix4fv(location, list.size(), GL_FALSE, glm::value_ptr(list[0]));
			}
		}

		void Shader::operator=(const api::math::Matrix4x4& matrix) const
		{
			glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
		}

		void Shader::operator=(const glm::vec3& vec) const
		{
			glUniform3f(location, vec.x, vec.y, vec.z);
		}

		void Shader::operator=(float* value) const
		{
			glUniformMatrix4fv(location, 1, GL_FALSE, value);
		}

		void Shader::operator=(float value) const
		{
			glUniform1f(location, value);
		}

		void Shader::operator=(bool value) const
		{
			glUniform1i(location, value ? 1 : 0);
		}

		unsigned int Shader::createShader(const std::string& shaderCode, const unsigned int& shaderType)
		{
			const unsigned int shaderID = glCreateShader(shaderType);

			const char* c_str = shaderCode.c_str();

			glShaderSource(shaderID, 1, &c_str, NULL);
			glCompileShader(shaderID);

			int status;

			glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);

			if (status == GL_FALSE) {
				int length;
				glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> log(length);
				glGetShaderInfoLog(shaderID, length, &length, &log[0]);
				// ENGINE_ERROR("Error occured while compiling a shader: {0}", &log[0]);
				return -1;
			}

			glAttachShader(programID, shaderID);

			return shaderID;
		}

		void Shader::bind() const
		{
			glUseProgram(programID);
		}

		void Shader::unbind() const
		{
			glUseProgram(0);
		}

		void Shader::cleanUp()
		{
			if (programID != 0)
			{
				glDetachShader(programID, vertexShaderID);
				glDetachShader(programID, fragmentShaderID);
				glDeleteShader(vertexShaderID);
				glDeleteShader(fragmentShaderID);
				glDeleteProgram(programID);
			}
		}		
	}
}


