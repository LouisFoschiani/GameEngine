namespace ESGI
{
	class Component
	{
		Component();
		~Component();

		virtual bool Initialize();

		virtual void DeInitialize();

		virtual void Update();
	};
}