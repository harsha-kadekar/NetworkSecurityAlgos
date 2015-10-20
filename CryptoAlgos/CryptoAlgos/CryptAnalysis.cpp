/*
Name: CryptAnalysis.cpp
Description: This file has different functions each using different methods to find the plain text or key from the ciphered text
*/

#include "CryptAnalysis.h"



int FrequencyAnalysisOfCipherText(char* strCipherText, int nSize)
{
	int nReturnValue = 0;

	int nLetterCount[26] = { 0 };
	float fLetterFrequency[26] = { 0 };

	for (int i = 0; i < nSize; i++)
	{
		if (strCipherText[i] >= 65 && strCipherText[i] <= 90)
		{
			nLetterCount[strCipherText[i] - 'A']++;
		}
		else if (strCipherText[i] >= 97 && strCipherText[i] <= 122)
		{
			nLetterCount[strCipherText[i] - 'a']++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		fLetterFrequency[i] = (nLetterCount[i] * 100.00 / nSize);
	}


	return nReturnValue;
}


/*
Name: CeaserCipher_BruteForce
Description: This function will do a brute force attack on the ciphered text. Text has been encrypted by Caeser cipher.
Parameter: strCipheredText -> Encrypted message which needs to be breaken
		   nSize -> Length of the text strCipheeredText
ReturnValue: 0 means no error else error codes. Deciphered text will be written in a text file.
*/
int CeaserCipher_BruteForce(char* strCipheredText, int nSize)
{
	int nReturnValue = 0;
	char* strPlainText = 0;
	FILE *fpOutputFile = 0;
	char strKey[6] = { '\0' };
	int nTemp = '\0';

	if (strCipheredText == 0 || nSize <= 0)
	{
		return ERR_INVALIDINPUTPARAMETERS;
	}

	strPlainText = (char*)malloc(sizeof(char)*(nSize+1));
	if (strPlainText == 0)
	{
		return ERR_MEMORYALLOCAIONFAILED;
	}

	memset(strPlainText, '\0', nSize+1);

	fopen_s(&fpOutputFile, "CaeserBruteForce_PossiblePlainText.txt", "w");
	if (fpOutputFile == 0)
	{

		free(strPlainText);
		strPlainText = 0;

		return ERR_FILEOPENERROR;
	}


	for (int i = 1; i < 25; i++)
	{
		memset(strKey, '\0', 5);
		sprintf_s(strKey, "\n%d\n", i);
		fwrite(strKey, sizeof(char), strnlen_s(strKey,6), fpOutputFile);
		for (int j = 0; j < nSize; j++)
		{
			if (strCipheredText[j] >= 65 && strCipheredText[j] <= 90)
			{
				nTemp = strCipheredText[j] - i;
				if (nTemp < 65)
				{
					nTemp = 26 + nTemp;
				}
				strPlainText[j] = nTemp;
			}
			else if (strCipheredText[j] >= 97 && strCipheredText[j] <= 122 )
			{
				nTemp = strCipheredText[j] - i;
				if (nTemp < 97)
				{
					nTemp = 26 + nTemp;
				}
				strPlainText[j] = nTemp;

			}
			else
			{
				strPlainText[j] = strCipheredText[j];
			}
		}
		fwrite(strPlainText, sizeof(char), strnlen_s(strPlainText, nSize), fpOutputFile);
		memset(strPlainText, '\0', nSize+1);
	}
	fclose(fpOutputFile);
	fpOutputFile = 0;
	return nReturnValue;
}

/*
Name: AtbashCipher_CryptoAnalysis
Description: This function will do a crypt analysis of Atbash cipher. This is try to get the plain text from the cipher text
Parameter: strCipherText-> This is the encrypted text which needs to be broken
		   nSize -> Size of the message which needs to be broken
ReturnValue: 0 for success else Error code.
*/
int AtbashCipher_CryptAnalysis(char* strCipherText, int nSize)
{
	int nReturnValue = 0;
	char* strPlainText = NULL;
	FILE* fpOutput = NULL;

	if (nSize < 0 || strCipherText == NULL)
		return ERR_INVALIDINPUTPARAMETERS;

	strPlainText = (char*)malloc(sizeof(char)*nSize);
	if (strPlainText == NULL)
	{
		return ERR_MEMORYALLOCAIONFAILED;
	}

	for (int i = 0; i < nSize; i++)
	{
		if (strCipherText[i] >= 65 && strCipherText[i] <= 90)
		{
			strPlainText[i] = 90 - (strCipherText[i] - 65);
		}
		else if (strCipherText[i] >= 97 && strCipherText[i] <= 122)
		{
			strPlainText[i] = 122 - (strCipherText[i] - 97);
		}
	}
	

	fopen_s(&fpOutput, "AtbashCipher_PossiblePlainText.txt", "w");
	if (fpOutput == NULL)
	{
		free(strPlainText);
		strPlainText = NULL;
		return ERR_FILEOPENERROR;
	}

	fprintf_s(fpOutput, "CIPHER TEXT:%s\n", strCipherText);
	fprintf_s(fpOutput, "PLAIN TEXT:%s\n", strPlainText);

	fclose(fpOutput);
	fpOutput = NULL;

	free(strPlainText);
	strPlainText = NULL;

	return nReturnValue;
}