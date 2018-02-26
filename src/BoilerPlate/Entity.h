#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_ 
#include "Vector_2.hpp"
#include "SDLEvent.hpp"
#include "MathUtilities.h"
#include "ColorPalette.h"

class  Entity
{
	private:

		/*MEMBERS*/
		int screenWidth;
		int screenHeight;
		Vector2 position;
		float mass;
		float orientation;
		Vector2 velocity;
		std::vector<Vector2> points;
		bool debuggingOn;
		float radius;

	public:

		/*CTOR*/
		Entity();
		~Entity();

		/*PUBLIC MEMBERS*/
	

		/*FUNCTIONS*/
		virtual void Update(float); 
		virtual void Render() = 0;
		void updateFrame(int, int);
		void Warping();
		void addOrientation(float orientationToAdd);
		void setOrientation(float orientationToAdd);
		void addPosition(Vector2);
		void setPosition(Vector2);
		Vector2 getPosition();
		Vector2 getVelocity();
		void addVelocity(Vector2);
		void setVelocity(Vector2);
		void setPoints(std::vector<Vector2>);
		std::vector<Vector2> getPoints();
		float getOrientation();
		float getMass();
		void setMass(float);
		void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius);
		void setRadius(float);
		float getRadius();
		bool getDebuggingOn();
		void setDebuggingOn(bool);

	

};

#endif // !_ENTITY_H_
