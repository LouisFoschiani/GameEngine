
#include "GameObject.h"

// pour quitter la boucle : a ne pas utiliser dans une vraie application
#include <conio.h>

#include <iostream>

namespace ESGI {

	bool GameObject::Initialize()
	{
#if defined(_DEBUG)
		m_DebugName = "GameObject";
#endif
		std::cout << "[GameObject] initialized\n";
		return true;
	}

}