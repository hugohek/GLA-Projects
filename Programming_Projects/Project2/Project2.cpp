// matrix-multiplication <Project2.cpp>
// ECE 312 Project 2 submission by
// <Your Name Here>
// <Your EID>
// Slip days used: <0>
// Fall 2023

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"

void multiplyMatrices(double a[],
                      const uint32_t a_rows, const uint32_t a_cols,
                      double b[], const uint32_t b_cols, double c[])
{ // https://en.wikipedia.org/wiki/Row-_and_column-major_order
    // Part A
    /* --------------------------------------------------------*/
   // if (a_cols != b_cols) return;
    
    for (uint32_t m = 0; m < a_rows; m++)
    {
        for (uint32_t n = 0; n < b_cols; n++)
        {
            double matx = 0.0;
            for (uint32_t o = 0; o < a_cols; o++)
            {
// cij = Ai0B0j + Ai1B1j + Ai2B2j + ... + Ai(n−1)B(n−1)j
// = a[0][0]*b[0][0] + a[0][0+1]*b[0+1][0] + a[0][0+2]*b[0+2][0]
                matx += a[m * a_cols + o] * b[o * b_cols + n]; // c[m*b_cols+n]
            }
            c[m * b_cols + n] = matx;
           // printf("%f\n", matx);
        }
    }
}

double **multiplyMatricesPtr(
    double **a,
    const uint32_t a_rows,
    const uint32_t a_cols,
    double **b,
    const uint32_t b_cols)
{
    double **c = (double **)malloc(a_rows * sizeof(double *));
   // if (c != NULL && a_cols == b_cols)
  //  {
        for (uint32_t m = 0; m < a_rows; m++)
        {
            c[m] = (double *)malloc(b_cols * sizeof(double));
        //    if (c[m] == NULL)  {   return NULL;}
        }

        for (uint32_t m = 0; m < a_rows; m++)
       {
            for (uint32_t n = 0; n < b_cols; n++)
            {
                double matx = 0.0;
                for (uint32_t o = 0; o < a_cols; o++)
                {
                    // cij = Ai0B0j + Ai1B1j + Ai2B2j + ... + Ai(n−1)B(n−1)j
                    // = a[0][0]*b[0][0] + a[0][0+1]*b[0+1][0] + a[0][0+2]*b[0+2][0]
                    matx += a[m][o] * b[o][n]; // c[m*b_cols+n]
                }
                c[m][n] = matx;
            }
        }
        return c;
  //  }
}

// https://en.wikipedia.org/wiki/Matrix_(mathematics)#Submatrix
double **createSubMatrix(
    double **a,
    const unsigned a_rows,
    const unsigned a_cols,
    const unsigned row_x,
    const unsigned col_y)
{
    double **matx = (double **)malloc((a_rows - 1) * sizeof(double *));
   // if (matx == NULL){ return NULL;    }

    for (uint32_t i = 0; i < a_rows - 1; i++)
    {
        matx[i] = (double *)malloc((a_cols - 1) * sizeof(double));
      //  if (matx[i] == NULL) { return NULL;  }
    }
    for (uint32_t i = 0, ix = 0; i < a_rows; i++)
    { if(i != row_x){
            for (uint32_t j = 0, jy = 0; j < a_cols; j++)
            {
                if(j != col_y){
                    matx[ix][jy] = a[i][j];
                    jy++;
                }
            }
            ix++;
        }
    }

    return matx;
}
