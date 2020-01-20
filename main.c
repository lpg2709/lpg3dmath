#include <stdio.h>
#include <stdlib.h>

#include "./src/my3Dlib.h"

int main(){

    matrix44f m;
    loadIdentity(m);

    int i;
    vec3f vec = {2, 2, 2};
    translate4fv(m, vec);
    scale4fv(m, vec);

    printMatrix44f(m);


    return 0;
}
