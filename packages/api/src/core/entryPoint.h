#pragma once

#include "app.h"

int main()
{
    api::core::App* app = api::core::createApp();

    app->run();

    return 0;
}