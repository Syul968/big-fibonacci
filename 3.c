#include <stdio.h>
#include "int128bit.h"

struct int128bit fib(int n){
    struct int128bit fi;

    if(n < 2){
        setValues(&fi, 0, n);
        return fi;
    }

    struct int128bit f0;
    setValues(&f0, 0, 0);
    struct int128bit f1;
    setValues(&f1, 0, 1);
    setValues(&fi, 0, 0);

	for(int i = 2; i <= n; i++){
		fi = add(f0, f1);
		f0 = f1;
		f1 = fi;
	}

    return fi;
}

int main(){
    int choice;

    do{
        printf("\nEnter an option:\n0. Exit\n1. Get Fibonacci number\n\n");
        scanf("%d", &choice);

        switch(choice){
            case 0:
                break;
            case 1:
                printf("Enter the position for the Fibonacci number: \n");
                int n;
                scanf("%d", &n);
                printf("Fib %d = %s\n", n, toString(fib(n)));
                break;
            default:
                printf("Enter a valid choice\n");
        }
    }while(choice);
}
