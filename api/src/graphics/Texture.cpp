#include "Texture.h"

#include <GL/glew.h>
#include <stb_image/stb_image.h>

#include <iostream>

namespace api
{
    namespace graphics
    {        
        Texture::Texture(const std::string& path)
        {
            int width, height, nrChannels;

            glGenTextures(1, &id);
            glBindTexture(GL_TEXTURE_2D, id);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            const bool& png = path.find(".png") != std::string::npos;

            unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, png ? STBI_rgb_alpha : 0);

            glTexImage2D(GL_TEXTURE_2D, 0, png ? GL_RGBA : GL_RGB, width, height, 0, png ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, -1);

            stbi_image_free(data);
        }

        void Texture::bind() const
        {
            glBindTexture(GL_TEXTURE_2D, id);
        }

        void Texture::unbind()
        {
            glBindTexture(GL_TEXTURE_2D, 0);
        }

        unsigned int Texture::getID() const
        {
            return id;
        }
    }
}