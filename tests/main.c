#include <stdio.h>
#include <stdlib.h>

#define MY_3DLIB
#include "./src/my3Dlib.h"

int main(){

    lpgM3Dmatrix44f m = {
         1,  5,  9, 13,
         2,  6, 10, 14,
         3,  7, 11, 15,
         4,  8, 12, 16
    };

    lpgM3Dmatrix44f n = {
         2,  2,  2,  2,
         2,  2,  2,  2,
         2,  2,  2,  2,
         2,  2,  2,  2
    };

    // lpgM3Dmulti4f(res, m, n);

    // lpgM3DlookAtf(res, 0, 0, 3, 0, 0, 0, 0, 1, 0);

    // lpgM3DprintMatrix44f(res);

    lpgM3Dvec3f k = { 1,1,1};
    lpgM3DvecScale(k, 4);
    lpgM3DprintVec3f(k);


    return 0;
}
