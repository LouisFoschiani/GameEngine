#include "TransformComponent.h"
#include "nlohmann/json.hpp"

float ESGI::TransformComponent::GetX() const
{
	return posX;
}

float ESGI::TransformComponent::GetY() const
{
	return posY;
}


float ESGI::TransformComponent::GetZ() const
{
	return posZ;
}

void ESGI::TransformComponent::MoveX(const float x)
{
	posX += x;
}

void ESGI::TransformComponent::MoveY(const float y)
{
	posY += y;
}

void ESGI::TransformComponent::MoveZ(const float z)
{
	posZ += z;
}

void ESGI::TransformComponent::Move(const float x, const float y, const float z)
{
	MoveX(x);
	MoveY(y);
	MoveZ(z);

}

void ESGI::TransformComponent::Debug()
{
	std::cout << "X = " << posX << " Y = " << posY << " Z = " << posZ << std::endl;

}

std::string ESGI::TransformComponent::ToJson() const {
	nlohmann::json j;
	j["type"] = "TransformComponent";
	j["position"] = {
		{"x", posX},
		{"y", posY},
		{"z", posZ}
	};
	return j.dump();
}