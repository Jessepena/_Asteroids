#include "InputManager.hpp"//eso no silve
//ya
#include <vector>


static std::vector <bool> m_previousKeys(300);
static std::vector <bool> m_currentKeys(300);

void InputManager::SetKeyDown(char key)
{
	m_currentKeys[key] = true;
}

bool InputManager::IsKeyDown(char key)
{
	return m_currentKeys[key];
}

bool InputManager::IsKeyPressed(char key)
{
	return !m_previousKeys[key] && m_currentKeys[key];
}

bool InputManager::IsKeyReleased(char key)
{
	return m_previousKeys[key] && !m_currentKeys[key];
}

void InputManager::Update()
{
	m_previousKeys = m_currentKeys;

	//for (int i = 'a'; i <= 'z'; i++) printf("%d ", int(m_previousKeys[i]));
	//puts("");

	//for (int i = 'a'; i <= 'z'; i++) printf("%d ", int(m_currentKeys[i]));
	//puts("");
	//puts("");
}


void InputManager::SetKeyUp(char key)
{
	m_currentKeys[key] = false;
}


InputManager::InputManager()
{
	m_previousKeys = m_currentKeys = std::vector <bool>(300);
}


InputManager::~InputManager()
{
}
