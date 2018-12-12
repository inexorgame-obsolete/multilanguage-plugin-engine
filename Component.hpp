#pragma once

#include <list>
#include "ExtensionPoint.hpp"

namespace inexor {
namespace engine {

/**
 * Base class for components.	
 * Every component can declare what extension points it provides, as
 * well as what extension points of other components it extends.
 */
class Component
{
private:
    std::list<ExtensionPoint> extension_points;

public:
    /**
     * Can be used in the class definition of `Component`
     * subclasses to declare the extension points that are extended.
     */
    static void implements(std::list<Interface> interfaces) {

    }
};

};
};
