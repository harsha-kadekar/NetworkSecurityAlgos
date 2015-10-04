#include "CrytoAlgoTester.h"


int main(int argc, char** argv)
{
	int nReturnValue = 0;
	int nChoice = -1;

	while (nChoice != 0)
	{
		printf("\nCRYTPO ALGO TESTER\n");
		printf("\n1. Caesor cipher\n");
		printf("\nEnter your choice\n");
		scanf_s("%d", &nChoice);

		switch(nChoice)
		{
			case 1:
			{
				TestCaesorCipher();
				break;
			}
			default:
			{
				printf("\nInvalid choice please re enter correct choice\n");
				break;
			}
		}

	}
	

	return nReturnValue;
}

int TestCaesorCipher()
{
	int nReturnValue = 0;
	int nSize = 0;
	char* strPlainText = '\0';
	char* strCipherText = '\0';
	int i = 0;
	char ch = '\0';
	HMODULE hLibMod = 0;
	int* pKey = 0;
	CeaserCipher cipher = 0;
	CeaserCipher_BruteForce attacker = 0;
	CeaserDecipher decipher = 0;
	//Collect the string --> Cipher it.
	//Try to break it
	//Decipher the string
	printf("\nCaesor Cipher testing\n");

	while (nSize <= 0)
	{
		printf("Please enter the length of the text to be encrypted\n");
		scanf_s("%d", &nSize);
	}

	strPlainText = (char*)malloc(sizeof(char)*(nSize + 1));
	if (0 == strPlainText)
	{
		printf("\nError:: Memory problem\n");
		return -1;
	}

	memset(strPlainText, '\0', nSize + 1);

	while (i < nSize)
	{
		scanf_s("%c", &ch);
		if(ch != '\n' && ch != EOF)
			strPlainText[i++] = ch;
	}

	printf("PLAIN TEXT: %s\n", strPlainText);

	strCipherText = (char*)malloc(sizeof(char)*(nSize + 1));
	if (strCipherText == 0)
	{
		//Error handle it
	}

	memset(strCipherText, '\0', nSize + 1);
	
	pKey = (int*)malloc(sizeof(int));
	if (pKey == 0)
	{
		//Error handle it
	}

	*pKey = -1;

	hLibMod = LoadLibrary(L"CryptoAlgos.dll");
	if (hLibMod == 0)
	{
		//Error handle it
	}

	cipher = (CeaserCipher)GetProcAddress(hLibMod, "CeaserCipher");
	if (cipher == 0)
	{
		//Error handle it
	}

	//Sleep(60000);
	//printf("\nHook It\n");
	nReturnValue = cipher(strPlainText, nSize, strCipherText, pKey);
	if (nReturnValue != 0)
	{
		//Error handle it
	}

	printf("\nCipher Text: %s\n", strCipherText);
	printf("\nKEY used: %d\n", *pKey);

	attacker = (CeaserCipher_BruteForce)GetProcAddress(hLibMod, "CeaserCipher_BruteForce");
	if (attacker == 0)
	{
		//Error handle it
	}

	nReturnValue = attacker(strCipherText, nSize);
	if (nReturnValue != 0)
	{
		//Error handle it
	}

	decipher = (CeaserDecipher)GetProcAddress(hLibMod, "CeaserDecipher");
	if (decipher == 0)
	{
		//Error handle it
	}

	memset(strPlainText, '\0', nSize + 1);

	nReturnValue = decipher(strCipherText, nSize, strPlainText, *pKey);
	if (nReturnValue != 0)
	{
		//Error handle it
	}

	printf("Deciphered Text:%s\n", strPlainText);

	FreeLibrary(hLibMod);
	hLibMod = 0;
	free(pKey);
	pKey = NULL;
	free(strCipherText);
	strCipherText = NULL;
	free(strPlainText);
	strPlainText = NULL;

	return nReturnValue;
}