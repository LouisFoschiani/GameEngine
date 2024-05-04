#pragma once
#include "InfraStructure.h"
#include "Component.h"
#include <vector> 
#include "TransformComponent.h"
#include "BehaviourComponent.h"
#include <iostream>

namespace ESGI
{
	struct GameObject
	{

	private:
		std::vector<Component*> components;


	public:
		GameObject();
		~GameObject();
		void Update(float deltaTime);
		// ce n'est pas une fonction virtuelle !
		void Update();
		void AddComponent(Component* component);
		std::vector<Component*>& GetComponents();

	};


}