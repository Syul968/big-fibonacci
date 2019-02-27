#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pet{
    char *animal;
    char *name;
    int age;
};

int insert(char *animal, char *name, int age, struct Pet **pta, int *size){
    *pta = (struct Pet *) realloc(*pta, sizeof(struct Pet) * ++(*size));

    if(!(*pta)){
        return 0;
    }

    struct Pet *ptp = *pta + *size - 1;
    ptp->animal = animal;
    ptp->name = name;
    ptp->age = age;

    return 1;
}

int delete(int i, struct Pet **pta, int *size){
    if(i < 0 || i >= *size){
        return 0;
    }

    free((*pta + i)->animal);
    free((*pta + i)->name);

    if(*size == 1){
        free(*pta);
        *pta = NULL;
        (*size)--;
    }else{
        for(i; i < *size - 1; i++){
            *(*pta + i) = *(*pta + i + 1);
        }

        *pta = (struct Pet *) realloc(*pta, sizeof(struct Pet) * --(*size));
        if(!(*pta)){
            return 0;
        }
    }

    return 1;
}

void print(struct Pet *pets, int size){
    if(size){
        for(int i = 0; i < size; i++){
            printf("Pet %d:\n\tAnimal: %s\n\tName: %s\n\tAge: %d\n", i, (pets + i)->animal, (pets + i)->name, (pets + i)->age);
        }
    }else{
        printf("There are no pets\n");
    }
}

char* stringInput(char tag[]){
    char* string = malloc(sizeof(char) * 1026);
    printf("Enter %s:\n", tag);
    fgets(string, 1026, stdin);
    strtok(string, "\n");
    string = realloc(string, sizeof(char) * (strlen(string) + 1));

    return string;
}

int intInput(char tag[]){
	int number;
	printf("Enter %s:\n", tag);
	scanf("%d", &number);
	fgetc(stdin);

	return number;
}

void clearScreen(){
    for(int i = 0; i < 50; i++){
        printf("\n");
    }
}

int main(){
    struct Pet *pets = NULL;
    int size = 0;

    int choice = 0;
    do{
        clearScreen();
        printf("Menu:\n0. Exit\n1. Insert pet\n2. Delete pet\n3. Print array\n\n");
        choice = intInput("an option");

        clearScreen();
        switch(choice){
            case 0:
                break;
            case 1:
                if(!insert(stringInput("the animal"), stringInput("the name"), intInput("the age"), &pets, &size)){
                    printf("Error inserting pet\n");
                }
                break;
            case 2:
                if(!delete(intInput("the index of the pet to delete"), &pets, &size)){
                    printf("Error deleting pet or non existent index\n");
                }
                break;
            case 3:
                print(pets, size);
                break;
            default:
                printf("Enter a valid option\n");
        }

        printf("\nPress enter to continue");
    	fgetc(stdin);
    }while(choice);
}
