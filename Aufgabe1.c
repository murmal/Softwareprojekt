/**
* @file   aufgabe1-bit.c
* @brief  Aufgabe1 - Bit Manipulationen
*/

#include <stdio.h>
// Falls notwendig erweitern Sie die Liste der includes


/**
@brief Aufgabe1a: Vertauschen von Bytes
@param [in] short int i
@return short int

Schreiben Sie eine Funktion die das Low Byte (Bits 0-7) und
das High Byte (Bits 8-15) vertauscht.
Z.B. aus der Zahl 0x4020 wird die Zahl 0x2040.
*/

short int switchLowHighByte(short int i) {

	return ((0xFF00 & i) >> 8) | ((0x00FF & i) << 8);

}


typedef enum {
	Stop = 0,
	Start = 1,
	Finish = 5,
	Fail = 255
} Status;


typedef enum {
	One = 1,
	Fifteen = 15,
	Last = 255
} Numbers;

/**
@brief Aufgabe1b: Serialisierung von Datenstrukturen
@param [in] Status s
@param [in] Numbers n
@param [out] short int* data

Gegeben sind zwei enums. Ihre Aufgabe ist es jeweils Werte der
beiden enums in ein Datenpacket der Groesse 16Bit zu packen (serialisieren).
Werte des enums Status sollen dabei in das Low Byte und Werte
des enums Numbers sollen in das High Byte gepackt werden.
*/


void serialize(Status s, Numbers n, short int* data) {
	
	*data = (n << 8) | s;
	
}

/**
@brief Aufgabe1c: Deserialisierung von Datenstrukturen
@param [in] short int data
@param [out] Status* s
@param [out] Numbers* n

Schreiben Sie eine Funktion die Werte der enums Status und Number
aus einem 16Bit Wert entpackt (deserialisiert).
Wir nehmen an, dass die enum Werte mittels der serialize Funktion
verpackt wurden.
*/

void deserialize(short int data, Status* s, Numbers* n) {
	
	
	
	*s = (Status)((unsigned short int)data & 0x00FF);
	*n = (Numbers) ((unsigned short int)(data & 0xFF00) >> 8);
	

	

}


enum TestEnum {
	OK,
	FAIL
};
typedef enum TestEnum Test;

Test testSD(Status s, Numbers n) {
	Test t;
	short int data;
	Status s2;
	Numbers n2;
	printf("vor dem serializie/deserialize: \n status: %x\n number %x \n", s, n);

	// Test execution
	serialize(s, n, &data);
	deserialize(data, &s2, &n2);

	printf("nach dem serializie/deserialize: \n status: %x\n number %x \n\n", s2, n2);



	if (s2 == s && n2 == n) {
		t = OK;
	}
	else {
		t = FAIL;
	}
	return t;
}

Test testLowHigh(short int i) {
	Test t;
	printf("originale zahl lautet %x \n", i);
	

	short int z = switchLowHighByte(i);
	

	printf("geswitches zahl lautet %x \n\n", z);


	if (i == switchLowHighByte(switchLowHighByte(i)))
		t = OK;
	else
		t = FAIL;

	return t;
}

int main() {
	

	short int zahl = 0x2040;
	

	testLowHigh(zahl);
	testSD( Fail, One);
	testSD(Finish, Fifteen);
	testSD(Fail, Last);
	printf("finish");
	printf("");
}



