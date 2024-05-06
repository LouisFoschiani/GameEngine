
#include "Input.h"

// pour quitter la boucle : a ne pas utiliser dans une vraie application
#include <conio.h>

#include <iostream>


	bool Input::Initialize() 
	{
#if defined(_DEBUG)
		m_DebugName = "Input";
#endif
		std::cout << "[Input] initialized\n";
		return true;
	}

	void Input::DeInitialize()
	{
		std::cout << "[Input] deinitialized\n";
	}

	// ce n'est pas une fonction virtuelle !
	void Input::Update()
	{

		if (_kbhit())
		{

			int ch = _getch();

			QuitButtonPressed = GetQuitButtonState(ch);
			AddSceneButtonPressed = GetAddSceneButtonState(ch);
			AddGameObjectButtonPressed = GetAddGameObjectButtonState(ch);
			LoadSceneButtonPressed = GetLoadSceneButtonState(ch);
		}
		else {
			QuitButtonPressed = false;
			AddSceneButtonPressed = false;
			AddGameObjectButtonPressed = false;
			LoadSceneButtonPressed = false;
		}


		
		std::cout << "[Input] update\n";
	}


	bool Input::GetQuitButtonState(const int ch)
	{
		return ch == 27; // ESC
	}

	bool Input::GetAddSceneButtonState(const int ch)
	{
		return ch == 115; // s stands for Scene
	}

	bool Input::GetAddGameObjectButtonState(const int ch)
	{
		return ch == 103; // g  stands for GameObject
	}

	bool Input::GetLoadSceneButtonState(const int ch)
	{
		return ch == 108; // l  stands for load
	}
