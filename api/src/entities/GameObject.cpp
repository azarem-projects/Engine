#include "GameObject.h"

#include "components/Transform.h"
#include "components/Material.h"

namespace api
{
    namespace entities
    {
        GameObject::GameObject()
        {
            addComponent<components::Transform>();
            addComponent<components::Material>();
        }

        std::vector<Component*> GameObject::getComponents() const
        {
            return components;
        }
    }
}
