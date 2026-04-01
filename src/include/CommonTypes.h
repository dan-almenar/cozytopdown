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
		DOWN,
		UP,
		LEFT,
		RIGHT,
		IDLE,
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
	// Configuration objects
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
}
#endif
