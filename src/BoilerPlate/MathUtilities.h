#ifndef MATHUTILITIES_H_INCLUDED
#define MATHUTILITIES_H_INCLUDED
#include <math.h>
#include <cmath>
#include <cstdlib>
#include "stdarg.h"
#include <vector>
#include <time.h> 
#include <stdlib.h> 
// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#define M_PI 3.14159265358979323846

class MathUtilities
{
public:
	int floatRoundToInt(float x);
	int floatRoundToEvenInt(float x);
    template <class T>
    T GetMax (T a, T b);
    template <class T>
    T GetMax (T a, T b, T c);
    template <class T>
    T GetMax (T a, T b, T c, T d);
    template <class T>
    T GetMin (T a, T b);
    template <class T>
    T GetMin (T a, T b, T c);
    template <class T>
    T GetMin(T a, T b, T c, T d);
	
	float degreesToRadians(float angle);
	float radiansToDegrees(float angle);
	int angularDistance(int x, int x2);
	template <class T>
    T clamp(T x, T Min, T Max);
	bool isPowerOfTwo(int x);
	int floatInterpolate(float x, int Min, int Max);
	float randInRange(int, int);
	float calculateDistance(float, float, float, float);

};


#endif // MATHUTILITIES_H_INCLUDED
