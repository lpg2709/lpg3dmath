#include <stdio.h>
#include <stdlib.h>

#include "./src/my3Dlib.h"

int main(){

    matrix44f m;
    loadIdentity(m);

    int i;
    vec3f vec = {2, 2, 2};
    translate4f(m, vec);
    scale4f(m, vec);

    for(i = 0; i < 16;i++){
        if(i%4 == 0 && i != 0)
            printf("\n");
        printf("%.1f ", m[i]);
    }


    return 0;
}
