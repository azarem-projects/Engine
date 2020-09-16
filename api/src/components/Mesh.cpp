#include "Mesh.h"

#include <assets/Asset.h>
#include <debug/Log.h>

namespace api
{
    namespace components
    {
        Mesh::Mesh() : Component("Mesh")
        {

        }

        Mesh* Mesh::init(const std::string& path)
        {
            vao = new graphics::VAO();

            assets::Asset* asset = assets::import(path);
            assets::ModelAsset* model = asset->model;

            vao->bind();
            vao->createIndexBuffer(model->indices);
            vao->createAttribute(0, model->positions, 3);
            vao->createAttribute(1, model->uvs, 2);
            vao->unbind();

            return this;
        }

        graphics::VAO* Mesh::getVAO() const
        {
            return vao;
        }
    }
}
