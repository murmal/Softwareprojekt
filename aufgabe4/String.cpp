#include <iostream>
using namespace std;

#include "String.h"


String::String() {
	size = 0;
	str = new char[1];
	str[0] = '\0';
}


String::String(char c) {
	size = 1;
	str = new char[2];
	str[0] = c;
	str[1] = '\0';
}

String::String(const char *s) {
	
	size = 0;
	const char* p = s;

	while (*p != '\0') {
		size++;
		p++;
	}

	str = new char[size+1];

	for (int i = 0; i <= size; i++) {
		str[i] = *s;
		s++;
	}
	

}

String::String(const String& s) {
	size = s.size;

	str = new char[size + 1];

	for (int i = 0; i <= size; i++) {
		str[i] = s.str[i];
	}
}

String::~String() { delete[] str; }



char& String::operator[](int index) {
	
	char k = '0';
	if (index < size) {
		return str[index];
	}

	else {
		return k;
	}
	
}

String& String::operator=(String& s3) {
	
	
	if (this != &s3) {


		String s1(s3);

		delete[] str;

		str = new char[s3.size];
		size = s3.size;

		for (int i = 0; i <= size; i++) {
			str[i] = s1.str[i];
		}

	}

	return *this;

}


String& String::operator+=(String& s) {
	
	
	
	for (int i = 0; i <= s.size; i++) {
		this->str[this->size + i] = s.str[i];
	}
	this->size += s.size;
	return *this;
	

}
