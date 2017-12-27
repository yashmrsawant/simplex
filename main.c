/***
 * @Name : Yash M Sawant
 * @Roll Number : mtc-1614
 * @mail : yashmrsawant@gmail.com
 *
 */
// Maximization Problem

#include "commons.h"



int main(int argc, char** argv) {


	int i, z;
	float objV = 0;

	INF = 999999999;

	inputHandler();
	
	z = solveSimplex();
	if(z == 0 || z == 1) {
    	printf("Basis : \n");
    		for(i = 0 ; i < m ; i ++) {
    			printf("X%d = %f, cExtra = %f\n", basis[i], table[i][2 * n + 2 * m], cExtra[basis[i]]);
			printf("%f \n", table[i][2 * n + 2 * m]);
    			objV = objV + table[i][2 * n + 2 * m] * cExtra[basis[i]];
    		}
		
		if(isMaximization == -1) {
			objV = -1 * objV;
		}
    		printf("Objective Function Value = %f\n", objV);
    	} else if(z == 20) {
    		printf("Infeasible\n");
    	} else if(z == 30) {
		for(i = 0 ; i < m ; i ++) {
			printf("X%d = %f, cExtra = %f\n", basis[i] + 1, table[i][2 * n + 2 *m], cExtra[basis[i]]);
			objV = objV + table[i][2 * n + 2 * m] * cExtra[basis[i]];
		}
		printf("Objective Function Value = %f\n", objV);
    		printf("Unbounded\n");
    	}

    return 0;
}



