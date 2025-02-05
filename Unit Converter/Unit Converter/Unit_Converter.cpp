#include <iostream>
#include <math.h>
#include <string>


using namespace std; //Convert everything to a medium then convert the medium to everything in the section (eg: 12 cm  -> inches -> everthing)

void Conversion(float con, int section) { // con == medium of each section
	string ext;

	cout << "\n\n";
	if (section == 1) {
		cout << "Cm: " << con << endl;
		cout << "Feet: " << con / 30.48 << endl;
		cout << "Inches: " << con / 2.54 << endl;
		cout << "Meters: " << con / 100 << endl;
		cout << "Yards: " << con / 91.44 << endl;
		cout << "Miles: " << con / 160900 << endl;
		cout << "Kilometer: " << con / 100000 << endl;
		cout << "Millimeter: " << con * 10 << endl;
		cout << "Micrometer: " << con * 10000 << endl;
		cout << "Nautical Miles: " << con / 185200 << endl;
	}
	else if (section == 2) {
		cout << "lbs: " << con << endl;
		cout << "kg: " << con / 2.2046244 << endl;
		cout << "grams: " << con / 0.0022046 << endl;
		cout << "tons: " << con / 2000 << endl;
		cout << "ounce: " << con * 16 << endl;
		cout << "Imperial Ton: " << con / 2240 << endl;
		cout << "Milligram: " << con * 453600 << endl;
	}
	else if (section == 3) {
		cout << "Celcius: " << con << endl;
		cout << "Fahrenheight: " << con * 1.8 + 32 << endl;
		cout << "Kelvin: " << con + 273.15;
	}


	cout << "\n\n";
	cin >> ext;
}

void Distance() { // con = Cm
	system("cls");
	string help = "";
	cout << "What unit do you have\n(1) Cm\n(2) Feet\n(3) Inches\n(4) Meters\n(5) Yards\n(6) Miles\n(7) Kilometer\n(8) Millimeter\n(9) Micrometer\n(0) Nautical Miles\n";
	cin >> help;
	if (help == "1") { // Cm - con
		cout << "How Much?\n";
		cin >> help;
		float Cm = (stof(help));
		Conversion(Cm, 1);
	}
	else if (help == "2") { // Feet
		cout << "How Much?\n";
		cin >> help;
		float Cm = (stof(help) * 30.48);
		Conversion(Cm, 1);
	}
	else if (help == "3") { // Inches
		cout << "How Much?\n";
		cin >> help;
		float Cm = (stof(help) * 2.54);
		Conversion(Cm, 1);
	}
	else if (help == "4") { // Meters
		cout << "How Much?\n";
		cin >> help;
		float Cm = (stof(help) * 100);
		Conversion(Cm, 1);
	}
	else if (help == "5") { // Yards
		cout << "How Much?\n";
		cin >> help;
		float Cm = (stof(help) * 91.44);
		Conversion(Cm, 1);
	}
	else if (help == "6") { // Miles
		cout << "How Much?\n";
		cin >> help;
		float Cm = (stof(help) * 160900);
		Conversion(Cm, 1);
	}
	else if (help == "7") { // Km
		cout << "How Much?\n";
		cin >> help;
		float Cm = (stof(help) * 100000);
		Conversion(Cm, 1);
	}
	else if (help == "8") { // Millimeter
		cout << "How Much?\n";
		cin >> help;
		float Cm = (stof(help) / 10);
		Conversion(Cm, 1);
	}
	else if (help == "9") { // Micro Meter
		cout << "How Much?\n";
		cin >> help;
		float Cm = (stof(help) / 10000);
		Conversion(Cm, 1);
	}
	else if (help == "0") { // Nautical Miles
		cout << "How Much?\n";
		cin >> help;
		float Cm = (stof(help) * 185200);
		Conversion(Cm, 1);
	}
}

void Weight() { //con = lbs
	system("cls");
	string help = "";
	cout << "What unit do you have\n(1) lbs\n(2) kg\n(3) grams\n(4) US tons\n(5) ounce\n(6) Imperial Ton\n(7) Milligram\n";
	cin >> help;
	if (help == "1") { // lbs - con
		cout << "How Much?\n";
		cin >> help;
		float lbs = (stof(help));
		Conversion(lbs, 2);
	}
	else if (help == "2") { // kgs
		cout << "How Much?\n";
		cin >> help;
		float lbs = (stof(help) * 2.2046244f);
		Conversion(lbs, 2);
	}
	else if (help == "3") { // grams
		cout << "How Much?\n";
		cin >> help;
		float lbs = (stof(help) / 453.5920865);
		Conversion(lbs, 2);
	}
	else if (help == "4") { // tons
		cout << "How Much?\n";
		cin >> help;
		float lbs = (stof(help) * 2000);
		Conversion(lbs, 2);
	}
	else if (help == "5") { // ounce
		cout << "How Much?\n";
		cin >> help;
		float lbs = (stof(help) / 16);
		Conversion(lbs, 2);
	}
	else if (help == "6") { // troy ounce
		cout << "How Much?\n";
		cin >> help;
		float lbs = (stof(help) * 2240);
		Conversion(lbs, 2);
	}
	else if (help == "7") { // milligram
		cout << "How Much?\n";
		cin >> help;
		float lbs = (stof(help) / 453600);
		Conversion(lbs, 2);
	}
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
		cout << "(1) Distance\n(2) Weight\n(3) Tempature\n(4) Exit Application\n";
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