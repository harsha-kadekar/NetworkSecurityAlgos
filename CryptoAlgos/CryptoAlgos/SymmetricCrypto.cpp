/*
Name: SymmetricCrypto.cpp
Description: This has all the functions which implement various symmetric cryptography algorithms.
*/
#include "SymmetricCryto.h"

/*
Name: CeaserCipher
Description: This function will implement ceaser cipher. Currently it only handles english alphabet.
Parameter: strPlainText -> This is the plain text which needs to be encrypted.
		   nSize -> Length of the plain text
		   strCiphterText-> This will hold the encrypted message.
		   pKey -> This will hold the key used for encryption.
ReturnValue: 0 for success else errors
*/
int CeaserCipher(char* strPlainText, int nSize, char* strCipherText, int* pKey)
{
	int nReturnValue = 0;
	int nTemp = '\0';

	if (strPlainText == 0 || strCipherText == 0 || pKey == 0 || nSize <= 0 )
	{
		return ERR_INVALIDINPUTPARAMETERS;
	}

	//Check if user is providing a key otherwise we need to generate key
	if (*pKey == -1 || (*pKey < 1 && *pKey > 25 ))
	{
		srand(time(0));
		*pKey = rand() % 26;

		if (*pKey == 0)
			*pKey = 1;
	}

	for (int i = 0; i < nSize; i++)
	{
		if (strPlainText[i] >= 65 && strPlainText[i] <= 90)
		{
			//Capital letters
			nTemp = strPlainText[i] + *pKey;

			if (nTemp > 90)
			{
				nTemp = nTemp - 26;
			}
			strCipherText[i] = nTemp;
		}
		else if (strPlainText[i] >= 97 && strPlainText[i] <= 122)
		{
			//small letters
			nTemp = strPlainText[i] + *pKey;

			if (nTemp > 122)
			{
				nTemp = nTemp - 26;
			}
			strCipherText[i] = nTemp;
		}
		else
		{
			strCipherText[i] = strPlainText[i];
		}
	}

	return nReturnValue;
}

/*
Name: CeaserDecipher
Description: This function given the cipher text from Ceaser cipher it will decipher it using key
Parameters: strCipherText -> This is the encrypted / Cipher text which needs to be deciphered
			strPlainText -> this will hold the decrpted text
			nSize -> Size of the cipher text
			nKey -> Key to use to decipher it
ReturnValue: Returns 0 for success else error codes
*/

int CeaserDecipher(char* strCipherText, int nSize, char* strPlainText, int nKey)
{
	int nReturnValue = 0;
	int nTemp = '\0';

	if (strCipherText == 0 || strPlainText == 0 || nSize <= 0 || nKey < 1 || nKey > 25 )
	{
		return ERR_INVALIDINPUTPARAMETERS;
	}

	for (int i = 0; i < nSize; i++)
	{
		if (strCipherText[i] >= 65 && strCipherText[i] <= 90)
		{
			nTemp = strCipherText[i] - nKey;
			if (nTemp < 65)
			{
				nTemp = 26 + nTemp;
			}
			strPlainText[i] = nTemp;
		}
		else if (strCipherText[i] >= 97 && strCipherText[i] <= 122)
		{
			nTemp = strCipherText[i] - nKey;
			if (nTemp < 97)
			{
				nTemp = 26 + nTemp;
			}
			strPlainText[i] = nTemp;
		}
		else
		{
			strPlainText[i] = strCipherText[i];
		}
	}

	return nReturnValue;
}


int MatrixMultiplication(int** pMatrixA, int Am, int An, int** pMatrixB, int Bm, int Bn, int** pMatrixC)
{
	int nReturnValue = 0;

	for (int i = 0; i < Am; i++)
	{
		for (int j = 0; j < Bn; j++)
		{
			pMatrixC[i][j] = 0;
			for (int k = 0; k < An; k++)
			{
				pMatrixC[i][j] += pMatrixA[i][k] + pMatrixB[k][j];
			}
		}
	}

	return nReturnValue;
}

