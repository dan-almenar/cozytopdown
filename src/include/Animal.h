#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <optional>
#include <algorithm>
#include <raylib.h>

#include "./CommonTypes.h"

namespace sprouts {
	struct CharacterConfig : public Config {
		std::optional<Texture2D> texture;
		std::optional<ANIMAL_STATE> state;
	};
	class Animal : public Character {
		public:
			Animal(Vector2 pos, float vel, CharacterConfig cfg={});
			~Animal() = default;
			// member functions
			void Heal(unsigned char);
			void ReceivePet();
			ANIMAL_STATE GetState() const;
		private:
			std::optional<Texture2D> _texture;
			std::optional<std::string> _id;
			Color _tint;
			Vector2 _anchorPos;
			Vector2 _currentPos;
			float _vel;
			ANIMAL_STATE _currentState;
			DIRECTION _currentDirection;
			DIRECTION _nextDirection;
			unsigned char _currentFrame;
			// member functions
			unsigned char setFrame(float);
			Color setTint();
			DIRECTION setDirection();
			void Move(DIRECTION, float) override;
	};
}

#endif
