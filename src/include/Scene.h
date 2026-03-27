#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include <memory>
#include <optional>

#include <raylib.h>

#include "CommonTypes.h"
namespace sprouts {
	class Scene {
		public:
			// Constructors
			Scene(const SceneConfig& cfg ={});
			~Scene();
			// Function Members
			std::string& GetID() const;
			void SetID(std::string);
			void PlayAudio();
			void Use();
			void Render(float dt);

		private:
			Scene() = delete;
			void cleanup();
			std::string _id;
			std::vector<Character*> _actors;
			std::vector<Prop*> _props;
			std::optional<Audio> _music;
			bool isActive = false;
	};

}
#endif
