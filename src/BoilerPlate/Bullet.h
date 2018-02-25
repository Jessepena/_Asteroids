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
		void Update(float);
		void Render();
		Bullet(Vector2, Vector2, float);
		~Bullet();
};

//que barbaro xd ah ya :v
//ya has tu clase que no se como la tienes xd, pero falta esa vaina 
#endif // ! BULLET_H_INCLUDED

//que haces? xd poniendo ete bullet.h pero me ta dando un error ahi