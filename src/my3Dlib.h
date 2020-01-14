#ifndef MY3DLIB_H
#define MY3DLIB_H

#include <stdio.h>
#include <math.h>
#include <string.h>


typedef float matrix44f[16];

void loadIdentity(matrix44f m[16]);

void rotation4f(float m[16], float angulo, float x, float y, float z);
void multi4f(float m[16], float a[16], float b[16]);
void vecCrossProduct4f(float m[3], float u[3], float v[3]);
void vecSize4f(float vetor[3], float *tam);
void vecNormalize3f(float vetor[3]);



#endif
