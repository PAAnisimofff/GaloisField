#include <iostream>
#include "GaloisField.h"
#include "GaloisFieldElement.h"
#include "GaloisFieldPolynomial.h"

/*
p(x) = 1x^8+1x^7+0x^6+0x^5+0x^4+0x^3+1x^2+1x^1+1x^0
1    1    0    0    0    0    1    1    1
*/


/*
поле Галуа типа GF(2^8)
*/


int i = 0;
int j = 0;

char S[256];

void rc4_init(unsigned const char* key, unsigned int key_length)
{
	//unsigned char temp;

	for (i = 0; i != 256; ++i)
		S[i] = i;

	for (i = j = 0; i != 256; ++i)
	{
		j = (j + key[i % key_length] + S[i]) % 256;
	/*	temp = S[i];
		S[i] = S[j];
		S[j] = temp;*/
		std::swap(S[i], S[j]);
	}

	i = j = 0;
}

/* Вывод одного псевдослучайного байта */
unsigned char rc4_output()
{
	unsigned char temp;

	i = (i + 1) % 256;
	j = (j + S[i]) % 256;

	temp = S[j];
	S[j] = S[i];
	S[i] = temp;

	return S[(temp + S[j]) % 256];
}


int main()
{
	unsigned char *k = new unsigned char[128];
	for (int i = 0; i < 128; i++)
		k[i] = '1';
	rc4_init(k, 128);
	std::cout << rc4_output() << std::endl;
	//unsigned int poly[9] = { 1,1,1,0,0,0,0,1,0 };
	//GaloisField gf(8, poly);


	//GaloisFieldElement element1(&gf, 1);
	//GaloisFieldElement element2(&gf, 2);
	//GaloisFieldElement element3;

	//element3 = element1 / element2; // exponentiation

	//std::cout << element1;
	//std::cout << std::endl;
	system("pause");
	return 0;
}