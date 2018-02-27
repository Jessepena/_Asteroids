#include "Bullet.h"

const int MAX_LIFE = 100;

Bullet::Bullet(Vector2 newPosition, float newOrientation) : Entity()
{
	setPosition(newPosition);
	setOrientation(newOrientation);
	std::vector<Vector2> pointsToPush;
	pointsToPush.push_back(Vector2(0.0f*(0.10), 30.0f*(0.10)));
	pointsToPush.push_back(Vector2(15.0f*(0.10), 20.0f*(0.10)));
	pointsToPush.push_back(Vector2(25.0f*(0.10), 10.0f*(0.10)));
	pointsToPush.push_back(Vector2(20.0f*(0.10), 5.0f*(0.10)));
	pointsToPush.push_back(Vector2(25.0f*(0.10), 0.0f*(0.10)));
	pointsToPush.push_back(Vector2(25.0f*(0.10), -10.0f*(0.10)));
	pointsToPush.push_back(Vector2(15.0f*(0.10), -20.0f*(0.10)));
	pointsToPush.push_back(Vector2(0.0f*(0.10), -25.0f*(0.10)));
	pointsToPush.push_back(Vector2(-15.0f*(0.10), -20.0f*(0.10)));
	pointsToPush.push_back(Vector2(-25.0f*(0.10), -10.0f*(0.10)));
	pointsToPush.push_back(Vector2(-20.0f*(0.10), -5.0f*(0.10)));
	pointsToPush.push_back(Vector2(-25.0f*(0.10), 0.0f*(0.10)));
	pointsToPush.push_back(Vector2(-25.0f*(0.10), 10.0f*(0.10)));
	pointsToPush.push_back(Vector2(-15.0f*(0.10), 20.0f*(0.10)));
	setPoints(pointsToPush);
	setRadius(3);
	m_life = 0;
	Move();
}

Bullet::~Bullet()
{

}

bool Bullet::shouldRemove() 
{
	return m_life > MAX_LIFE;
}

void Bullet::Update(float deltaTime)
{
	m_life++;
	Entity::Update(deltaTime);
}

void Bullet::Render()
{
	Vector2 position = getPosition();
	std::vector<Vector2> points = getPoints();

	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.0f);
	
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_LINE_LOOP);
	for (Vector2 i : points)
	{
		glVertex2f(i.x, i.y);
	}
	glEnd();

	if (getDebuggingOn())
		drawHollowCircle(position.x, position.y, getRadius());
}

void Bullet::Move()
{
	MathUtilities mathUtilities;
	float bulletOrientation = getOrientation();
	if (getMass() > 0)
	{
		if (getVelocity().Length() < 3)
		{
			Vector2 velocityToAdd(-((400 / getMass()) * sinf(mathUtilities.degreesToRadians(bulletOrientation))), 400 / getMass() * cosf(mathUtilities.degreesToRadians(bulletOrientation)));
			addVelocity(velocityToAdd);
		}
		else
		{
			Vector2 velocityToAdd(-((150 / getMass()) * sinf(mathUtilities.degreesToRadians(bulletOrientation))), 150 / getMass() * cosf(mathUtilities.degreesToRadians(bulletOrientation)));
			addVelocity(velocityToAdd);
		}
	}
}