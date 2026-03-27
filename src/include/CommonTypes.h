#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <string>
#include <optional>
#include <memory>
#include <functional>
#include <raylib.h>

namespace sprouts {
	// FLAGS
	enum DIRECTION {
		IDLE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	enum ANIMAL_STATE {
		SICK,
		HEALTHY,
		HAPPY,
		LOVING
	};
	enum PROP_TYPE {
		HEART,
		FRUIT
	};
	// Characters
	class Character {
		public:
			virtual ~Character() = default;
			virtual void Move(DIRECTION, float) = 0;
	};	// Configuration objects
	// structs
	struct Prop {};
	struct Audio {
		std::string src;
		void Play();
		void Pause();
	};
	struct Animation {
		std::optional<std::function<void(float)>> callback;
		float start;
		float end;
		float duration = 0.;
	};	
	// Config types 
	struct Config { public: std::string id = ""; };
	struct GameConfig : public Config {};
	struct CharacterConfig : public Config {
		CharacterConfig(){ id = "character"; };
		std::optional<Texture2D> texture;
		std::optional<Color> tint;
		std::optional<unsigned char> stamina;
		std::optional<unsigned char> heartsStock;
		std::optional<unsigned char> fruitStock;
	};
	struct SceneConfig : public Config {
		SceneConfig(){ id = "scene"; };
		std::vector<Character*> actors;
		std::vector<Prop*> props;
		std::optional<Audio> music;
	};
	
}
#endif
