#pragma once

#include <vector>

#include "architecture/Macros.h"

#include "Scene.h"

namespace api
{
    namespace scenes
    {
        class SceneManager
        {
        SINGLETON(SceneManager, [](auto&) {})

        private:
            Scene* currentScene;
            std::vector<Scene*> scenes;

        public:
            static void add(Scene* scene);
            static void setScene(int scene);
            static Scene* getScene();

            static void init();
            static void update();

        };
    }
}