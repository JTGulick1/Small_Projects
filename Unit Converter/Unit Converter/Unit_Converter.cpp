#include <iostream>
#include <math.h>
#include <string>


using namespace std; //Convert everything to a medium then convert the medium to everything in the section (eg: 12 cm  -> inches -> everthing)

void Conversion(float con, int section) { // con == medium of each section
	string ext;

	cout << "\n\n";
	if (section == 1) {

	}
	else if (section == 2) {

	}
	else if (section == 3) {
		cout << "Celcius: " << con << endl;
		cout << "Fahrenheight: " << con * 1.8 + 32 << endl;
		cout << "Kelvin: " << con + 273.15;
	}


	cout << "\n\n";
	cin >> ext;
}

void Distance() { // WIP

}

void Weight() { // WIP

}

void Temp() { //con == Cel
	system("cls");
	string help = "";
	cout << "What unit do you have\n(1) Fahrenheight\n(2) Celsius\n(3) Kelvin\n";
	cin >> help;
	if (help == "1") {
		cout << "How Much?\n";
		cin >> help;
		float C = (stof(help) - 32) * 0.55555555556;
		Conversion(C, 3);
	}
	else if (help == "2") {
		cout << "How Much?\n";
		cin >> help;
		Conversion(stof(help), 3);
	}
	else if (help == "3") {
		cout << "How Much?\n";
		cin >> help;
		float C = (stof(help) - 273.15);
		Conversion(C, 3);
	}
}

int main() {

	while (true) {
		system("cls");
		cout << "Welcome to the Unit Converter" << endl;
		cout << "(1) Distance\n(2) Weight\n(3) Tempature\n(4) Exit Application";
		string choice = "";
		cin >> choice;
		if (choice == "1") {
			Distance();
		}
		else if (choice == "2") {
			Weight();
		}
		else if (choice == "3") {
			Temp();
		}
		else if (choice == "4") {
			break;
		}
	}

	return -1;
}