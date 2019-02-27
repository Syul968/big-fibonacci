#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 80

struct pet {
	char *animal;
	char *name;
	int age;
};

int n;
int top = 0;
struct pet *pets;

void initArray(const int size) {
	n = size;
	pets = (struct pet *)calloc(n, sizeof(struct pet));
}

void printPet(const struct pet pet) {
	printf("Animal: %s\n", pet.animal);
	printf("Name: %s\n", pet.name);
	printf("Age: %d\n", pet.age);
}

void printPetCompact(const struct pet pet) {
	printf("{ %s, %s, %d }\n", pet.animal, pet.name, pet.age);
}

void printPets() {
	printf("%d PETS IN ARRAY\n", top);
	printf("-----------------------\n");
	for(int i = 0; i < top; i++) {
		if(i != 0)
			printf("-----------------------\n");
		printPet(pets[i]);
	}
}

void printPetsCompact() {
	printf("%d PETS IN ARRAY\n", top);
	for(int i = 0; i < top; i++) {
		printf("%3d: ", i);
		printPetCompact(pets[i]);
	}
}

void insert(char *animal, char *name, const int age) {
	if(top >= n)
		pets = realloc(pets, ++n * sizeof(struct pet));
	struct pet newPet = {animal, name, age};
	pets[top++] = newPet;
}

void deleteLast() {
	if(top <= 0) {
		printf("YOU CANNOT DELETE FROM AN EMPTY ARRAY!\n");
		return;
	}
	
	free(pets[top - 1].animal);
	free(pets[top - 1].name);
	
	if(top >= n)
		pets = realloc(pets, --n * sizeof(struct pet));
	
	top--;
}

void printMenu() {
	printf("CHOOSE OPTION\n");
	printf("1. Add pet\n");
	printf("2. Delete last pet\n");
	printf("3. Show pets\n");
	printf("0. Exit\n");
}

int main(int argc, char *argv[]) {
	initArray(5);
	short selection;
	char *animal;
	char *name;
	int age;
	
	do {
		printMenu();
		scanf("%hd", &selection);
		
		switch(selection) {
			case 0:
				printf("Killing all pets...\n");
				printf("Cleaning up...\n");
				printf("DONE!\n");
				exit(0);
			case 1:
				printf("Animal: ");
				animal = calloc(BUFFER_SIZE, sizeof(char));
				scanf("%s", animal);
				printf("Name: ");
				name = calloc(BUFFER_SIZE, sizeof(char));
				scanf("%s", name);
				printf("Age: ");
				scanf("%d", &age);
				insert(animal, name, age);
				break;
			case 2:
				deleteLast();
				break;
			case 3:
				printPetsCompact();
				break;
			default:
				printf("NOT AN OPTION\n");
				continue;
		}
	} while(selection != 0);
}