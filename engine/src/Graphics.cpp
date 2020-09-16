#include "Graphics.h"

#include <glm/glm.hpp>

#include <vector>

#include <debug/Log.h>
#include <assets/Asset.h>

#include <entities/GameObject.h>
#include <components/Mesh.h>

#include <math/Linear.h>

#include <scenes/SceneManager.h>
#include <scenes/Scene.h>

/**
 * {
 *      "name": "World",
 *      "objects": [
 *          {
 *              "components": [
 *                  {
 *                      "name": "Transform",
 *                      "x": 3.14159,
 *                      "y": 2.72,
 *                      "z": 25.93
 *                  },
 *                  {
 *                      "name": "Material",
 *                      "texture": "../Resources/Textures/diffuse.png"
 *                  },
 *                  {
 *                      "name": "Mesh",
 *                      "texture": "../Resources/Models/human.fbx"
 *                  }
 *              ]
 *          },
 *          {
 *              "components": [
 *                  {
 *                      "name": "Transform",
 *                      "x": 2.72,
 *                      "y": 25.93
 *                      "z": 3.14159,
 *                  },
 *                  {
 *                      "name": "Material",
 *                      "texture": "../Resources/Textures/diffuse.png"
 *                  },
 *                  {
 *                      "name": "Mesh",
 *                      "texture": "../Resources/Models/orc.fbx"
 *                  }
 *              ]
 *          }
 *      ]
 * }
 */

#include <iostream>

namespace engine
{
    api::entities::GameObject* gameObject_0;

    void Graphics::init()
    {
        api::rendering::DefaultRenderer::init();

        gameObject_0 = new api::entities::GameObject();
        
        gameObject_0->addComponent<api::components::Mesh>();
        gameObject_0->mesh->init("/home/azarem/Resources/Models/cube.fbx");
        // gameObject_0->material->init("/home/azarem/Resources/Textures/diffuse.png");
        // gameObject_0->transform->position.z -= 15;

        // api::scenes::Scene* world = new api::scenes::Scene();
        // api::scenes::Scene* dungeon = new api::scenes::Scene();

        // world->add(gameObject_0);

        // api::scenes::SceneManager::add(world);
        // api::scenes::SceneManager::add(dungeon);

        // api::scenes::SceneManager::setScene(0);
    }

    void Graphics::update()
    {
        // gameObject_0->transform->rotation.x += 1;
        // gameObject_0->transform->rotation.y += 1;
        // gameObject_0->transform->rotation.z += 1;

        // api::scenes::SceneManager::update();

        // api::rendering::DefaultRenderer::render();
    }

    api::scenes::SceneStack* Graphics::createSceneStack()
    {
        api::scenes::SceneStack* sceneStack = new api::scenes::SceneStack();

        return sceneStack;
    }
}
