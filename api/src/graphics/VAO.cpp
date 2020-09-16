#include "VAO.h"

#include <GL/glew.h>

namespace api
{
    namespace graphics
    {
        VAO::VAO()
        {
            glGenVertexArrays(1, &id);
            vertexCount = 0;
        }

        VAO::~VAO()
        {

        }

        void VAO::createAttribute(const unsigned int& attribute, const std::vector<float>& data, const unsigned int& size)
        {
            VBO* vbo = new VBO(GL_ARRAY_BUFFER);

            vbo->bind();
            vbo->storeData(data);

            glVertexAttribPointer(attribute, size, GL_FLOAT, GL_FALSE, size * 4, 0);

            vbo->unbind();

            vbos.push_back(vbo);

            attributes.push_back(attribute);
        }

        void VAO::createAttribute(const unsigned int& attribute, const std::vector<int>& data, const unsigned int& size)
        {
            VBO* vbo = new VBO(GL_ARRAY_BUFFER);

            vbo->bind();
            vbo->storeData(data);

            glVertexAttribIPointer(attribute, size, GL_INT, size * 4, 0);

            vbo->unbind();

            vbos.push_back(vbo);

            attributes.push_back(attribute);
        }

        void VAO::createIndexBuffer(const std::vector<int>& data)
        {
            VBO* vbo = new VBO(GL_ELEMENT_ARRAY_BUFFER);

            vbo->bind();
            vbo->storeData(data);

            vertexCount = data.size();

            vbos.push_back(vbo);
        }

        void VAO::createIndexBuffer(const std::vector<unsigned int>& data)
        {
            VBO* vbo = new VBO(GL_ELEMENT_ARRAY_BUFFER);

            vbo->bind();
            vbo->storeData(data);

            vertexCount = data.size();

            vbos.push_back(vbo);
        }

        void VAO::bind() const
        {
            glBindVertexArray(id);

            for (int i = 0; i < attributes.size(); i++)
            {
                glEnableVertexAttribArray(attributes[i]);
            }
        }

        void VAO::unbind() const
        {
            glBindVertexArray(0);

            for (int i = 0; i < attributes.size(); i++)
            {
                glDisableVertexAttribArray(attributes[i]);
            }
        }

        unsigned int VAO::getID() const
        {
            return id;
        }

        unsigned int VAO::getVertexCount() const
        {
            return vertexCount;
        }
    }
}
