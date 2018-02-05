#ifndef MATHUTILITIES_H_INCLUDED
#define MATHUTILITIES_H_INCLUDED
#include "math.h"
#include "stdarg.h"
#include "MathUtilities.cpp"

struct MathUtilities
{
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
	int angleConvert(int i, int x);
	int angularDistance(int x, int x2);
	template <class T>
    T clamp(T x, T Min, T Max);
	bool isPowerOfTwo(int x);
	int floatInterpolate(float x, int Min, int Max);

};

#endif // MATHUTILITIES_H_INCLUDED
