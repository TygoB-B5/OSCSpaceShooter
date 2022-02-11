#pragma once

#include "ofMain.h"
#include "Core/Input/OscController.h"
#include "Core/Input/DebugController.h"

#define ENABLE_DEBUG_CONTROLLER 1

namespace CarGame
{
	class Game
	{
	public:
		void Setup();
		void Update();
		void Draw();

		void KeyPressed(char key);
		void KeyReleased(char key);
		void MouseMoved(int x, int y);
		void MouseDragged(int x, int y, int button);
		void MousePressed(int x, int y, int button);
		void MouseReleased(int x, int y, int button);
		void MouseEntered(int x, int y);

	private:
		std::shared_ptr<Input::Controller> m_Controller;
	};
}