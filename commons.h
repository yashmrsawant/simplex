/*
 * commons.h
 *
 *  Created on: 20-Dec-2017
 *      Author: yashmrsawant
 */

#ifndef COMMONS_H_
#define COMMONS_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>


#define AVG 10
#define MAX 10000

int n, m;
float* obj;
int* objUnrestrictedFlag;
long long int INF;

float* cExtra;
float** table;
float* cMinusZ;
int* basis;
int isMaximization;

struct timeval time_start;
struct timeval time_end;

int inputHandler();
int solveSimplex();
void printTable();
void getLPOfSize(int size, FILE* file);
void Free();


#endif /* COMMONS_H_ */
