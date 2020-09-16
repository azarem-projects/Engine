#include "DefaultRenderer.h"

#include <GL/glew.h>

#include <math/Linear.h>

#include "scenes/SceneManager.h"
#include "scenes/Scene.h"

// api::rendering::DefaultRenderer::DefaultRenderer()
// {
//     shader = shaders::DefaultShader();

//     math::Matrix4x4 projection = math::getProjection();

//     shader.bind();
//     shader["u_Projection"] = projection;
//     shader.unbind();
// }

void api::rendering::DefaultRenderer::init()
{
    rendering::DefaultRenderer& instance = getInstance();

    instance.shader = shaders::DefaultShader();

    math::Matrix4x4 projection = math::getProjection();

    instance.shader.bind();
    instance.shader["u_Projection"] = projection;
    instance.shader.unbind();
}

void api::rendering::DefaultRenderer::render()
{
    rendering::DefaultRenderer& instance = getInstance();

    instance.shader.bind();

    for (api::entities::GameObject* gameObject : api::scenes::SceneManager::getScene()->getGameObjects())
    {
        // gameObject->material->getTexture()->bind();
        
        api::math::Matrix4x4& transform = *gameObject->transform->globalTransform;
        instance.shader["u_Model"] = transform;

        gameObject->mesh->getVAO()->bind();
        glDrawElements(GL_TRIANGLES, gameObject->mesh->getVAO()->getVertexCount(), GL_UNSIGNED_INT, 0);
        gameObject->mesh->getVAO()->unbind();
    }

    instance.shader.unbind();
}
