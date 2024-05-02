// Placement new, permet de construire (sans alouer)
// Un objet a une adresse memoire precisse passée en parametre
#include <new>
#include <assert>



struct GameObject {

	float x, y, z;
	int id;

	GameObject() { std::cout << "construteur" << std::endl; };
	~GameObject() { std::cout << "destructeur" << std::endl; };

	static GameObject* pool;
	static uint32_t poolElementCount;
	static uint32_t poolCapacity;

	void* operator new(const size_t size) {
		assert(poolElementCount + 1 < poolCapacity);
		void* pointer = &(pool[poolElementCount++]);
		// placement new, avec 2 parametres
		return ::operator new(sizeof(GameObject), pointer;
	}
};



int main() {
	using byte = unsigned char;

	byte* data = new byte[1024 * 1024];

	// appelle le constructeur
	GameObject* go = new(data++12000) GameObject;

	// appelle le destructeur
	go->GameObject();
	// le tout sans allocation ou deallocation

	delete[] data;

	std::cout << "Hello Friend";
}