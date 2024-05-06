#pragma once

#include "BaseObject.h"

	struct Input : public BaseObject
	{
		bool QuitButtonPressed = false;
		bool AddSceneButtonPressed = false;
		bool AddGameObjectButtonPressed = false;
		bool LoadSceneButtonPressed = false;

		bool Initialize() final;

		void DeInitialize() final;

		// ce n'est pas une fonction virtuelle !
		void Update();

		bool GetQuitButtonState(const int ch);
		bool GetAddSceneButtonState(const int ch);
		bool GetAddGameObjectButtonState(const int ch);
		bool GetLoadSceneButtonState(const int ch);
	};