#pragma once

#include <vector>

#include "Scene.h"

namespace api
{
    namespace scenes
    {
        class SceneStack
        {
        private:
            std::vector<Scene*> scenes;

        public:
            std::vector<Scene*> getScenes() const;
            void pushScene(Scene* scene);
        };
    }
}