#pragma once
#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

class InputManager
{
	private:

		/*KEYS*/
		bool w_key;
		bool a_key;
		bool d_key;
		bool y_key;
		bool n_key;
		bool m_key;
		bool up_key;
		bool left_key;
		bool right_key;

	public:
	
		bool get_w_key();
		void set_w_key(bool);
		bool get_a_key();
		void set_a_key(bool);
		bool get_d_key();
		void set_d_key(bool);
		bool get_y_key();
		void set_y_key(bool);
		bool get_n_key();
		void set_n_key(bool);
		bool get_m_key();
		void set_m_key(bool);
		bool get_up_key();
		void set_up_key(bool);
		bool get_left_key();
		void set_left_key(bool);
		bool get_right_key();
		void set_right_key(bool);

	InputManager();
	~InputManager();
};

#endif // !_INPUTMANAGER_H_

