#pragma once
#ifndef _ASTEROID_H_
#define _ASTEROID_H_
#include "Entity.h"

const float asteroidRotation = 1.0f;
const float asteroidSpeed = 1.0f;

class Asteroid : public Entity
{

public:

	struct AsteroidSize
	{
		enum Size
		{
			BIG = 4,
			MEDIUM = 2,
			SMALL = 1,
		};
	};

	/*CTOR*/
	Asteroid();
	Asteroid(AsteroidSize::Size);
	Asteroid(Vector2, AsteroidSize::Size);
	~Asteroid();

	/*PUBLIC MEMBERS*/


	/*FUNCTIONS*/
	void Update(float);
	void Render() override;
	void move();
	AsteroidSize::Size GetSize();

private:
	/*MEMBERS*/
	float angle;
	AsteroidSize::Size size;

};


#endif // !_ASTEROID_H_
