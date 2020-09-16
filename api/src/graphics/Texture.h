#pragma once

#include <string>

namespace api
{
    namespace graphics
    {
        class Texture
        {
        private:
            unsigned int id;
        public:
            Texture(const std::string& path);

            unsigned int getID() const;
            void bind() const;
            static void unbind();
        };
    }
}