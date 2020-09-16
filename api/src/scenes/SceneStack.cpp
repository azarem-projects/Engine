#include "SceneStack.h"

namespace api
{
    namespace scenes
    {
        std::vector<Scene*> SceneStack::getScenes() const
        {
            return scenes;
        }

        void SceneStack::pushScene(Scene* scene)
        {
            scenes.emplace_back(scene);
        }
    }
}