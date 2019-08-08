#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<fstream>
#include<cctype>
using namespace std;

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int count_t = 0, count_w = 0, symb=0;
	char S;
	int count_s, sentensss=0;
	string fname, text;
	cout << "Name of file:" << endl;
	cin >> fname;
	cout << "Count of sent:" << endl;
	cin >> count_s;

	ifstream f(fname);
	while (!f.eof())
	{
		f.get(S);
		text = text + S;
	}
	f.close();
	text[text.length() - 1] = NULL;


	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ')count_t++;
		if (text[i] == '.')sentensss++;
	}
	cout <<"Total number of sentences: "<< sentensss << endl;
	string word = ".", text_out = "";
	string *text_mass = new string[count_t + 1];
	string word_mass[10000];
	int j = 0;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') {
			j++;
		}
		else {
			text_mass[j] = text_mass[j] + text[i];
		}
	}

	while (true) {

		for (int m = 0; m < count_s; m++) {
			do {
				for (int i = 0; i < count_t; i++) {
					if (text_mass[i] == word) {
						word_mass[count_w] = text_mass[i + 1];
						count_w++;
					}
				}
				if (count_w == 0) { word = '.'; }
				else {
					word = word_mass[rand() % count_w];
				}
				count_w = 0;
				text_out = text_out + word + " ";
			} while (word != ".");
			cout << text_out << endl;
			text_out = "";
		}
		system("pause>null");
	}
	return 0;
}