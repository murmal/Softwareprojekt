#include <stdio.h>

int counter(char *input){
	

	int counter = 0;


	while(*input != '\0'){

		counter++;
		input++;
	}

	return counter;
}

char* extract(char* input){

	int adresse = (int) input;
	int laengeInput = counter(input);

	while (laengeInput != 0){
		
		if (*(adresse+laengeInput) == ':'){
			if (*(input+laengeInput-1) == ':'){

				return (input+2);

				

			}
		}
		else{ laengeInput--;}

		
	}

	if (laengeInput == 0){

		return input;



}


int main(){

	char i[] = "Hallo";

	int x = counter(i);
	printf("");
}
