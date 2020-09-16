#pragma once

#include <vector>
#include <string>

#include "Component.h"
#include "components/Transform.h"
#include "components/Material.h"
#include "components/Mesh.h"

#include <debug/Log.h>

namespace api
{
    namespace entities
    {
        class GameObject
        {
        private:
            std::vector<Component*> components;

        public:
            components::Transform* transform;
            components::Material* material;
            components::Mesh* mesh;

            GameObject();

            template <typename T>
            T* addComponent()
            {
                T* instance = new T();
                instance->gameObject = this;
                components.emplace_back((Component*) instance);

                if (instance->getName() == "Transform")
                {
                    transform = (api::components::Transform*) instance;
                }

                if (instance->getName() == "Material")
                {
                    material = (api::components::Material*) instance;
                }

                if (instance->getName() == "Mesh")
                {
                    mesh = (api::components::Mesh*) instance;
                }

                return instance;
            }

            template <typename T>
            T* getComponent() {
                const std::string& fullTypeName = typeid(T).name();
                const std::string& componentName = fullTypeName.substr(fullTypeName.find(" ") + 1, fullTypeName.length());

                for (int i = 0; i < components.size(); i++)
                {
                    if (components[i]->getName() == componentName)
                    {
                        return (T*) components[i];
                    }
                }

                return nullptr;
            }

            std::vector<Component*> getComponents() const;
        };
    }
}
