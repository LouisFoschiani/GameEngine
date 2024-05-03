
#include "InfraStructure.h"

namespace ESGI
{
	struct GameObject : public InfraStructure
	{
		GameObject();
		~GameObject();
		void Update(float deltaTime);
		
		static int currentIndex;
		static int poolSize;

		static void CreatePool(int size);
		static GameObject* Allocate();
		static void ResetPool();
		static void DestroyPool();


		bool Initialize() final;

		void DeInitialize() final;

		// ce n'est pas une fonction virtuelle !
		void Update();


	};


}