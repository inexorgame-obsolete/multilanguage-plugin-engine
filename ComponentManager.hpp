#pragma once

#include <list>
#include "Component.hpp"

namespace inexor {
namespace engine {

class ComponentManager {
private:
    std::list<Component> components;
};

};
};
