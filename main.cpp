#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <filesystem>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
namespace fs = std::filesystem;
using std::filesystem::directory_iterator;


int lineCounter = 1;
bool threeCharControl(char c);
void ifController(FILE* f, char c);
void forController(FILE* f, char c);
void whileController(FILE* f, char c);
void bracketController(FILE* f, char c,string s);
void squareBracketController(FILE* f, char c);
void leximeController(FILE* f, char c);







int main()
{
	string line, current_file;
	int module_counter = 0;


	string file_name = "deneme.cpp";
	FILE* f = fopen(file_name.c_str(), "r+");
	char cc = '_';
	int lineCounter = 1;
	


	while (cc!=EOF) {
		cc = getc(f);
		if (cc == '\n')
			lineCounter++;
		leximeController(f, cc);
	}


	return 0;
}



void squareBracketController(FILE* f, char c) {
	int currentLine = lineCounter;
	while (true) {
		c = getc(f);
		if (c == EOF) {
			cout << "There is a missing a '}' of which you put '{' at line " << currentLine << endl;
			break;
		}
		if (c == '}') {
			break;
		}
		leximeController(f, c);
	}
}



void bracketController(FILE* f, char c, string s) {
	int currentLine = lineCounter;
	while (true) {
		c = getc(f);
		if (c == '\n') lineCounter++;

		if (!threeCharControl(c)) {
			cout << "At line " << currentLine << " there is a " << s << " syntax error.Missing '('" << endl;
			fseek(f, -1, SEEK_CUR);
			break;
		}

		if (c == '(') {
			while (true) {
				c = getc(f);
				if (c == '\n') lineCounter++;
				if (c == '\n' || c == EOF) {
					cout << "At line " << currentLine << " there is a " << s << " syntax error. Missing ')'" << endl;
					fseek(f, -1, SEEK_CUR);
					break;
				}
				else if (c == ')') {

					break;
				}
			}
			break;
		}


	}
}


bool threeCharControl(char c) {
	bool controller = false;
	if (c == ' ') controller = true;
	if (c == '\n') controller = true;
	if (c == '(') controller = true;
	return controller;
}



void leximeController(FILE* f, char c) {
	if (c == '#') {
		while (c != '\n')c = getc(f);
	}
	if (c == '/') {
		c = getc(f);
		if (c == '/') {
			while (c != '\n')c = getc(f);
		}
	}
	if (c == '\n')
		lineCounter++;
	if (c == 'i')
		ifController(f, c);
	if (c == 'w')
		whileController(f, c);
	if (c == 'f')
		forController(f, c);
	if (c == '{')
		squareBracketController(f, c);

}


void forController(FILE* f, char c) {
	c = getc(f);
	if (c == '\n')
		lineCounter++;
	if (c == 'o') {
		c = getc(f);
		if (c == '\n')
			lineCounter++;
		if (c == 'r') {
			c = getc(f);
			if (c > 65 && c < 122) {
				return;
			}
			fseek(f, -1, SEEK_CUR);
			bracketController(f, c, "FOR");
		}
	}
}


void whileController(FILE* f, char c) {
	c = getc(f);
	if (c == '\n')
		lineCounter++;
	if (c == 'h') {
		c = getc(f);
		if (c == '\n')
			lineCounter++;
		if (c == 'i') {
			c = getc(f);
			if (c == '\n')
				lineCounter++;
			if (c == 'l') {
				c = getc(f);
				if (c == '\n')
					lineCounter++;
				if (c == 'e') {
					c = getc(f);
					if (c > 65 && c < 122) {
						return;
					}
					fseek(f, -1, SEEK_CUR);
					bracketController(f, c, "WHILE");
				}
			}
		}
	}
}

void ifController(FILE* f, char c) {
	c = getc(f);
	if (c == '\n')
		lineCounter++;
	if (c == 'f') {
		c = getc(f);
		if (c > 65 && c < 122) {
			return;
		}
		fseek(f, -1, SEEK_CUR);
		bracketController(f, c, "IF");
	}
}

