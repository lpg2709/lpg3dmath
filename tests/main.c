#include <stdio.h>
#include <stdlib.h>

#define LPG3DMATH_H
#include "../lpg3dmath.h"

int main(){

    lpg3dm_matrix44f m = {
         1,  5,  9, 13,
         2,  6, 10, 14,
         3,  7, 11, 15,
         4,  8, 12, 16
    };

    lpg3dm_matrix44f n = {
         2,  2,  2,  2,
         2,  2,  2,  2,
         2,  2,  2,  2,
         2,  2,  2,  2
    };

    // lpg3dm_multi4f(res, m, n);

    // lpg3dm_lookAtf(res, 0, 0, 3, 0, 0, 0, 0, 1, 0);

    // lpg3dm_printMatrix44f(res);

    lpg3dm_vec3f k = { 1,1,1};
    lpg3dm_vecScale(k, 4);
    lpg3dm_printVec3f(k);


    return 0;
}
