#include "./my3Dlib.h"

void lpgM3DloadIdentity(lpgM3Dmatrix44f m){

    static lpgM3Dmatrix44f matrixIdentity = { 1.0f, 0.0f, 0.0f, 0.0f,
                                             0.0f, 1.0f, 0.0f, 0.0f,
                                             0.0f, 0.0f, 1.0f, 0.0f,
                                             0.0f, 0.0f, 0.0f, 1.0f };

    memcpy(m, matrixIdentity, sizeof(matrixIdentity));
}

void lpgM3Drotationr4f(lpgM3Dmatrix44f m, float angulo, float x, float y, float z){
    float seno, cosseno, moduloVetor;
    float xx,yy,zz,xy,xz,yz,xseno,zseno,yseno,umMenosCosseno;

    seno = (float)sin(angulo);
    cosseno = (float) cos(angulo);

    moduloVetor = (float) sqrt(x*x + y*y + z*z);

    if(moduloVetor == 0.0f){
        return ;
    }

    x = x/moduloVetor;
    y = y/moduloVetor;
    z = z/moduloVetor;

    xx = x*x;
    yy = y*y;
    zz = z*z;
    xy = x*y;
    xz = x*z;
    yz = y*z;
    xseno = x*seno;
    yseno = y*seno;
    zseno = z*seno;
    umMenosCosseno = 1.0f - cosseno;
    #define M(linha,coluna) m[coluna*4 + linha]

    M(0,0) = (xx*umMenosCosseno) + cosseno;
    M(0,1) = (xy*umMenosCosseno) + zseno;
    M(0,2) = (xz*umMenosCosseno) - yseno;
    M(0,3) = 0.0f;
    M(1,0) = (xy*umMenosCosseno) - zseno;
    M(1,1) = (yy*umMenosCosseno) + cosseno;
    M(1,2) = (yz*umMenosCosseno) + xseno;
    M(1,3) = 0.0f;
    M(2,0) = (xz*umMenosCosseno) + yseno;
    M(2,1) = (yz*umMenosCosseno)- xseno;
    M(2,2) = (zz*umMenosCosseno) + cosseno;
    M(2,3) = 0.0f;
    M(3,0) = 0.0;
    M(3,1) = 0.0f;
    M(3,2) = 0.0f;
    M(3,3) = 1.0f;

    #undef M
/*
    |[x*x(1-cos @) +   cos @] [x*y(1-cos @) - z*sin @] [x*z(1-cos @) + y*sin @]   [0]   |
    |[x*y(1-cos @) + z*sen @] [y*y(1-cos @) +   cos @] [y*z(1-cos @) - x*sin @]   [0]   |
    |[x*z(1-cos @) - y*sen @] [y*z(1-cos @) + x*sin @] [z*z(1-cos @) +   cos @]   [0]   |
    |[             0        ] [             0        ] [             0        ]   [1]   |
*/
}

void lpgM3Drotationd4f(lpgM3Dmatrix44f m, float angulo, float x, float y, float z){
    angulo = angulo*0.017453292519943296;
    lpgM3Drotationr4f(m, angulo, x, y, z);
}

void lpgM3Drotationd4fv(lpgM3Dmatrix44f m, float angulo, lpgM3Dvec3f vec){
    lpgM3Drotationd4f(m, angulo, vec[0], vec[1], vec[2]);
}
void lpgM3Drotationr4fv(lpgM3Dmatrix44f m, float angulo, lpgM3Dvec3f vec){
    lpgM3Drotationr4f(m, angulo, vec[0], vec[1], vec[2]);
}

void lpgM3Dscale4f(lpgM3Dmatrix44f m, float x, float y, float z){

    #define M(l,c) m[(c*4)+l]

    M(0,0) = M(0,0)*x;
    M(1,1) = M(1,1)*y;
    M(2,2) = M(2,2)*z;
    M(3,3) = 1;

    #undef M

}

void lpgM3Dscale4fv(lpgM3Dmatrix44f m, lpgM3Dvec3f vec){

    lpgM3Dscale4f(m, vec[0], vec[1], vec[2]);

}

void lpgM3Dtranslate4f(lpgM3Dmatrix44f m,  float x, float y, float z){
    #define M(l,c) m[(c*4)+l]

    M(0,3) = M(0,3) + x;
    M(1,3) = M(1,3) + y;
    M(2,3) = M(2,3) + z;
    M(3,3) = 1;

    #undef M
}

void lpgM3Dtranslate4fv(lpgM3Dmatrix44f m, lpgM3Dvec3f vec){
    lpgM3Dtranslate4f(m, vec[0], vec[1], vec[2]);
}

void lpgM3Dmulti4f(lpgM3Dmatrix44f m, lpgM3Dmatrix44f a, lpgM3Dmatrix44f b){
    #define A(l,c) a[(c*4)+l]
    #define B(l,c) b[(c*4)+l]
    #define C(l,c) m[(c*4)+l]

    int i;
    float ai0, ai1, ai2, ai3;
    for(i = 0; i < 4;i++){
        ai0 = A(i,0);
        ai1 = A(i,1);
        ai2 = A(i,2);
        ai3 = A(i,3);
        C(i,0) = (ai0 * B(0,0)) + (ai1 * B(1,0)) + (ai2 * B(2,0)) + (ai3 * B(3,0));
        C(i,1) = (ai0 * B(0,1)) + (ai1 * B(1,1)) + (ai2 * B(2,1)) + (ai3 * B(3,1));
        C(i,2) = (ai0 * B(0,2)) + (ai1 * B(1,2)) + (ai2 * B(2,2)) + (ai3 * B(3,2));
        C(i,3) = (ai0 * B(0,3)) + (ai1 * B(1,3)) + (ai2 * B(2,3)) + (ai3 * B(3,3));
    }

    #undef A
    #undef B
    #undef C
}

void lpgM3DvecCrossProduct3f(lpgM3Dvec3f res, float aX, float aY, float aZ, float bX, float bY, float bZ){
    res[0] = aY*bZ - bY*aZ;
    res[1] =-aX*bZ + bX*bZ;
    res[2] = aX*bY - bX*bY;
}

void lpgM3DvecCrossProduct3fv(lpgM3Dvec3f m, lpgM3Dvec3f a, lpgM3Dvec3f b){
    lpgM3DvecCrossProduct3f(res, a[0], a[1], a[2], b[0], b[1], b[2]);
}


void lpgM3DvecSize4f(float vetor[3], float *tam){
    *tam = sqrt((vetor[0]*vetor[0]) + (vetor[1]*vetor[1]) + (vetor[2]*vetor[2]));
}

void lpgM3DaddVector3f(lpgM3Dvec3f res, float aX, float aY, float aZ, float bX, float bY, float bZ){
    res[0] = aX + bX;
    res[1] = aY + bY;
    res[2] = aZ + bZ;
}

void lpgM3DaddVector3fv(lpgM3Dvec3f res, lpgM3Dvec3f a, lpgM3Dvec3f b){
    lpgM3DaddVector3f(res, a[0], a[1], a[2], b[0], b[1], b[2]);
}

void lpgM3DsubtractVector3f(lpgM3Dvec3f res, float aX, float aY, float aZ, float bX, float bY, float bZ){
    lpgM3DaddVector3f(res, aX, aY, aZ, -bX, -bY, -bZ);
}

void lpgM3DsubtractVector3fv(lpgM3Dvec3f res, lpgM3Dvec3f a, lpgM3Dvec3f b){
    lpgM3DsubtractVector3f(res, a[0], a[1], a[2], b[0], b[1], b[2]);
}

void lpgM3DvecNormalize3f(lpgM3Dvec3f vetor){
    float tam;
    lpgM3DvecSize4f(vetor, &tam);
    vetor[0] = vetor[0] / tam;
    vetor[1] = vetor[1] / tam;
    vetor[2] = vetor[2] / tam;
}

void lpgM3Dorth(lpgM3Dmatrix44f m, float left, float right, float bottom, float top, float near, float far){

    lpgM3DloadIdentity(m);

    float rl, tb, fn, plusrl, plustb, plusfn;

    rl = right-left;
    tb = top-bottom;
    fn = far-near;
    plusrl = right+left;
    plustb = top+bottom;
    plusfn = far+near;

    m[0] = (2.0f/rl);
    m[3] = (-plusrl/rl);
    m[5] = (2.0f/tb);
    m[7] = (-plustb/tb);
    m[10] = (-2.0f/fn);
    m[11] = (-plusfn/fn);
    m[15] = 1.0f;

/*
    |[2/(right-left)] [       0      ] [       0      ] [ -(right+left)/(right-left) ]|
    |[       0      ] [2/(top-bottom)] [       0      ] [-((top+bottom)/(top-bottom))]|
    |[       0      ] [       0      ] [ -2/(far-near)] [  -((far+near)/(far-near))  ]|
    |[       0      ] [       0      ] [       0      ] [              1             ]|
*/
}


void lpgM3Dperspective(lpgM3Dmatrix44f m, float fov, float aspect, float near, float far){

    lpgM3DloadIdentity(m);

    fov = fov*0.017453292519943296;

    float top = near * tanf(fov*0.5);
    float bottom = -top;
    float left = bottom * aspect;
    float right = -left;

    m[0]  = (2.0f * near)/(left - right);
    m[5]  = (2.0f * near)/(top - bottom);
    m[8]  = (right + left)/((right - left));
    m[9]  = (top + bottom)/(top-bottom);
    m[10] = -((far + near)/(far-near));
    m[11] = -1.0f;
    m[14] = -((2.0f * (far*near))/(far-near));
    m[15] = 0.0f;

}


void lpgM3DlookAtf(lpgM3Dmatrix44f lookAtm, float posX, float posY, float posZ, float targerX, float targerY, float targerZ, float upX, float upY, float upZ){
    lpgM3Dvec3f direction;
    lpgM3DsubtractVector3f(direction, posX, posY, posZ, targerX, targerY, targerZ);
    lpgM3DvecNormalize3f(direction);


}



void lpgM3DprintMatrix33f(lpgM3Dmatrix33f m){
    int i;
    printf("\n");
    for(i = 0;i < 9;i++){
        if(i%3 == 0 && i != 0)
            printf("\n");
        printf(" %.2f ", m[i]);
    }
    printf("\n");
}

void lpgM3DprintMatrix22f(lpgM3Dmatrix22f m){
    int i;
    printf("\n");
    for(i = 0;i < 4;i++){
        if(i%2 == 0 && i != 0)
            printf("\n");
        printf(" %.2f ", m[i]);
    }
    printf("\n");

}

void lpgM3DprintMatrix44f(lpgM3Dmatrix44f m){
    int i;
    printf("\n");
    for(i = 0;i < 16;i++){
        if(i%4 == 0 && i != 0)
            printf("\n");
        printf(" %.2f ", m[i]);
    }
    printf("\n");
}

void lpgM3DprintVec3f(lpgM3Dvec3f v){
    printf("\n(%f, %f, %f)\n", v[0], v[1], v[2]);
}
