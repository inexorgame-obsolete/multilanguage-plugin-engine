#pragma once

#include <list>
#include "ExtensionPoint.hpp"

namespace inexor {
namespace engine {

class Component
{
private:
    std::list<ExtensionPoint> extension_points;
};

};
};
