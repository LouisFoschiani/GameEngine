#pragma once

// #include "GameObject.h"
#include <string>

struct GameObject;

class Component
{

private:
	GameObject* gameObject;
	virtual bool Initialize();

	virtual void DeInitialize();

	virtual void Update();

public:
	Component();
	~Component();
	void Link(GameObject* gameObject);
	virtual std::string ToJson() const;
	virtual void Debug();
};