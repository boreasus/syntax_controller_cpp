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


bool control(char c) {
	bool controller = false;
	if (c == ' ') controller = true;
	if (c == '\n') controller = true;
	if (c == '(') controller = true;
	return controller;
}



using namespace std;
namespace fs = std::filesystem;
using std::filesystem::directory_iterator;



int main(void)
{

	string line, current_file;
	ofstream result_file{ "total.cpp" };
	string current_path = fs::current_path().string();
	//the path main.cpp working on


	cout << "Current path is : " << current_path << endl;


	//pth variable access every file in the folder 
	for (const auto& file : directory_iterator(current_path))
	{
		current_file = file.path().string();
		ifstream working_file(current_file.c_str());
		if (current_file.substr(current_file.length() - 4) == ".cpp") {
			if (current_file.substr(current_file.length() - 8) == "main.cpp")
				continue;
			if (current_file.substr(current_file.length() - 9) == "total.cpp")
				continue;

			if (working_file && result_file)
			{


				cout << file.path().string() << " OPENED" << endl;
				module_counter++;
				while (getline(working_file, line))
				{

					result_file << line << "\n";
				}

			}
			else
			{
				cout << file.path().string() << " COULDN'T OPEN" << endl;
			}
			result_file.close();
		}



	}





	string file_name = "main.cpp";
	FILE* f = fopen(file_name.c_str(), "r+");
	char cc = '_';
	int lineCounter = 1,tempWhileLC,tempForLC,tempIfLC;

	
	for (int j = 1; j < 2; j++) {
		if (j == 1) {
			file_name = "total.cpp";
			f = fopen(file_name.c_str(), "r+");
		}




		while (!feof(f)) {
			cc = getc(f);
			//for
			if (cc == 'f') {
				cc = getc(f);
				if (cc == 'o') {
					cc = getc(f);
					if (cc == 'r') {
						tempForLC = lineCounter;
						while (true) {
							cc = getc(f);
							if (cc == '\n') lineCounter++;

							if (!control(cc)) {
								cout << "At line " << tempForLC << " there is a FOR syntax error. Missing '('" << endl;
								break;
							}

							if (cc == '(') {
								while (true) {
									cc = getc(f);
									if (cc == '\n') lineCounter++;
									if (cc == '\n' || cc == EOF) {
										cout << "At line " << tempForLC << " there is a FOR syntax error. Missing ')'" << endl;
										break;
									}
									else if (cc == ')') {
										break;
									}
								}
								break;
							}


						}
					}
				}
			}

			//if
			if (cc == 'i') {
				cc = getc(f);
				if (cc == 'f') {
					cout << "if has fond\n";
				}
			}



			//while

			if (cc == 'w') {
				cc = getc(f);
				if (cc == 'h') {
					cc = getc(f);
					if (cc == 'i') {
						cc = getc(f);
						if (cc == 'l') {
							cc = getc(f);
							if (cc == 'e') {
								tempWhileLC = lineCounter;
								while (true) {
									cc = getc(f);
									if (cc == '\n') lineCounter++;

									if (!control(cc)) {
										cout << "At line " << tempWhileLC << " there is a WHILE syntax error. Missing '('" << endl;
										break;
									}

									if (cc == '(') {
										while (true) {
											cc = getc(f);
											if (cc == '\n') lineCounter++;
											if (cc == '\n' || cc == EOF) {
												cout << "At line " << tempWhileLC << " there is a WHILE syntax error. Missing ')'" << endl;
												break;
											}
											else if (cc == ')') {
												break;
											}
										}
										break;
									}


								}
							}

						}
					}
				}
			}


			if (cc == '\n') lineCounter++;

		}









		if (j == 0) {
		}
		else {
		}


	}



	return 0;
}
