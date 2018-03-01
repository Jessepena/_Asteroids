#pragma once

#include <vector>

class InputManager {


	/*KEYS*/

public:
	
	static void SetKeyDown(char);
	static void SetKeyUp(char);

	static bool IsKeyDown(char);

	static bool IsKeyPressed(char);
	static bool IsKeyReleased(char);

	static void Update();


	InputManager();
	~InputManager();
};

