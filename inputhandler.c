/*
 * inputhandler.c
 *
 *  Created on: 22-Dec-2017
 *      Author: yashmrsawant
 */

#include "commons.h"

void printTable() {
    int i, j;
    for(i = 0 ; i < m ; i ++){
        for(j = 0 ; j < (2 * n + 2 * m + 1) ; j ++) {
            printf("%5.2f ", table[i][j]);
        }
        printf("\n");
    }
}


int inputHandler() {



	/**
	 *
	 *	n, m
	 *	<n spaced floating point numbers>
	 *	<n spaced boolean variable> (regarding unrestrictedness of variable)
	 *	1) <n spaced floating point numbers> <positive number> <1 or 0>
	 *	2)---------------"-------------------------------------------
	 *	3)---------------"-------------------------------------------
	 *	i)---------------"-------------------------------------------
	 *	m) <n spaced floating point numbers> <positive number> <1 or 0>
	 *
	 */
	int i = 0; int j = 0;
	int z;
	scanf("%d", &isMaximization); //1 for maximization & -1 for minimization
	scanf("%d %d", &n, &m);


	obj = (float *)(malloc(sizeof(float) * n));
	objUnrestrictedFlag = (int *)(malloc(sizeof(int) * n));
	cExtra = (float *)(malloc(sizeof(float *) * (2 * n + 2 * m)));

	table = (float **)(malloc(sizeof(float*) * m));
	for(; i < m ; i ++) {
		table[i] = (float *)(malloc(sizeof(float) * (2 * n + 2 * m + 1)));
		for(j = 0 ; j < (2 * n + 2 * m + 1) ; j ++) {
			table[i][j] = 0;
		}
	}

	for(i = 0 ; i < n ; i ++) {
		scanf("%f %d", &obj[i], &objUnrestrictedFlag[i]);
		cExtra[i] = isMaximization * obj[i];
		if(objUnrestrictedFlag[i] == 1) {
			cExtra[n + 2 * m + i] = -1 * obj[i];
		} else {
			cExtra[n + 2 * m + i] = 0;
		}
	}

	for(i = 0 ; i < m ; i ++) {
		for(j = 0 ; j < n ; j ++) {
			scanf("%f", &table[i][j]);
			if(objUnrestrictedFlag[j] == 1) {
				table[i][n + 2 * m + j] = -1 * table[i][j];

			}
		}
		// For b
		scanf("%f", &table[i][2 * n + 2 * m]);
		// For >=(1) or <= (0)
		scanf("%d", &z);
		if(z == 1) {
			table[i][n + i] = -1;
			table[i][n + m + i] = 1;
			cExtra[n + i] = 0;
			cExtra[n + m + i] = -1 * INF;
		} else {
			table[i][n + i] = 1;
			table[i][n + m + i] = 0;
			cExtra[n + i] = 0;
			cExtra[n + m + i] = 0;
		}
	}
	printTable();
	return 0;
}
