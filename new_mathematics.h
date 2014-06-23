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

#ifndef NEW_MATHEMATICS_H
#define NEW_MATHEMATICS_H

float rad2deg(float rad);
float deg2rad(float deg);
float fsin(float deg); 
float  fcos(float deg);
float ftan(float deg);
//float facos(float num);
//float fatan2(float opp, float adj);
float fsqrt(float x);

#endif //NEW_MATHEMATICS_H
