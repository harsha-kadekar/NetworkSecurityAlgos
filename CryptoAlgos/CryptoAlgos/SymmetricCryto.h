#ifndef SYMMETRICCRYPTO_H
#define SYMMETRICCRYPTO_H

#include "ErrorCodes.h"
#include <stdlib.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

	_declspec(dllimport) int CeaserCipher(char* strPlainText, int nSize, char* strCipherText, int* pKey);
	_declspec(dllimport) int CeaserDecipher(char* strCipherText, int nSize, char* strPlainText, int nKey);
	_declspec(dllimport) int AtbashDecipher(char* strCipherText, int nSize, char* strPlainText);
	_declspec(dllimport) int AtbashCipher(char* strPlainText, int nSize, char* strCipherText);

#ifdef __cplusplus
}
#endif

#endif
