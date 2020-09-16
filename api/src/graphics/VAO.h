#pragma once

#include <vector>

#include "VBO.h"

namespace api
{
    namespace graphics
    {
        class VAO
        {
        private:
            unsigned int id;
            unsigned int vertexCount;
            std::vector<VBO*> vbos;
            std::vector<unsigned int> attributes;

        public:
            VAO();
            ~VAO();

            void createAttribute(const unsigned int& attribute, const std::vector<float>& data, const unsigned int& size);
            void createAttribute(const unsigned int& attribute, const std::vector<int>& data, const unsigned int& size);
            void createIndexBuffer(const std::vector<int>& data);
            void createIndexBuffer(const std::vector<unsigned int>& data);

            void bind() const;
            void unbind() const;

            unsigned int getID() const;
            unsigned int getVertexCount() const;
        };
    }
}

