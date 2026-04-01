#include <stdexcept>
#include "./include/Animal.h"

namespace sprouts {
	constexpr unsigned char ANIM_FRAMES{5};
	constexpr float DEFAULT_SIZE{32.};
	constexpr float DEFAULT_SPEED{60.};
	Animal::Animal(Vector2 pos, float vel, const CharacterConfig& cfg) : _anchorPos(pos), _currentPos(pos), _vel(vel){
		if (cfg.texture.has_value()) _texture = cfg.texture.value();
		_currentState = cfg.state.value_or(HEALTHY);
		_currentDirection = IDLE;
		_currentFrame = 0;
		_id = cfg.id;
		_width = cfg.width.value_or(DEFAULT_SIZE);
		_height = cfg.height.value_or(DEFAULT_SIZE);
		_tints = cfg.tints.value_or(std::array<Color, 4>{LIME, WHITE, GOLD, PURPLE});
		setTint();
	}
	void Animal::Heal(unsigned char points){
		if (_currentState == LOVING) return;
		unsigned char maxHealState = static_cast<unsigned char>(HAPPY);
		unsigned char nextState = static_cast<unsigned char>(_currentState) + points;
		_currentState = static_cast<ANIMAL_STATE>(std::min(nextState, maxHealState)); 
		setTint();
		return;
	}
	void Animal::setTint(){
		_currentTint = _tints[static_cast<unsigned char>(_currentState)];
	}
	void Animal::Move(DIRECTION dir, float dt){
		// TODO IMPLEMENT LEASH LOGC
		switch (dir){
			case UP:
				_currentPos.y -= _vel * dt;
			case DOWN:
				_currentPos.y += _vel * dt;
			case LEFT:
				_currentPos.x -= _vel * dt;
			case RIGHT:
				_currentPos.x += _vel * dt;
			default:
				return; // IDLE
		}
	}
	ANIMAL_STATE Animal::GetState() const {
		return _currentState;
	}
	void Animal::setFrame(float dt){
		_animTimer += dt;
		if (_animTimer < _animSpeed) return;
		_animTimer = 0;
		_currentFrame = std::min(static_cast<unsigned char>(_currentFrame + 1), ANIM_FRAMES);
	}
	Rectangle Animal::getTextureFrame(){
		if (!_texture) throw std::logic_error("TEXTURE ERROR: No available texture!");

		unsigned char row{std::min(static_cast<unsigned char>(_currentFrame), ANIM_FRAMES)};
		unsigned char col{static_cast<unsigned char>(_currentDirection)};
		if (_currentDirection == IDLE) col = 0; // use walking down sprites

		return Rectangle{row * _width, col * _height, _width, _height};
	}
}
