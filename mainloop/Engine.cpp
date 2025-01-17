#include "Engine.h"

// par contre lors de la definition de la fonction il faut une implementation complete
#include "EngineContext.h"
#include "Timer.h"

#include <iostream>

	void Engine::ProcessSystems(double elapsedTime)
	{
		Subsystem* systems[2] = {behaviourEngine, physicEngine};


		for (Subsystem* system : systems) {
			system->accumulatedTime += elapsedTime;

			float deltaTime = static_cast<float>(elapsedTime);

			system->Update(deltaTime);

			int loops = system->maxIterations;
			// on sort de la boucle des que l'un des deux tests est faux
			while ((system->accumulatedTime > system->targetFrameRate) && (loops > 0))
			{
				system->accumulatedTime -= system->targetFrameRate;

				// alternativement on pourrait recalculer le deltaTime a chaque tour de boucle
				// et rappeler Update() si loops < system.maxIterations

				system->FixedUpdate(static_cast<float>(system->targetFrameRate));

				--loops;
			}
		}


		
	}

	bool Engine::Initialize()
	{
#if defined(_DEBUG)
		m_DebugName = "Engine";
#endif

		// Les systemes pourraient etre cree de facon data-driven, plugins, ou en dur
		behaviourEngine = new Subsystem(60);
		behaviourEngine->Create();
		behaviourEngine->Initialize();

		physicEngine = new Subsystem(30);
		physicEngine->Create();
		physicEngine->Initialize();

		std::cout << "[Engine] initialized\n";

		return true;
	}

	void Engine::FreeComponent(Component* component)
	{

		if (component->GetType() == "BehaviourComponent") {

			behaviourEngine->UnregisterComponent(component);

		}else if (component->GetType() == "TransformComponent") {

			physicEngine->UnregisterComponent(component);

		}

	}

	void Engine::DeInitialize()
	{
		// libere et detruit les systems
		behaviourEngine->DeInitialize();
		behaviourEngine->Destroy();


		physicEngine->DeInitialize();
		physicEngine->Destroy();

		std::cout << "[Engine] deinitialized\n";
	}

	// ce n'est pas une fonction virtuelle !
	void Engine::Update(EngineContext& context)
	{
		std::cout << "[Engine] update\n";

		double elapsedTime = context.clock.ElapsedTime;

		// tout lag est maximise 100 ms (1/10 de seconde)
		// cela permet d'eviter de faire sauter le moteur en cas de breakpoint ou lag enorme
		// alternativement on peut appliquer une correction en extrapolant a partir du temps ecoule 
		if (elapsedTime > 0.10)
			elapsedTime = 0.10;

		ProcessSystems(elapsedTime);
	}
