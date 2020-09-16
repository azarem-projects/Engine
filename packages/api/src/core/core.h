#pragma once

#include "architecture/macros.h"

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
