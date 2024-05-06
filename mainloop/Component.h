#pragma once

#include <string>
#include "nlohmann/json.hpp"

class GameObject;

class Component
{

private:
	GameObject* gameObject = nullptr;

public:
	Component() = default;
	~Component() = default;
	virtual std::string GetType() const = 0;
	void Link(GameObject* gameObject);
	virtual std::string ToJson() const {
		return "";
	}
	virtual void Debug(){}
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
};