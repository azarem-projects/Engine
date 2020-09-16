#include "Material.h"

namespace api
{
    namespace components
    {
        Material::Material() : Component("Material")
        {

        }

        graphics::Texture* Material::getTexture() const
        {
            return texture;
        }

        Material* Material::init(const std::string& path)
        {
            // texture = new api::graphics::Texture(path);
        }
    }
}
