#pragma once

#include "Component.h"
namespace ESGI
{
	class TransformComponent : public Component
	{

	private:
		float posX;
		float posY;
		float posZ;

	public:

		TransformComponent(const float x, const float y, const float z) : posX(x), posY(y), posZ(z) {
		}

		float GetX() const;
		float GetY() const;
		float GetZ() const;

		void MoveX(const float x);
		void MoveY(const float y);
		void MoveZ(const float z);
		void Move(const float x, const float y, const float z);

		std::string ToJson() const;

	};
}
