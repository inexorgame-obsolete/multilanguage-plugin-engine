#pragma once

#include <algorithm>
#include <list>
#include "Component.hpp"

namespace inexor {
namespace engine {

using ComponentList = std::list<Component>;

/**
 * The component manager keeps a pool of active components.
 */
class ComponentManager {
private:
    ComponentList components;
    ComponentList enabled; 

public:
    ComponentManager() {
        components = ComponentList();
        enabled = ComponentList();
    }

    // __contains__ should be implemented using ContainerList::iterator
    // __getitem__ should be implemented using std::get

	/**
	 * Return whether the given component class is enabled.
	 */
	bool is_enabled(Component c) {
		return (std::find(enabled.begin(), enabled.end(), c) != enabled.end());
	}

	/**
	 * Force a component to be enabled.
	 */
	void enable_component(Component c) {
		if (std::find(components.begin(), components.end(), c) != components.end()) {
			if (!is_enabled(c)) enabled.push_back(c); // TODO: Instantiate class if it hasn't been instantiated yet. Thread?
		}
	}

	/**
	 * Force a component to be disabled.
	 */
	void disable_component(Component c) {
		if (std::find(components.begin(), components.end(), c) != components.end()) {
			if (is_enabled(c)) enabled.remove(c); // TODO: Kill the started thread?
		}
	}

	/**
	 * Can be overridden by sub-classes so that special
	 * initialization for components can be provided.
	 */
	virtual void component_activated(Component c);

	/**
	 * Can be overridden by sub-classes to veto the activation of a component.
	 * If this method returns `False`, the component was disabled
	 * explicitly.  If it returns `None`, the component was neither
	 * enabled nor disabled explicitly. In both cases, the component
	 * with the given class will not be available.
	 */
	virtual void is_component_enabled(Component c);
};

};
};
