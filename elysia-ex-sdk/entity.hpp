// Entity class
// Entity class contains a way to make a structure of data about players.
// Contains typical properties of an entity.
#include <string>
#include <array>

#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity
{
	private:
		std::string name;
		int health;
		std::array<float, 3> position;

	public:
		std::string getName() { return name; }

		int getHealth() {  return health;  }

		std::array<float, 3> getPos() {  return position;  }

		Entity(std::string name, int health, std::array<float, 3> &position) {
			this->name = name;
			this->health = health;
			this->position = position;
		}
};

#endif