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
