#include <core/entryPoint.h>
#include <core/app.h>

class Sandbox : public api::core::App
{

};

api::core::App* api::core::createApp()
{
    return new Sandbox();
}
