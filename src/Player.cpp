#include "./include/Player.h"

namespace sprouts {
	Player::Player(Vector2 pos, float vel, const CharacterConfig& cfg) : _pos(pos), _vel(vel){
		_texture = cfg.texture;
		_tint = cfg.tint.value_or(WHITE);
		_currentDirection = IDLE;
		_currentFrame = 0;
		_stamina = cfg.stamina.value_or(100);
		_heartsStock = cfg.heartsStock.value_or(0);
		_fruitStock = cfg.fruitStock.value_or(0);
	}
	Player::~Player(){
		cleanup();
	}
	void Player::cleanup(){
		_id = "";
		_texture.reset();
		_currentTarget = nullptr;
	}
	void Player::SetID(std::string id){
		_id = id;
	}
	const std::string& Player::GetID() const{
		return _id;
	}
	/*
	Character* Player::LockTarget(Character* c){
		if (c) _currentTarget = c;
	}
	*/
	void Player::LockTarget(Character* c){
		if (c) _currentTarget = c;
	}
	void Player::HealAnimal(){
		if (!_currentTarget) return;
		if (_fruitStock == 0) {
			// call no fruit animation
			_currentTarget = nullptr;
			return;
		}

		Animal* target{static_cast<Animal*>(_currentTarget)};
		ANIMAL_STATE targetState{target->GetState()};
		if (targetState == HAPPY || targetState == LOVING) return;
		unsigned char healPoints{static_cast<unsigned char>(targetState)};
		healPoints = 2 - healPoints;
		healPoints = std::min(healPoints, _fruitStock);
		target->Heal(healPoints);
		_fruitStock -= healPoints;

		_currentTarget = nullptr;
	}
	void Player::PetAnimal(){
		if (!_currentTarget) return;
		if (_heartsStock == 0){
			// call no heart animation
			_currentTarget = nullptr;
			return;
		}

		Animal* target{static_cast<Animal*>(_currentTarget)};
		ANIMAL_STATE targetState{target->GetState()};
		if (targetState != HAPPY && targetState != LOVING){
			// call must heal first animation
			_currentTarget = nullptr;
			return;
		}

		target->ReceivePet();
		_heartsStock--;
		_currentTarget = nullptr;
	}
	void Player::Eat(){
		if (_fruitStock == 0){
			// call out of stock animation
			return;
		}
		// call eat animation
		_stamina = std::min(_stamina + 10, 100);
		_fruitStock--;
	}
	void Player::Move(DIRECTION dir, float dt){
		// TODO implement
	}
}
