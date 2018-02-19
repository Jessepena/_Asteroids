#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_ 
#include "Vector_2.hpp"
#include "SDLEvent.hpp"
#include "MathUtilities.h"


const int screenWidth = 568;
const int screenHeight = 320;

class  Entity
{
private:
	/*MEMBERS*/
	Vector2 position;
	float mass;
	float orientation;
	Vector2 velocity;
	std::vector<Vector2> points;

public:

	/*CTOR*/
	Entity();
	~Entity();

	/*PUBLIC MEMBERS*/
	

	/*FUNCTIONS*/
	void Update(float);
	virtual void Render() = 0;
	void Warping();
	void addOrientation(float orientationToAdd);
	void addPosition(Vector2);
	void setPosition(Vector2);
	Vector2 getPosition();
	Vector2 getVelocity();
	void setPoints(std::vector<Vector2>);
	std::vector<Vector2> getPoints();
	float getOrientation();
	

};

#endif // !_ENTITY_H_
