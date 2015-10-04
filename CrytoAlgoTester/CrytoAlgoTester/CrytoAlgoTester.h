
#ifndef CRYPTOALGOTESTER_H
#define CRYPTOALGOTESTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

typedef int (*CeaserCipher_BruteForce)(char* , int );
typedef int (*CeaserCipher)(char* , int , char* , int* );
typedef int (*CeaserDecipher)(char*, int, char*, int);

int TestCaesorCipher();


#endif
