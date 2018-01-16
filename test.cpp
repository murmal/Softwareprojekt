// Main fuer Teilaufgabe 1
// Bitte weitere Testfaelle hinzufuegen.


#include "RE.h"
#include <iostream>

using namespace std;

int main() {
	bool q;
	// phi + c
	RE* r3 = new Alt(new Phi(), new Ch('c'));

	// c + phi
	RE* r4 = new Alt(new Ch('c'), new Phi());

	cout << r3->pretty() << endl;
	
	cout << r3->simp()->pretty() << endl;
	 q = orakel(r3, r3->simp(), "c");
	cout << "String c: " << q << endl;
	q = orakel(r3, r3->simp(), "b");
	cout << "String a: " << q << endl;


	// c**
	RE* r5 = new Star(new Star(new Ch('c')));

	cout << r5->pretty() << endl;
	cout << r5->simp()->pretty() << endl;
	q = orakel(r5, r5->simp(), "c");
	cout << q << endl;

	RE* ab = new Conc(new Ch('a'), new Star(new Ch('b')));
	RE* a = new Ch('a');

	q = orakel(ab, a, "abbb");
	cout << q << endl;

	// phi*
	RE* r6 = new Star(new Phi());

	cout << r6->pretty() << endl;
	cout << r6->simp()->pretty() << endl;

	// (phi + c) + c**
	RE* r7 = new Alt(r3, r5);

	cout << r7->pretty() << endl;
	// exhaustively apply simplifications
	cout << simpFix(r7)->pretty() << endl;






}