#include "String.h"

ostream& operator<< (ostream &out, String &s) {
	for (int i = 0; i<s.size; i++) {
		out << s.str[i];
	}

	return out;
}


int main() {

	String s;

	String si('a');
	String sii('s');
	String s3("wie gehts?");
	String s33("mir gehts gut danke");
	String s4(s3);
	String s5("hallo ");
	String s44(s33);
	s5 += s3;
	s4 += s33;
	String	s2 = s5;
	s = sii;

	cout << "Strings mit einzelnen Charactern:" << endl;
	cout << si << endl;
	cout << sii << endl;
	cout << "\nStrings mit Zeichenkette:"<< endl;	
	cout << s3 << endl;		//wie gehts
	cout << s33 << endl;
	cout << "\nStrings aus Strings:" << endl;
	cout << s4 << endl;		//wie gehts
	cout << s44 << endl;		//wie gehts
	cout << "\nStrings mit '+=':" << endl;
	cout << s5 << endl;		//hallo wie gehts?
	cout << s4 << endl;
	cout << "\nStrings mit '=':" << endl;
	cout << s2 << endl;		//hallo
	cout << s << endl;		//hallo
	cout << "\nStrings mit '[]':" << endl;
	cout << s5[3] << endl;
	cout << s4[4] << endl;

	cout << "ende" << endl;


}
