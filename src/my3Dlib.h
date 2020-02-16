#ifndef MY3DLIB_H
#define MY3DLIB_H

#include <stdio.h>
#include <math.h>
#include <string.h>


#define PI (3.14159265358979323846)
#define TOW_PI (2.0*PI)
#define PI_DIV_180 (0.017453292519943296)
#define PI_DIV_180_INV (57.2957795130823229)

#define degreeToRad(x) ((x)*PI_DIV_180)
#define radToDegree(x) ((x)*PI_DIV_180_INV)

/*--------------- Data Type ----------------*/

/*-- Matrixs --*/
typedef float lpgM3Dmatrix22f[4];
typedef int lpgM3Dmatrix22i[4];
typedef double lpgM3Dmatrix22d[4];

typedef float lpgM3Dmatrix33f[9];
typedef int lpgM3Dmatrix33i[9];
typedef double lpgM3Dmatrix33d[9];

typedef float lpgM3Dmatrix44f[16];
typedef int lpgM3Dmatrix44i[16];
typedef double lpgM3Dmatrix44d[16];

/*-- Vectors --*/
typedef float lpgM3Dvec4f[4];
typedef float lpgM3Dvec3f[3];
typedef float lpgM3Dvec2f[2];

typedef int lpgM3Dvec4i[4];
typedef int lpgM3Dvec3i[3];
typedef int lpgM3Dvec2i[2];

typedef double lpgM3Dvec4d[4];
typedef double lpgM3Dvec3d[3];
typedef double lpgM3Dvec2d[2];


/*--------- Operations functions -----------*/

/*! @brief Load the identity matrix into your matrix
 *  @param [lpgM3Dmatrix44f] m - The matrix who recive the identity matrix
 *  @return void
 */
void lpgM3DloadIdentity(lpgM3Dmatrix44f m);


/*! @brief Calculate the rotation matrix give a angle in degree and a vector with each coordinate
 *  @param [lpgM3Dmatrix44f] m - The matrix who recive the rotation matrix
 *  @param [float] angulo - The angle in degree for rotation
 *  @param [float] x - The x coordinate of the vector
 *  @param [float] y - The y coordinate of the vector
 *  @param [float] z - The z coordinate of the vector
 *  @return void
 */
void lpgM3Drotationd4f(lpgM3Dmatrix44f m, float angulo, float x, float y, float z);


/*! @brief Calculate the rotation matrix give a angle in radian and a vector with each coordinate
 *  @param [lpgM3Dmatrix44f] m - The matrix who recive the rotation matrix
 *  @param [float] angulo - The angle in radian for rotation
 *  @param [float] x - The x coordinate of the vector
 *  @param [float] y - The y coordinate of the vector
 *  @param [float] z - The z coordinate of the vector
 *  @return void
 */
void lpgM3Drotationr4f(lpgM3Dmatrix44f m, float angulo, float x, float y, float z);


/*! @brief Calculate the rotation matrix give a angle in degree and a vector
 *  @param [lpgM3Dmatrix44f] m - The matrix who recive the rotation matrix
 *  @param [float] angulo - The angle in degree for rotation
 *  @param [lpgM3Dvec3f] vec - The vector
 *  @return void
 */
void lpgM3Drotationd4fv(lpgM3Dmatrix44f m, float angulo, lpgM3Dvec3f vec);

/*! @brief Calculate the rotation matrix give a angle in radian and a vector
 *  @param [lpgM3Dmatrix44f] m - The matrix who recive the rotation matrix
 *  @param [float] angulo - The angle in radian for rotation
 *  @param [lpgM3Dvec3f] vec - The vector
 *  @return void
 */
void lpgM3Drotationr4fv(lpgM3Dmatrix44f m, float angulo, lpgM3Dvec3f vec);

/*! @brief Calculate the scaling matrix give the how much scaling in the axis.
 *  @param [lpgM3Dmatrix44f] m - The matrix who recive the scaling matrix
 *  @param [float] x - How much scaling in the X axis
 *  @param [float] y - How much scaling in the Y axis
 *  @param [float] z - How much scaling in the Z axis
 *  @return void
 */
void lpgM3Dscale4f(lpgM3Dmatrix44f m, float x, float y, float z);

/*! @brief Calculate the scaling matrix give the how much scaling in the axis with one vector.
 *  @param [lpgM3Dmatrix44f] m - The matrix who recive the scaling matrix
 *  @param [lpgM3Dvec3f] vec - How much scaling in the axis
 *  @return void
 */
void lpgM3Dscale4fv(lpgM3Dmatrix44f m, lpgM3Dvec3f vec);
void lpgM3DvecSize4f(float vetor[3], float *tam);


void lpgM3Dtranslate4fv(lpgM3Dmatrix44f m, lpgM3Dvec3f vec);
void lpgM3Dtranslate4f(lpgM3Dmatrix44f m,  float x, float y, float z);
void lpgM3Dmulti4f(lpgM3Dmatrix44f m, lpgM3Dmatrix44f a, lpgM3Dmatrix44f b);
void lpgM3DvecCrossProduct4f(float m[3], float u[3], float v[3]);
void lpgM3DvecNormalize3f(float vetor[3]);

/*! @brief Create the ortho matrix.
 *  @param [lpgM3Dmatrix44f] m - The matrix who recive the ortho matrix
 *  @param [float] left - Specifies the left finla coordenate.
 *  @param [float] right - Specifies the right finla coordenate
 *  @param [float] bottom - Specifies the bottom finla coordenate
 *  @param [float] top - Specifies the top finla coordenate
 *  @param [float] near - Specifies the near finla coordenate
 *  @param [float] far - Specifies the far finla coordenate
 *  @return void
 */
void lpgM3Dorth(lpgM3Dmatrix44f m, float left, float right, float bottom, float top, float near, float far);

/*! @brief Create the perspective matrix.
 *  @param [lpgM3Dmatrix44f] m - The matrix who recive the perspective matrix
 *  @param [float] fov - Specifies the fov in degree.
 *  @param [float] aspect - Specifies the aspect ration of the screen
 *  @param [float] near - Specifies the near finla coordenate
 *  @param [float] far - Specifies the far finla coordenate
 *  @return void
 */
void lpgM3Dperspective(lpgM3Dmatrix44f m, float fov, float aspect, float near, float far);

void lpgM3DaddVector3f(lpgM3Dvec3f res, float aX, float aY, float aZ, float bX, float bY, float bZ);
void lpgM3DaddVector3fi(lpgM3Dvec3f res, lpgM3Dvec3f a, lpgM3Dvec3f b);
void lpgM3DsubtractVector3f(lpgM3Dvec3f res, float aX, float aY, float aZ, float bX, float bY, float bZ);
void lpgM3DsubtractVector3fi(lpgM3Dvec3f res, lpgM3Dvec3f a, lpgM3Dvec3f b);


/*------------ Print functions -------------*/
void lpgM3DprintMatrix44f(lpgM3Dmatrix44f m);
void lpgM3DprintMatrix33f(lpgM3Dmatrix33f m);
void lpgM3DprintMatrix22f(lpgM3Dmatrix22f m);
void lpgM3DprintVec3f(lpgM3Dvec3f v);

void lpgM3DlookAtf(lpgM3Dmatrix44f lookAtm, float posX, float posY, float posZ, float targerX, float targerY, float targerZ, float upX, float upY, float upZ);


#endif // MY3DLIB_H
