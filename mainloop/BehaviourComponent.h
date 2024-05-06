#pragma once

#include "Component.h"
#include <iostream>
#include <string>

class BehaviourComponent : public Component
{

public:

	std::string GetType() const override { return "BehaviourComponent"; }
	void Debug() final;

	void Update() = 0;
	void FixedUpdate() = 0;
	std::string ToJson() const;
};