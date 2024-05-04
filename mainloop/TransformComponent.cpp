#include "TransformComponent.h"
#include "nlohmann/json.hpp"

	float TransformComponent::GetX() const
	{
		return posX;
	}

	float TransformComponent::GetY() const
	{
		return posY;
	}


	float TransformComponent::GetZ() const
	{
		return posZ;
	}

	void TransformComponent::MoveX(const float x)
	{
		posX += x;
	}

	void TransformComponent::MoveY(const float y)
	{
		posY += y;
	}

	void TransformComponent::MoveZ(const float z)
	{
		posZ += z;
	}

	void TransformComponent::Move(const float x, const float y, const float z)
	{
		MoveX(x);
		MoveY(y);
		MoveZ(z);

	}

	void TransformComponent::Debug()
	{
		std::cout << "X = " << posX << " Y = " << posY << " Z = " << posZ << std::endl;

	}

	std::string TransformComponent::ToJson() const {
		nlohmann::json j;
		j["type"] = "TransformComponent";
		j["position"] = {
			{"x", posX},
			{"y", posY},
			{"z", posZ}
		};
		return j.dump();
	}