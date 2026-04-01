#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include <memory>
#include <optional>

#include <raylib.h>

#include "Animal.h"
#include "CommonTypes.h"

namespace sprouts {
	struct SceneConfig : public Config {
		inline static unsigned char sceneNumber = 0;

		SceneConfig();
		SceneConfig(const SceneConfig&);
		~SceneConfig();

		std::vector<Animal*> animals;
		std::vector<Prop*> props;
		std::optional<Audio> music;
	};
	class Scene {
		public:
			// Constructors
			Scene(const SceneConfig& cfg ={});
			~Scene();
			// Function Members
			const std::string& GetID() const;
			void SetID(std::string);
			void PlayAudio();
			void Use();
			void Render(float dt);

		private:
			Scene() = delete;
			void cleanup();
			std::string _id;
			std::vector<Animal*> _animals;
			std::vector<Prop*> _props;
			std::optional<Audio> _music;
			bool isActive = false;
	};

}
#endif
