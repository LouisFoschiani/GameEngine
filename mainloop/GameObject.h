#pragma once
#include "InfraStructure.h"
#include "Component.h"
#include <vector> 
#include "TransformComponent.h"
#include "BehaviourComponent.h"
#include <iostream>

namespace ESGI
{
	struct GameObject : public InfraStructure
	{

	private:
		std::vector<Component*> components;


		bool Initialize() final;

		void DeInitialize() final;


	public:
		GameObject();
		~GameObject();
		void Update(float deltaTime);
		// ce n'est pas une fonction virtuelle !
		void Update();
		static GameObject* Allocate();
		void AddComponent(Component* component);
		std::vector<Component*>& GetComponents();

	};


}