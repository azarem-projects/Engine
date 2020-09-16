#pragma once

#include <layers/LayerStack.h>
#include <layers/Layer.h>
#include <scenes/SceneStack.h>

#include <string>
#include <vector>

#include <shaders/DefaultShader.h>
#include <graphics/VAO.h>
#include <graphics/Texture.h>

#include <components/Mesh.h>

#include <rendering/DefaultRenderer.h>

namespace engine
{
    class Graphics : public api::layers::Layer
    {
    private:
        api::shaders::DefaultShader shader;
        
        std::vector<api::entities::GameObject*> gameObjects;
        std::vector<api::entities::Component*> components;


    protected:
        virtual void init() override;
        virtual void update() override;

        virtual api::scenes::SceneStack* createSceneStack() override;
    };
}