#include "BehaviourComponent.h"

void BehaviourComponent::Debug()
{
	std::cout << "DEBUG BEHAVIOUR" << std::endl;

}

std::string BehaviourComponent::ToJson() const {
	nlohmann::json j;
	
	return j.dump();
}