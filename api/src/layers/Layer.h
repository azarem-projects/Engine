#pragma once

#include "scenes/SceneStack.h"
#include "scenes/Scene.h"

namespace api
{
    namespace layers
    {
        class Layer
        {
        friend class LayerStack;

        protected:
            virtual void init() = 0;
            virtual void update() = 0;

            virtual scenes::SceneStack* createSceneStack() = 0;
        };
    }
}