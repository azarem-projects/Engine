#pragma once

#include "App.h"

extern api::core::App* api::core::createApp();

int main()
{
    api::core::App* app = api::core::createApp();

    app->run();

    return 0;
}
