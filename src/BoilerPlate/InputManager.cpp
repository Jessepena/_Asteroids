#include "InputManager.hpp"


InputManager::InputManager()
{

}


InputManager::~InputManager()
{
}

bool InputManager::get_w_key()
{
	return w_key;
}

void InputManager::set_w_key(bool new_w_key)
{
	w_key = new_w_key;
}

bool InputManager::get_a_key()
{
	return a_key;
}

void InputManager::set_a_key(bool new_a_key)
{
	a_key = new_a_key;
}

bool InputManager::get_d_key()
{
	return d_key;
}

void InputManager::set_d_key(bool new_d_key)
{
	d_key = new_d_key;
}

bool InputManager::get_y_key()
{
	return y_key;
}

void InputManager::set_y_key(bool new_y_value)
{
	y_key = new_y_value;
}



bool InputManager::get_n_key()
{
	return n_key;
}

void InputManager::set_n_key(bool new_n_key)
{
	n_key = new_n_key;
}

bool InputManager::get_m_key()
{
	return m_key;
}

void InputManager::set_m_key(bool new_m_key)
{
	m_key = new_m_key;
}

bool InputManager::get_up_key()
{
	return up_key;
}

void InputManager::set_up_key(bool new_up_key)
{
	up_key = new_up_key;
}

bool InputManager::get_left_key()
{
	return left_key;
}

void InputManager::set_left_key(bool new_left_key)
{
	left_key = new_left_key;
}

bool InputManager::get_right_key()
{
	return right_key;
}

void InputManager::set_right_key(bool new_right_key)
{
	right_key = new_right_key;
}

