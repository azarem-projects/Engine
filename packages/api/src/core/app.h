#pragma once

namespace api
{
    namespace core
    {
        class App
        {
        public:
            void run();
        };

        App* createApp();
    }
}