#pragma once

#include <string>

namespace api
{
    namespace entities
    {
        class GameObject;
        
        class Component
        {
        private:
            std::string name;

        protected:
            Component(const std::string& name);

        public:
            GameObject* gameObject;

            virtual void init() {}
            virtual void update() {}

            std::string getName() const;
            void setName(const std::string& name);
        };
    }
}