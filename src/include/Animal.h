#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <optional>
#include <algorithm>
#include <array>
#include <raylib.h>

#include "./CommonTypes.h"

namespace sprouts {
	struct CharacterConfig : public Config {
		CharacterConfig(){ id = "character"; };
		std::optional<Texture2D> texture;
		std::optional<std::array<Color, 4>> tints;
		std::optional<Color> tint;
		std::optional<unsigned char> stamina;
		std::optional<unsigned char> heartsStock;
		std::optional<unsigned char> fruitStock;
		std::optional<ANIMAL_STATE> state;
		std::optional<float> width;
		std::optional<float> height;
		std::optional<float> sideSize;
	};

	class Animal {
		public:
			Animal(Vector2 pos, float vel, const CharacterConfig& cfg={});
			~Animal() = default;
			// member functions
			void Heal(unsigned char);
			void ReceivePet();
			ANIMAL_STATE GetState() const;
			void Move(DIRECTION, float);
			void Render(float);
		private:
			std::optional<Texture2D> _texture;
			std::optional<std::string> _id;
			std::array<Color, 4> _tints;
			Color _currentTint;
			Vector2 _anchorPos;
			Vector2 _currentPos;
			float _vel;
			float _animTimer;
			float _animSpeed;
			float _width;
			float _height;
			ANIMAL_STATE _currentState;
			DIRECTION _currentDirection;
			DIRECTION _nextDirection;
			unsigned char _currentFrame;
			// member functions
			void setFrame(float);
			void setTint();
			DIRECTION setDirection();
			Rectangle getTextureFrame();
	};
}

#endif
