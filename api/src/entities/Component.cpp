#include "Component.h"

namespace api
{
    namespace entities
    {
        Component::Component(const std::string& name)
        {
            this->name = name;
        }

        std::string Component::getName() const
        {
            return name;
        }

        void Component::setName(const std::string& name)
        {
            this->name = name;
        }
    }
}