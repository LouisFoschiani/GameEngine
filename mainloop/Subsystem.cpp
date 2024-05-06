#include "Subsystem.h"

void Subsystem::Update(float deltaTime)
{
	for (Component* comp : observers) {
		comp->Update();
	}
}

void Subsystem::FixedUpdate(float deltaTime)
{
	for (Component* comp : observers) {
		comp->FixedUpdate();
	}
}

void Subsystem::RegisterComponent(Component* component)
{
	observers.push_back(component);
}

void Subsystem::UnregisterComponent(Component* component)
{
	observers.erase(std::remove(observers.begin(), observers.end(), component), observers.end());
}
