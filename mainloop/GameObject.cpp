#include "GameObject.h"
#include "Component.h"

	void GameObject::AddComponent(Component* component)
	{

		components.push_back(component);
		component->Link(this);

	}

	std::vector<Component*>& GameObject::GetComponents()
	{
		return components;
	}