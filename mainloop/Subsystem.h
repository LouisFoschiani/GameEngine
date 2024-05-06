#pragma once

#include "BaseObject.h"
#include "Component.h"

class Subsystem : public BaseObject
{

	double framerate;

public:

	std::vector<Component*> observers;

	double targetFrameRate;
	double accumulatedTime = 0.0;
	int maxIterations = 2;

	Subsystem(double framerate) : framerate(framerate) {
		targetFrameRate = 1.0 / framerate;
	}
	~Subsystem() = default;
	bool Create() { return true; }
	void Destroy() {}
	bool Initialize() { return true; }
	void DeInitialize() {}
	void Update(float deltaTime);
	void FixedUpdate(float deltaTime);
	void RegisterComponent(Component* component);
	void UnregisterComponent(Component* component);

};

