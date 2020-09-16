#pragma once

#include <vector>

#include "entities/GameObject.h"
#include "entities/Component.h"

namespace api
{
    namespace scenes
    {
        class Scene
        {
        private:
            std::vector<entities::GameObject*>* gameObjects;
            std::vector<entities::Component*>* components;

        public:
            Scene();

            void add(entities::GameObject* gameObject);

            std::vector<entities::GameObject*>& getGameObjects() const;
            std::vector<entities::Component*>& getComponents() const;

            void init();
            void update();

        };
    }
}
