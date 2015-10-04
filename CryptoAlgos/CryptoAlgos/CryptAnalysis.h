#ifndef CRYPTANALYSIS_H
#define CRYPTANALYSIS_H

#include "ErrorCodes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

	_declspec(dllimport) int CeaserCipher_BruteForce(char* strCipheredText, int nSize);

#ifdef __cplusplus
}
#endif

#endif
