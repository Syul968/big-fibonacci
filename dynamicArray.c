#include <stdio.h>
#include <stdlib.h>

int n;
int top;
int *arr;

void printArr(const int *arr) {
	printf("ARR SIZE %d\n", n);
	printf("TOP INDEX: %d\n", top);
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void printMenu() {
	printf("CHOOSE OPTION\n");
	printf("1. Add element\n");
	printf("2. Delete element (last)\n");
	printf("3. Print array\n");
	printf("0. Exit\n");
}

void addObject(int a) {
	if(++top >= n) {
		arr = realloc(arr, top * sizeof(int));
		n++;
	}
	
	arr[top] = a;
}

void deleteObject() {
	if(top < 0) {
		printf("YOU CANNOT DELETE FROM EMPTY ARRAY!\n");
		return;
	}
	
	arr[top] = 0;
	if(top == n - 1)
		arr = realloc(arr, --n * sizeof(int));
	top--;
}

int main(int argc, char *argv[]) {
	printf("Array size: ");
	scanf("%d", &n);
	arr = (int *)calloc(n, sizeof(int));
	top = -1;
	
	int selection;
	int element;
	printMenu();
	while(scanf("%d", &selection)) {
		switch(selection) {
			case 0:
				exit(0);
			case 1:
				printf("Element: ");
				scanf("%d", &element);
				addObject(element);
				break;
			case 2:
				deleteObject();
				break;
			case 3:
				printArr(arr);
				break;
		}
		printMenu();
	}
}