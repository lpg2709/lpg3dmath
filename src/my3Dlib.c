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

void lpgM3DvecCrossProduct4f(float m[3], float u[3], float v[3]){
    m[0] = u[1]*v[2] - v[1]*u[2];
    m[1] =-u[0]*v[2] + v[0]*u[2];
    m[2] = u[0]*v[1] - v[0]*u[1];
}

void lpgM3DvecSize4f(float vetor[3], float *tam){
    *tam = sqrt((vetor[0]*vetor[0]) + (vetor[1]*vetor[1]) + (vetor[2]*vetor[2]));
}
void lpgM3DvecNormalize3f(lpgM3Dvec3f vetor){
    float tam;
    lpgM3DvecSize4f(vetor, &tam);
    vetor[0] = vetor[0] / tam;
    vetor[1] = vetor[1] / tam;
    vetor[2] = vetor[2] / tam;
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
