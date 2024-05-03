
#include "InfraStructure.h"

namespace ESGI
{
	struct GameObject : public InfraStructure
	{
		bool Initialize() final;

		void DeInitialize() final;

		// ce n'est pas une fonction virtuelle !
		void Update();

	};
}