#include "String.h"

ostream& operator<< (ostream &out, String &s) {
	for (int i = 0; i<s.size; i++) {
		out << s.str[i];
	}

	return out;
}


int main() {

	String s;
	String s2('H');
	String s3("hallo");
	String s4(s3);
	String s5("peeeeeeeenis");

	s5 += s3;
	s2 = s5;

	cout << s5 << endl;		//hallo
	cout << s2 << endl;		//peeeeeenis
	cout << s3 << endl;		//hallo
	cout << s4 << endl;		//hallo
	cout << s4[4];


}