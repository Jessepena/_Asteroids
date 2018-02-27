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
		int m_screenWidth;
		int m_screenHeight;
		Vector2 m_position;
		float m_mass;
		float m_orientation;
		Vector2 m_velocity;
		std::vector<Vector2> m_points;
		bool m_debuggingOn;
		float m_radius;

	public:

		/*CTOR*/
		Entity();
		~Entity();

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
		int getScreenWidth();
		int getScreenHeight();

};

#endif // !_ENTITY_H_
