#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <vector>
#include <string>
#include <memory>

#include "CommonTypes.h"
#include "Scene.h"

namespace sprouts {
	class Game {
		public:
			// Constructors
			Game(int w, int h, std::string ttl, GameConfig cfg={});
			void SetScene(std::string);
			void Update(float dt);
			void Render();
			Character* GetCharacterAt(Vector2 pos);
			void SetTarget(Character* c); // derives to Player::LockTarget();
			void HandleInput();
		private:
			Scene* _currentScene;
			std::vector<std::unique_ptr<Scene>> _scenes;
			int _width;
			int _height;
			int _title;
	};
}

#endif
