#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Entity.h"


class Bullet : public Entity 
{
	
	public:
		/*MEMBERS*/
		int m_life;

		/*FUNCTIONS*/
		void Update(float);
		void Render();
		void Move();
		bool shouldRemove();
		Bullet(Vector2, float);
		~Bullet();
};

#endif // ! BULLET_H_INCLUDED
