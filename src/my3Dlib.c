#include "./my3Dlib.h"

void loadIdentity(matrix44f m[16]){

    static matrix44f matrixIdentity = { 1.0f, 0.0f, 0.0f, 0.0f,
                                        0.0f, 1.0f, 0.0f, 0.0f,
                                        0.0f, 0.0f, 1.0f, 0.0f,
                                        0.0f, 0.0f, 0.0f, 1.0f };

    memcpy(m, matrixIdentity, sizeof(matrixIdentity));
}

void rotation4f(float m[16], float angulo, float x, float y, float z){
    float seno, cosseno, moduloVetor;
    float xx,yy,zz,xy,xz,yz,xseno,zseno,yseno,umMenosCosseno;

    angulo = angulo*0.017453292519943296;

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

void multi4f(float m[16], float a[16], float b[16]){
    #define A(c,l) a[(c*4)+l]
    #define B(c,l) b[(c*4)+l]
    #define C(c,l) m[(c*4)+l]
    int i;
    for(i = 0; i<4;i++){
        C(i,0) = (A(i,0) * B(0,0)) + (A(i,1) * B(1,0)) + (A(i,2) * B(2,0));
        C(i,1) = (A(i,0) * B(0,1)) + (A(i,1) * B(1,1)) + (A(i,2) * B(2,1));
        C(i,2) = (A(i,0) * B(0,2)) + (A(i,1) * B(1,2)) + (A(i,2) * B(2,2));
        C(i,3) = (A(i,0) * B(0,3)) + (A(i,1) * B(1,3)) + (A(i,2) * B(2,3));
    }

    #undef A
    #undef B
    #undef C
}

void vecCrossProduct4f(float m[3], float u[3], float v[3]){
    m[0] = u[1]*v[2] - v[1]*u[2];
    m[1] =-u[0]*v[2] + v[0]*u[2];
    m[2] = u[0]*v[1] - v[0]*u[1];
}

void vecSize4f(float vetor[3], float *tam){
    *tam = sqrt((vetor[0]*vetor[0]) + (vetor[1]*vetor[1]) + (vetor[2]*vetor[2]));
}
void vecNormalize3f(float vetor[3]){
    float tam;
    vecSize4f(vetor, &tam);
    vetor[0] = vetor[0] / tam;
    vetor[1] = vetor[1] / tam;
    vetor[2] = vetor[2] / tam;
}
