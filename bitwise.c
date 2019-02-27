#include <stdio.h>
#include <stdlib.h>

typedef struct bignum {
	int bytes;
	char *num;
} bignum;

int max(const int a, const int b) {
	return (a > b) ? a : b;
}

int min(const int a, const int b) {
	return (a < b) ? a : b;
}

void printCharBinary(const char c) {
	for(int i = 1; i <= 8; i++)
		printf("%d", (c >> (8 - i)) & 1);
}

void printBignum(const bignum bignum) {
	for(int i = 1; i <= bignum.bytes; i++)
		printCharBinary(bignum.num[bignum.bytes - i]);
	printf("\n");
}

bignum and(const bignum a, const bignum b) {
	bignum result;
	result.bytes = max(a.bytes, b.bytes);
	result.num = (char *)calloc(result.bytes, sizeof(char));
	int minBytes = min(a.bytes, b.bytes);
	
	int i;
	for(i = 0; i < minBytes; i++)
		result.num[i] = a.num[i] & b.num[i];
	while(i++ < result.bytes)
		result.num[i] = 0;
	
	return result;
}

bignum or(const bignum a, const bignum b) {
	bignum result;
	result.bytes = max(a.bytes, b.bytes);
	result.num = (char *)calloc(result.bytes, sizeof(char));
	int minBytes = min(a.bytes, b.bytes);
	
	int i;
	for(i = 0; i < minBytes; i++)
		result.num[i] = a.num[i] | b.num[i];
	while(i < a.bytes) {
		result.num[i] = 0 | a.num[i];
		i++;
	}
	while(i < b.bytes) {
		result.num[i] = 0 | b.num[i];
		i++;
	}
	
	return result;
}

bignum xor(const bignum a, const bignum b) {
	bignum result;
	result.bytes = max(a.bytes, b.bytes);
	result.num = (char *)calloc(result.bytes, sizeof(char));
	int minBytes = min(a.bytes, b.bytes);
	
	int i;
	for(i = 0; i < minBytes; i++)
		result.num[i] = a.num[i] ^ b.num[i];
	while(i < a.bytes) {
		result.num[i] = 0 ^ a.num[i];
		i++;
	}
	while(i < b.bytes) {
		result.num[i] = 0 ^ b.num[i];
		i++;
	}
	
	return result;
}

bignum ones(bignum a) {
	bignum result;
	result.bytes = a.bytes;
	result.num = (char *)calloc(result.bytes, sizeof(char));
	
	for(int i = 0; i < result.bytes; i++)
		result.num[i] = a.num[i] ^ 255;
	
	return result;
}

bignum sum(bignum a, bignum b) {
	bignum result;
	result.bytes = max(a.bytes, b.bytes) + 1;
	result.num = (char *)calloc(result.bytes, sizeof(char));
	int minBytes = min(a.bytes, b.bytes);
	
	char carry = 0;
	for(int i = 0; i < minBytes; i++) {
		if()
	}
}

int main(int argc, char *argv[]) {
	bignum a;
	a.bytes = 2;
	a.num = (char *)calloc(a.bytes, sizeof(char));
	a.num[0] = 18;
	a.num[1] = 7;
	
	bignum b;
	b.bytes = 1;
	b.num = (char *)calloc(b.bytes, sizeof(char));
	b.num[0] = 16;
	
	bignum c = ones(b);
	
	printBignum(c);
}