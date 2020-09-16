#pragma once

#include "architecture/Macros.h"

namespace api
{
    namespace core
    {
        class Core
        {
        SINGLETON(Core, [](auto&) {})

        public:
            static void init();
        };
    }
}
