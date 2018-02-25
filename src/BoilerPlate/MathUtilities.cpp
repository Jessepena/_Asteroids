#include "MathUtilities.h"


template <class T>

T MathUtilities::GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return result;
}

template <class T>
T MathUtilities::GetMax (T a, T b, T c) {
  T result = a;
  if(b>result)
    result = b;
  else if(c>result)
    result = c;
  return result;
}
template <class T>
T MathUtilities::GetMax (T a, T b, T c, T d) {
  T result = a;
  if(b>result)
    result = b;
  else if(c > result)
    result = c;
  else if(d > result)
    result = d;
  return result;
}
template <class T>
T MathUtilities::GetMin (T a, T b) {
  T result;
  result = (a<b)? a : b;
  return result;
}
template <class T>
T MathUtilities::GetMin (T a, T b, T c) {
  T result = a;
  if(b < result)
    result = b;
  else if(c < result)
    result = c;
  return result;
}
template <class T>
T MathUtilities::GetMin(T a, T b, T c, T d) {
  T result = a;
  if(b < result)
    result = b;
  else if(c < result)
    result = c;
  else if(d < result)
    result = d;
  return result;
}

int MathUtilities::floatRoundToInt(float x)
{
	int i = roundf(x);
	return i;
}

int MathUtilities::floatRoundToEvenInt(float x)
{
    int i = x;
    if(i % 2 != 0)
        i++;

    return i;
}


float MathUtilities::degreesToRadians(float angle)
{
	return angle * (M_PI / 180);
}

float MathUtilities::radiansToDegrees(float angle)
{
	return angle * (180 / M_PI);
}


int MathUtilities::angularDistance(int x, int x2)
{
    int result = x2-x;
    if(result < 0)
        result*=-1;
    return result;
}

template <class T>
 T MathUtilities::clamp(T x, T Min, T Max)
 {
     if(x < Min)
        x = Min;
     else if(x > Max)
        x = Max;

     return x;
 }

 bool MathUtilities::isPowerOfTwo(int x)
 {
     bool value = false;
     for(int i=2;i<=x;i*=2)
     {
         if(i==x)
            value = true;
     }
     return value;
 }

 int MathUtilities::floatInterpolate(float x, int Min, int Max)
 {
     int range = Max - Min, result = -1;

     if(x >= 0 && x <= 1)
     {
        result = range * x;
        result += Min;
     }

     return result;
 }

 float MathUtilities::randInRange(int min, int max)
 {
	
	 return rand() % max + min;
 }

 float MathUtilities::calculateDistance(float x1, float y1, float x2, float y2)
 {
	 return fabs(sqrtf(powf((x2 - x1), 2) + powf((y2 - y1), 2)));
 }

