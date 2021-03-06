#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "int128bit.h"

void setValues(struct int128bit *pts, unsigned long long left, unsigned long long right){
    pts->left = left;
    pts->right = right;
}

struct int128bit add(struct int128bit x, struct int128bit y){
    struct int128bit result;
    result.left = x.left + y.left;
    result.right = x.right + y.right;

    if(result.right < x.right){
        result.left++;
    }

    return result;
}

void addBit(char **string, int *len, int carry){
    int i = *len - 1;
    do{
        int sum = (*(*string + i) - '0') * 2 + carry;
        *(*string + i) = sum % 10 + '0';
        carry = sum / 10;
    }while(i-- > 0);
    if(carry){
        (*len)++;
        *string =  realloc(*string, *len + 1);
        memmove(*string + 1, *string, *len);
        **string = carry + '0';
    }
}

struct int128bit and(struct int128bit a, struct int128bit b) {
    struct int128bit result;
    result.left = a.left & b.left;
    result.right = a.right & b.right;
    return result;
}

struct int128bit or(struct int128bit a, struct int128bit b) {
    struct int128bit result;
    result.left = a.left | b.left;
    result.right = a.right | b.right;
    return result;
}

struct int128bit xor(struct int128bit a, struct int128bit b) {
    struct int128bit result;
    result.left = a.left ^ b.left;
    result.right = a.right ^ b.right;
    return result;
}

struct int128bit ones(struct int128bit a) {
    struct int128bit result;
    unsigned long long max = 0b1111111111111111111111111111111111111111111111111111111111111111;
    result.left = a.left ^ max;
    result.right = a.right ^ max;
    return result;
}

struct int128bit twos(struct int128bit a) {
    struct int128bit onesComplement = ones(a);
    struct int128bit one;
    setValues(&one, 0, 1);
    return add(onesComplement, one);
}

struct int128bit leftShift(struct int128bit a, int n) {
    struct int128bit result;
    result.left = a.left;
    result.right = a.right;
    while(n--) {
        result.left = result.left << 1;
        result.right = result.right << 1;
        if(result.right < a.right)
            result.left++;
    }
    return result;
}

struct int128bit rightShift(struct int128bit a, int n) {
    struct int128bit result;
    result.left = a.left;
    result.right = a.right;
    int carry;
    while(n--) {
        carry = (result.left & 1);
        result.left = result.left >> 1;
        result.right = result.right >> 1;
        if(carry == 1)
            result.right += 0b1000000000000000000000000000000000000000000000000000000000000000;
    }
    
    return result;
}

char *toString(struct int128bit n){
    int len = 1;
    char *string = malloc(len + 1);
    strcpy(string, "0");

    int size = sizeof(n.left);
    for(int i = size * 8 - 1; i >= 0; i--){
         addBit(&string, &len, (n.left >> i) & 1);
    }
    for(int i = size * 8 - 1; i >= 0; i--){
        addBit(&string, &len, (n.right >> i) & 1);
    }

    return string;
}
