#include "GameObject.h"

namespace ESGI {
	void GameObject::AddComponent(Component* component)
	{

		components.push_back(component);
		component->Link(this);

	}

	std::vector<Component*>& GameObject::GetComponents()
	{
		return components;
	}
}


