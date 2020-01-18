#ifndef MY3DLIB_H
#define MY3DLIB_H

#include <stdio.h>
#include <math.h>
#include <string.h>


#define PI (3.14159265358979323846)
#define 2PI (2.0*PI)
#define PI_DIV_180 (0.017453292519943296)
#define PI_DIV_180_INV (57.2957795130823229)

#define degreeToRad(x) ((x)*PI_DIV_180)
#define radToDegree(x) ((x)*PI_DIV_180_INV)

/*--------------- Data Type ----------------*/

/*-- Matrixs --*/
typedef float matrix22f[4];
typedef int matrix22i[4];
typedef double matrix22d[4];

typedef float matrix33f[9];
typedef int matrix33i[9];
typedef double matrix33d[9];

typedef float matrix44f[16];
typedef int matrix44i[16];
typedef double matrix44d[16];

/*-- Vectors --*/
typedef float vec4f[4];
typedef float vec3f[3];
typedef float vec2f[2];

typedef int vec4i[4];
typedef int vec3i[3];
typedef int vec2i[2];

typedef double vec4d[4];
typedef double vec3d[3];
typedef double vec2d[2];


/*--------- Operations functions -----------*/
void loadIdentity(matrix44f m);

void rotation4f(matrix44f m, float angulo, float x, float y, float z);
void scale4f(matrix44f m, vec3f vec);
void translate4f(matrix44f m, vec3f vec);
void multi4f(matrix44f m, matrix44f a, matrix44f b);
void vecCrossProduct4f(float m[3], float u[3], float v[3]);
void vecSize4f(float vetor[3], float *tam);
void vecNormalize3f(float vetor[3]);



#endif
