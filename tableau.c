/*
 * tableau.c
 *
 *  Created on: 20-Dec-2017
 *      Author: yashmrsawant
 */


#include "commons.h"


float epsilon = 0.001;

float dot(int* basis, int ind, float* cExtra) {
    float z = 0;
    int i = 0;
    for(; i < m ; i ++) {
        z = z + cExtra[basis[i]] * table[i][ind];
    }
    return z;
}

int solveSimplex() {


    int i, j;
	float zMul, zDiv, objV;
    int artificialVariableInBasis, feasibleFlag;
    int enteringI,pivotI;
    float enteringV, pivotV;

    float* cMinusz = (float *)(malloc(sizeof(float) * (2 * n + 2 * m + 1)));
    float* theta = (float *)(malloc(sizeof(float) * m));
    float* values = (float *)(malloc(sizeof(float) * m));
    basis = (int *)(malloc(sizeof(int) * m));
    int* iBasis = (int *)(malloc(sizeof(int) * (2 * n + 2 * m)));


    printf("C : ");
    for(i = 0 ; i < (2 * n + 2 * m) ; i ++) {
    	//printf("%5.2f ", cExtra[i]);
    	iBasis[i] = -1;
    }
    printf("\n");

    for(i = 0 ; i < m ; i ++) {
        if(table[i][n + i] == -1) {
        	basis[i] = n + m + i;
        	iBasis[n + m + i] = i;
        } else {
        	basis[i] = n + i;
        	iBasis[n + i] = i;
        }
    }

    while(1) {
    	artificialVariableInBasis = 0;
    	enteringI = -1;
    	enteringV = 0;
    	pivotI = -1;
    	objV = 0;
    	printf("Basis : ");
    	for(i = 0 ; i < m ; i ++) {
    		printf("%d ", basis[i]);
    		objV = objV + cExtra[basis[i]] * table[i][2 * n + 2 *m];
    	}
    	printf("\n");
    	printf("Current Objective Value : %5.2f", objV);
    	printf("\n");

      	// Checking whether artificialVariableInBasis
    	for(i = 0 ; i < m ; i ++) {
    		if(basis[i] >= n + m && basis[i] <= (n + 2 * m - 1)) {
    			artificialVariableInBasis = 1;
    			break;
    		}
    	}
    	printf("CMinusZ :");
    	for(i = 0 ; i < (2 * n + 2 * m + 1) ; i ++) {
    		if(artificialVariableInBasis) {
				if(i == (2 * n + 2 * m))
					continue;

    		} else {
    			if(i == (2 * n + 2 * m)) {
    				cMinusz[i] = dot(basis, i, cExtra);
    			}
    		}
    		if(i != (2 * n + 2 * m) && iBasis[i] < 0) {
    			// Non Basis

    			cMinusz[i] = cExtra[i] - dot(basis, i, cExtra);
    		} else if(i != (2 * n + 2 * m)){
    			cMinusz[i] = 0;
    		}
    		//printf("%5.2f ", cMinusz[i]);
    	}
    	//printf("\n");
    	for(i = 0 ; i < (2 * n + 2 * m) ; i ++) {
    		if(cMinusz[i] > epsilon) {
    			if(enteringI == -1) {
    				enteringI = i;
    				enteringV = cMinusz[i];
    			} else {
    				if(enteringV < cMinusz[i]) {
    					enteringI = i;
    					enteringV = cMinusz[i];
    				}
    			}
    		}
    	}

    	if(enteringI == -1) {
    		if(artificialVariableInBasis) {
    			feasibleFlag = 1;
    			for(i = 0 ; i < m ; i ++) {
    				if(basis[i] >= (n + m) && basis[i] <= (n + 2 * m - 1)) {
    					if(table[i][2 * n + 2 * m] != 0) {
    						feasibleFlag = 0;
    						break;
    					}
    				}
    			}
    			if(feasibleFlag == 1) {
    				return 1;
    			}
    			if(enteringI == -1)
    				return 20;
    		}
    		return 0;
    	}
    	for(i = 0 ; i < m ; i ++) {
    		if(table[i][enteringI] == 0 || table[i][enteringI] < 0) {
    			theta[i] = INF;
    		} else {
    			theta[i] = table[i][2 * n + 2 * m] / table[i][enteringI];
    		}
    		if(pivotI == -1) {
    			pivotI = i;
    			pivotV = theta[i];
    		} else{
    			if(pivotV > theta[i]) {
    				pivotI = i;
    				pivotV = theta[i];
    			}
    		}
    	}

    	if(pivotV == INF) {
		printf("Set of feasible basis\n");
		for(i = 0 ; i < m ; i ++) {
			printf("x%d = %f ", basis[i] + 1, values[i]);		
		}
    		return 30; //Unbounded
    	}

    	//Changing Basis
    	iBasis[basis[pivotI]] = -1;
    	basis[pivotI] = enteringI;
    	iBasis[enteringI] = pivotI;

    	//Updating table rows
    	for(i = 0 ; i < m ; i ++) {
    		zMul = table[i][enteringI];
    		zDiv = table[pivotI][enteringI];
    		for(j = 0 ; j < (2 * n + 2 * m + 1) ; j ++) {
    			if(i == pivotI) {
    				table[i][j] = table[i][j] / zDiv;
    			} else {
    				table[i][j] = table[i][j] - zMul * table[pivotI][j] / zDiv;
    			}
    		}
		values[i] = table[i][2 * n + 2 * m];
    	}
    	//printf("Table : ");
    	//printTable();

    }
    return 0;
}
