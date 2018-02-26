#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Entity.h"
//esto es un entity...
//tienes que solo pensar en que la bala tiene una velocidad constante
//un angulo y una posicion
//to eso lo tiene space object osea que tienes que simplemente en el constructor anejar eso
//que se lo vas a mandr desde player


//papa, tas ahi?


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
