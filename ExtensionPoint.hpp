#pragma once

#include <list>
#include "Interface.hpp"

namespace inexor {
namespace engine {

class Component;

/**
 * Marker class for extension points in components.
 */
class ExtensionPoint {
private:
    Interface iface;

public:
    ExtensionPoint(Interface i) {
        iface = i;
	}

	/**
	 * Return a list of components that declare to implement the
	 * extension point interface.
	 */
	std::list<Component*> extensions(Component* c) {
		return std::list<Component*>(); // TODO: Implement via ComponentMeta
	}
};

};
};
