#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <optional>
#include <memory>
#include <raylib.h>

#include "./CommonTypes.h"
#include "./Animal.h"

namespace sprouts {
	class Player {
		public:
			Player(Vector2 pos, float vel, const CharacterConfig& cfg={});
			~Player();
			void Move(DIRECTION, float);
			void Render(float);
			void LockTarget(Animal*);
			void HealAnimal();
			void PetAnimal();
			void Eat();
			void SetID(std::string);
			const std::string& GetID() const;
		private:
			std::string _id = "player";
			std::optional<Texture2D> _texture;
			Color _tint;
			Vector2 _pos;
			float _vel;
			DIRECTION _currentDirection;
			unsigned char _currentFrame;
			unsigned char _stamina;
			unsigned char _heartsStock;
			unsigned char _fruitStock;
			Animal* _currentTarget = nullptr;
			void cleanup();
	};
}
#endif
