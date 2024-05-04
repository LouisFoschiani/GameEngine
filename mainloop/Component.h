#include "GameObject.h"
namespace ESGI
{
	class Component
	{


	private:
		GameObject* gameObject;

		virtual bool Initialize();

		virtual void DeInitialize();

		virtual void Update();

	public:
		Component();
		~Component();
		void Link(GameObject* gameObject);
	};
}