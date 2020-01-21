#include <stdio.h>
#include <stdlib.h>

#include "./src/my3Dlib.h"

int main(){

    matrix44f m = {
         1,  5,  9, 13,
         2,  6, 10, 14,
         3,  7, 11, 15,
         4,  8, 12, 16
    };

    matrix44f n = {
         2,  2,  2,  2,
         2,  2,  2,  2,
         2,  2,  2,  2,
         2,  2,  2,  2
    };

    matrix44f res;
    vec3f v = {0, 0, 1};

//    multi4f(res, m, n);

    rotationr4fv(n, 90, v);

    printMatrix44f(n);


    return 0;
}
