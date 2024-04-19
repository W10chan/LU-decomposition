#include <stdio.h>
#include <math.h>
#define DIM 4

int main()
{
    int i, j, k, m, n, dim, maxline;
    float temp, alpha, reserve, sum1, sum2;
    float A[DIM][DIM],L[DIM][DIM],U[DIM][DIM];
    float b[DIM],x[DIM],y[DIM];

//  input matrix-------------------------------------------
//  A
    printf("input Matrix\n");
    for(i = 0; i < DIM; i++){
        for(j = 0; j < DIM; j++){
            printf("A[%d][%d]:", i+1, j+1);
            scanf("%f", &A[i][j]);
            L[i][j] = 0.0;
            U[i][j] = 0.0;
        }
    }

//  B
    for(i = 0; i < DIM; i++){
        printf("B[%d]:", i+1);
        scanf("%f", &b[i]);
    }
//  -------------------------------------------------------
//  output to input----------------------------------------
    printf("A\n");
    for(i = 0; i < DIM; i++){
        for(j = 0; j < DIM; j++){
            printf(" %f ",A[i][j]);
        }
        printf("\n");
    }

    printf("B\n");
    for(i = 0; i < DIM; i++){
        printf(" %f \n",b[i]);
    }
//  -------------------------------------------------------
//  LU ----------------------------------------------------
    for(i = 0; i < DIM; i++){
        L[i][i] = 1.0;
    }
    for(i = 0; i < DIM; i++){
        for(j = 0; j < DIM; j++){
            if( i <= j){
                sum1 = 0.0;
                for(m = 0; m <= i-1; m++){
                    sum1 += L[i][m] * U[m][j];
                }
                U[i][j] = A[i][j] - sum1;
            }
            else if(i > j){
                sum2 = 0.0;
                for(n = 0; n <= j-1; n++){
                    sum2 += L[i][n] * U[n][j];
                }
                L[i][j] = (A[i][j] - sum2) / U[j][j];
            }
        }
    }
//  -------------------------------------------------------
//  output for LU------------------------------------------
//  L------------------------------------------------------
    printf("L\n");
    for(i = 0; i < DIM; i++){
        for(j = 0; j < DIM; j++){
            printf(" %f ",L[i][j]);
        }
        printf("\n");
    }
//  U------------------------------------------------------
    printf("U\n");
    for(i = 0; i < DIM; i++){
        for(j = 0; j < DIM; j++){
            printf(" %f ",U[i][j]);
        }
        printf("\n");
    }
//  -------------------------------------------------------
//  solve the problem--------------------------------------
//  Ly = b-------------------------------------------------
    for(i = 0; i < DIM; i++){
        y[i] = b[i];
    }

    for(j = 0; j < DIM-1; j++){
        for(i = j+1; i < DIM; i++){
            y[i] -= y[j] * L[i][j];
        }
    }

//  Ux = y
    for(i = 0; i < DIM; i++){
        x[i] = y[i];
    }

    for(j = DIM-1; j >= 0; j--){
        x[j] /= U[j][j];
        for (i = 0; i <= j-1; i++){
            x[i] -= U[i][j] * x[j];
        }
    }
//  -------------------------------------------------------
//  output x-----------------------------------------------
    printf("x\n");
    for(i = 0; i < DIM; i++){
        printf("x[%d] = %f\n",i+1,x[i]);
    }
}
