#include "VBO.h"

namespace api
{
    namespace graphics
    {
        VBO::VBO(const unsigned int& type) {
            glGenBuffers(1, &id);

            this->type = type;
        }

        VBO::~VBO() {

        }

        void VBO::storeData(const std::vector<float>& data) const
        {
            glBufferData(type, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
        }

        void VBO::storeData(const std::vector<int>& data) const
        {
            glBufferData(type, data.size() * sizeof(int), &data[0], GL_STATIC_DRAW);
        }

        void VBO::storeData(const std::vector<unsigned int>& data) const
        {
            glBufferData(type, data.size() * sizeof(unsigned int), &data[0], GL_STATIC_DRAW);
        }

        void VBO::bind() const
        {
            glBindBuffer(type, id);
        }

        void VBO::unbind() const
        {
            glBindBuffer(type, 0);
        }
    }
}
