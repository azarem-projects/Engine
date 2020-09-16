#pragma once

#define SINGLETON(name, init)       \
    private:                        \
        name() { init(*this); }     \
    public:                         \
        name(const name&) = delete; \
        static name& getInstance()  \
        {                           \
            static name instance;   \
            return instance;        \
        }
