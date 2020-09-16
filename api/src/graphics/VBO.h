#pragma once

#include <GL/glew.h>

#include <vector>

namespace api
{
    namespace graphics
    {
        class VBO
        {
        private:
            unsigned int id;
            unsigned int type;

        public:
            VBO(const unsigned int& type);
            ~VBO();

            void storeData(const std::vector<float>& data) const;
            void storeData(const std::vector<int>& data) const;
            void storeData(const std::vector<unsigned int>& data) const;

            void bind() const;
            void unbind() const;
        };
    }
}
