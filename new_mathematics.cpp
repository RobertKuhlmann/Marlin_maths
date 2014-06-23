/*
  new_mathematics.cpp implements replacements for some trigonometric functions
  with much better performance 
  
  sin,  cos,  tan, atan2  and sqrt 
  can be replaced with
  fsin,  fcos, ftan, fatan2 and fsqrt.
  But be aware of fsin, fcos and ftan use degree, not radiant parameters!

  Integration into Marlin, transformation to ATmega and math_tables by Robert Kuhlmann.

  June, 2014, RobertKuhlmann, Germany
*/

/*
  Useful stuff

  radians = (degrees * 71) / 4068

  degrees = (radians * 4068) / 71

  With floating point this is more accurate than using the "original" values
*/

#include "new_mathematics.h"
#include "Arduino.h"
#include "math_tables.h"

float rad2deg(float rad)
{
  return (rad*4068)/71;
}

float deg2rad(float deg)
{
  return (deg*71)/4068;
}

//normalize parameter to positive 0-360 degree value range
float get_ndeg(float deg)
{
  if ((deg > 360) || (deg < 0))
  {
    float ndeg = abs(deg);
    if (ndeg > 360)
    {
      int mod = (int)deg % 360;
      ndeg = mod + (ndeg-mod);
    }
    if (deg < 0) {ndeg = -ndeg + 360;}
    return ndeg;
  }
  else {return deg;}
}//float get_ndeg(float deg)

float fsin(float deg)
{
  float ndeg = get_ndeg(deg);
  float sign = 1;
  union {float flt; unsigned long lng;} cvt;
  if (ndeg > 270) {cvt.lng = pgm_read_dword(&SIN_TABLE[900-(int)((ndeg-270)*10)]); sign = -1;}
  else {if (ndeg > 180) {cvt.lng = pgm_read_dword(&SIN_TABLE[(int)((ndeg-180)*10)]); sign = -1;}
  else {if (ndeg > 90) {cvt.lng = pgm_read_dword(&SIN_TABLE[900-(int)((ndeg-90)*10)]);}
  else {cvt.lng = pgm_read_dword(&SIN_TABLE[(int)(ndeg*10)]);}}}
  return cvt.flt*sign;
} //float fsin(float deg)

float fcos(float deg)
{
  float ndeg = get_ndeg(deg);
  float sign = 1;
  union {float flt; unsigned long lng;} cvt;
  if (ndeg > 270) {cvt.lng = pgm_read_dword(&SIN_TABLE[(int)((ndeg-270)*10)]);}
  else {if (ndeg > 180) {cvt.lng = pgm_read_dword(&SIN_TABLE[900-(int)((ndeg-180)*10)]); sign = -1;}
  else {if (ndeg > 90) {cvt.lng = pgm_read_dword(&SIN_TABLE[(int)((ndeg-90)*10)]);sign = -1;}
  else {cvt.lng = pgm_read_dword(&SIN_TABLE[900-(int)(ndeg*10)]);}}}
  return cvt.flt*sign;
} //float fcos(float deg)


float ftan(float deg)
{
  float ndeg = get_ndeg(deg);
  float sign = 1;
  union {float flt; unsigned long lng;} cvt;
  if (ndeg > 270) {cvt.lng = pgm_read_dword(&TAN_TABLE[900-(int)((ndeg-270)*10)]); sign = -1;}
  else {if (ndeg > 180) {cvt.lng = pgm_read_dword(&TAN_TABLE[(int)((ndeg-180)*10)]); sign = -1;}
  else {if (ndeg > 90) {cvt.lng = pgm_read_dword(&TAN_TABLE[900-(int)((ndeg-90)*10)]);}
  else {cvt.lng = pgm_read_dword(&TAN_TABLE[(int)(ndeg*10)]);}}}
  return cvt.flt*sign;
}//float ftan(float deg)

/*
float facos(float num)
{
//2500-(A2/2)*5000
  union {float flt; unsigned long lng;} cvt;
  cvt.lng = pgm_read_dword(&ACOS_TABLE[2500-(int)(num/2)*5000]);
  return cvt.flt;
}//float facos(float num)

float fatan2(float opp, float adj)
{

	float hypt = fsqrt(adj * adj + opp * opp);
	float rad = facos(adj/hypt);

	if(opp < 0)
		rad = -rad;

	return rad;
}//float fatan2(float opp, float adj)

*/

//You get the square root of a float by halving its exponent, which is equivalent
// to a single right-shift of the exponent. 
//The exponent of float is biased (by 127).
//This is not very accurate (5%) but extremely fast
float fsqrt(float x)
{
    unsigned long val_int = *(unsigned long*)&x; /* Same bits, but as an int */
 
    val_int += 127L << 23;
    val_int >>= 1;
    
    return *(float*)&val_int;
}//float fsqrt(float x)

