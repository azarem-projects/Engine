#include "SceneManager.h"

void api::scenes::SceneManager::add(api::scenes::Scene* scene)
{
    SceneManager& instance = getInstance();
    
    instance.scenes.emplace_back(scene);
}

void api::scenes::SceneManager::setScene(int scene)
{
    SceneManager& instance = getInstance();

    instance.currentScene = instance.scenes[scene];

    init();
}

api::scenes::Scene* api::scenes::SceneManager::getScene()
{
    SceneManager& instance = getInstance();

    return instance.currentScene;
}

void api::scenes::SceneManager::init()
{
    SceneManager& instance = getInstance();

    instance.currentScene->init();
}

void api::scenes::SceneManager::update()
{
    SceneManager& instance = getInstance();

    instance.currentScene->update();    
}
