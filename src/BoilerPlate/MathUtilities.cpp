#include "MathUtilities.h"
#define M_PI 3.14159265358979323846

template <class T>

T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return result;
}

template <class T>
T GetMax (T a, T b, T c) {
  T result = a;
  if(b>result)
    result = b;
  else if(c>result)
    result = c;
  return result;
}
template <class T>
T GetMax (T a, T b, T c, T d) {
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
T GetMin (T a, T b) {
  T result;
  result = (a<b)? a : b;
  return result;
}
template <class T>
T GetMin (T a, T b, T c) {
  T result = a;
  if(b < result)
    result = b;
  else if(c < result)
    result = c;
  return result;
}
template <class T>
T GetMin(T a, T b, T c, T d) {
  T result = a;
  if(b < result)
    result = b;
  else if(c < result)
    result = c;
  else if(d < result)
    result = d;
  return result;
}

int floatRoundToInt(float x)
{
	int i = roundf(x);
	return i;
}

int floatRoundToEvenInt(float x)
{
    int i = x;
    if(i % 2 != 0)
        i++;

    return i;
}

int angleConvert(int i, int x)
{
    int result = -1;
    if(i==1)
    {
        result = (x*M_PI)/180;
    }
    else if(i==2)
    {
        result = (x*180)/M_PI;
    }
    return result;
}

int angularDistance(int x, int x2)
{
    int result = x2-x;
    if(result < 0)
        result*=-1;
    return result;
}

template <class T>
 T clamp(T x, T Min, T Max)
 {
     if(x < Min)
        x = Min;
     else if(x > Max)
        x = Max;

     return x;
 }

 bool isPowerOfTwo(int x)
 {
     bool value = false;
     for(int i=2;i<=x;i*=2)
     {
         if(i==x)
            value = true;
     }
     return value;
 }

 int floatInterpolate(float x, int Min, int Max)
 {
     int range = Max - Min, result = -1;

     if(x >= 0 && x <= 1)
     {
        result = range * x;
        result += Min;
     }

     return result;
 }
