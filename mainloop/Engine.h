#pragma once

#include "BaseObject.h"
#include "Subsystem.h"

// "forward declaration" d'une structure qui elle meme reference des classes
	// qui ne sont pas encore definies (fonctionne ici car il s'agit de pointeurs,
	// seul le typage interesse le compilateur dans ce cas)	
struct EngineContext;

struct Engine : public BaseObject
{

	// simple exemple, ou alors un vector ou une liste simplement chainee (intrusive) de systems
	Subsystem* behaviourEngine;
	Subsystem* physicEngine;


	void ProcessSystems(double elapsedTime);

	// ---

	bool Initialize() final;
	void FreeComponent(Component* component);
	void DeInitialize() final;

	// ce n'est pas une fonction virtuelle !
	void Update(EngineContext& context);

};
