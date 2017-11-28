#include <stdio.h>
#include <stdint.h>
#include <string.h>

int16_t counter(char *input) {


	int16_t counter = 0;


	while (*input != '\0') {

		counter++;
		input++;
	}

	return counter;
}

char* extract(char* input) {

	char* adresse = input;
	int16_t laengeInput = counter(input);

	while (laengeInput != 0) {

		if ((*(adresse + laengeInput) == ':') && (*(adresse + laengeInput - 1) == ':')) {
			

				return (adresse + laengeInput + 1);

		}
		else { laengeInput--; }
	}

	if (laengeInput == 0) {
		return input;
	}
}

void extract2(char* input, char** output) {
	char* adresse = input;
	output = input;
	int16_t laengeInput = counter(input);

	while (laengeInput != 0) {

		if ((*(adresse + laengeInput) == ':') && (*(adresse + laengeInput - 1) == ':')) {

			output = adresse + laengeInput + 1;
			

		}
		else { laengeInput--; }
	}

	if (laengeInput == 0) {
		
	}

}

typedef enum {
	OK,
	FAIL
} Test;

Test testExtract(char* input, char* expected) {
	Test t;

	if (strcmp( extract(input), expected) == 0) {
		t = OK;
	}
	else {
		t = FAIL;
	}
	return t;
}


typedef struct {
	char* input;
	char* expected;
} TestCase;


void runTests(int no, TestCase test[]) {
	Test t;
	int i;

	for (i = 0; i < no; i++) {
		printf("Test %d: ", i);
		t = testExtract(test[i].input, test[i].expected);
		if (OK == t)
			printf("OK \n");
		if (FAIL == t)
			printf("FAIL \n");
	}
}


	int16_t main() {

		const int testNo = 7;
		TestCase tests[7] = {
			{ "", "" },
			{ "Hallo", "Hallo" },
			{ "Hallo::wie::gehts", "gehts" },
			{ "::", "" },
			{ "::jemand:zuhause::", "" },

			{ "Hier:Sollte::das:zuruckgegeben:werden", "das:zuruckgegeben:werden" },
			{ " Hallo::::asdf", "asdf" },

		};

		runTests(testNo, tests);





		char i[] = "Hallo";
		char q[] = "Hallo::wie::gehts";
		char a[] = "::";
		char k[] = "::jemand:zuhause::";
		char r[] = "Hier:Sollte::das:zuruckgegeben:werden";
		char t[] = "Hallo::::asdf";
		char t2[] = "Hallo::::asdf";
		char r2[] = "Hier:Sollte::das:zuruckgegeben:werden";

		

		char* test = extract(i);
		char* test1 = extract(q);
		char* test2 = extract(a);
		char* test3 = extract(k);
		char* test4 = extract(r);
		char* test5 = extract(t);

		printf("Eingabe: %s \nAusgabe: %s\n\n", i, extract(i));
		printf("Eingabe: %s \nAusgabe: %s\n\n", q, extract(q));
		printf("Eingabe: %s \nAusgabe: %s\n\n", a, extract(a));
		printf("Eingabe: %s \nAusgabe: %s\n\n", k, extract(k));
		printf("Eingabe: %s \nAusgabe: %s\n\n", r, extract(r));
		printf("Eingabe: %s \nAusgabe: %s\n\n", t, extract(t));

		printf("");
	}
