#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Entity.h"


class Bullet : public Entity 
{
	private:
		/*MEMBERS*/
		int m_life;
		//donde es que ta width y height
	public:
		/*FUNCTIONS*/
		void Update(float);
		void Render();
		void Move();
		bool shouldRemove();
		Bullet(Vector2, float);
		~Bullet();
};

#endif // ! BULLET_H_INCLUDED
