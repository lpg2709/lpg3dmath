#include <stdio.h>
#include <stdlib.h>

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

    lpgM3Dmatrix44f res;
    lpgM3Dvec3f v = {0, 0, 1};

//    lpgM3Dmulti4f(res, m, n);

    lpgM3Drotationr4fv(n, 90, v);

    lpgM3DprintMatrix44f(n);


    return 0;
}
