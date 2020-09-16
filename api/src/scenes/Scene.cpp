#include "Scene.h"

api::scenes::Scene::Scene()
{
    gameObjects = new std::vector<api::entities::GameObject*>();
    components = new std::vector<api::entities::Component*>();
}

void api::scenes::Scene::add(api::entities::GameObject* gameObject)
{
    gameObjects->emplace_back(gameObject);

    for (api::entities::Component* component : gameObject->getComponents())
    {
        components->emplace_back(component);
    }
}

std::vector<api::entities::GameObject*>& api::scenes::Scene::getGameObjects() const
{
    return *gameObjects;
}

std::vector<api::entities::Component*>& api::scenes::Scene::getComponents() const
{
    return *components;
}

void api::scenes::Scene::init()
{
    for (api::entities::Component* component : *components)
    {
        component->init();
    }
}

void api::scenes::Scene::update()
{
    for (api::entities::Component* component : *components)
    {
        component->update();
    }    
}
