#include <iostream>
#include <queue>
#include <string>

using namespace std;

string Equation(string equ) {
	string updated = "";
	string curr = "";
	string::size_type n;
	queue<float> numbers;
	queue<char> forms;
	bool ex = false;
	bool md = false;
	bool ad = false;

	n = equ.find('(');
	if (string::npos != n) {

		string::size_type temp;
		temp = equ.find(')');
		string newEqu = equ.substr(n + 1, temp - 1); // this might or might not work
		newEqu.erase(newEqu.begin() + newEqu.size() - 1, newEqu.end() - 1);
		string beg = equ.substr(0, n);
		string end = equ.substr(temp + 1, equ.size());
		cout << newEqu << endl;
		newEqu = Equation(newEqu);

		if (beg.size() >= 1 && end.size() >= 1) {
			equ = beg + '*' + Equation(newEqu) + '*' + end;
		}
		else if (beg.size() >= 1 && end.size() <= 1) {
			equ = beg + '*' + Equation(newEqu);
		}
		else if (beg.size() <= 1 && end.size() >= 1) {
			equ = Equation(newEqu) + '*' + end;
		}
		else {
			equ = Equation(newEqu);
		}
		cout << equ << endl;
	}

	n = equ.find('^');
	if (string::npos != n) {
		ex = true;
	}
	if (n != equ.find('*') || n != equ.find('/')) {
		md = true;
	}
	else if (n != equ.find('+') || n != equ.find('-')) {
		ad = true;
	}

	if (ex == false && md == false && ad == false) {
		return equ;
	}

	for (char i : equ) { 
		if (i == '(' || i == ')') {

		}
		else if (isdigit(i) >= 1 || i == '.') {
			curr += i;
		}

		else if (i == '^' && forms.size() == 0 && ex == true) {

			forms.push('^');
			numbers.push(stof(curr));
			curr = "";
		}
		else if (forms.size() == 1 && ex == true) {
			cout << numbers.front() << "   " << curr << endl;
			float temp = powf(numbers.front(), stof(curr));
			updated += to_string(temp) + i;
			curr = "";
			numbers.pop();
			forms.pop();
		}
		else if (ex == true) {
			updated += curr;
			updated += i;
			curr = "";
		}

		else if (i == '*' && forms.size() == 0 && md == true) {
			forms.push('*');
			numbers.push(stof(curr));
			curr = "";
		}
		else if (i == '/' && forms.size() == 0 && md == true)
		{
			forms.push('/');
			numbers.push(stof(curr));
			curr = "";
		}
		else if (forms.size() == 1 && md == true) {
			if (i == '*') {
				float temp = numbers.front();
				numbers.pop();
				if (forms.front() == '/') {
					numbers.push(temp / stof(curr));
					forms.pop();
					forms.push('*');
				}
				else {
					numbers.push(temp * stof(curr));
				}
				curr = "";
			}
			else if (i == '/') {
				float temp = numbers.front();
				numbers.pop();
				if (forms.front() == '*') {
					numbers.push(temp * stof(curr));
					forms.pop();
					forms.push('/');
				}
				else {
					numbers.push(temp / stof(curr));
				}
				curr = "";
			}
			else {
				float temp = numbers.front();
				numbers.pop();
				if (forms.front() == '/') {
					updated += to_string(temp / stof(curr));
				}
				else {
					updated += to_string(temp * stof(curr));
				}
				forms.pop();
				updated += i;
				curr = "";
			}

		}
		else if (md == true) {
			if (forms.size() == 1) {
				if (forms.front() == '*' && md == true) {
					updated += to_string(numbers.front() * stof(curr));
				}
				else if (forms.front() == '/' && md == true) {
					updated += to_string(numbers.front() / stof(curr));
				}
				updated += i;
				numbers.pop();
				forms.pop();
			}
			else {
				updated += curr;
				updated += i;
			}
			curr = "";
		}



		else if (i == '+' && forms.size() == 0 && ad == true) {
			forms.push('+');
			numbers.push(stof(curr));
			curr = "";
		}
		else if (i == '-' && forms.size() == 0 && ad == true)
		{
			forms.push('-');
			numbers.push(stof(curr));
			curr = "";
		}
		else if (forms.size() == 1 && ad == true) {
			if (i == '+') {
				float temp = numbers.front();
				numbers.pop();
				if (forms.front() == '-') {
					numbers.push(temp - stof(curr));
					forms.pop();
					forms.push('+');
				}
				else {
					numbers.push(temp + stof(curr));
				}
				curr = "";
			}
			else if (i == '-') {
				float temp = numbers.front();
				numbers.pop();
				if (forms.front() == '+') {
					numbers.push(temp + stof(curr));
					forms.pop();
					forms.push('-');
				}
				else {
					numbers.push(temp - stof(curr));
				}
				curr = "";
			}
		}
		else if (ad == true) {
			if (forms.size() == 1) {
				if (forms.front() == '+' && md == true) {
					updated += to_string(numbers.front() + stof(curr));
				}
				else if (forms.front() == '-' && md == true) {
					updated += to_string(numbers.front() - stof(curr));
				}
				updated += i;
				numbers.pop();
				forms.pop();
			}
			else {
				updated += curr;
				updated += i;
			}
			curr = "";
		}
	}
	if (forms.size() == 1) {
		//cout << numbers.front() << forms.front() << "   " << curr << "    ";
		if (forms.front() == '^' && ex == true) {
			updated += to_string(powf(numbers.front(), stof(curr)));
		}
		else if (forms.front() == '*' && md == true) {
			updated += to_string(numbers.front() * stof(curr));
		}
		else if (forms.front() == '/' && md == true) {
			updated += to_string(numbers.front() / stof(curr));
		}
		else if (forms.front() == '+' && ad == true) {
			updated += to_string(numbers.front() + stof(curr));
		}
		else if (forms.front() == '-' && ad == true) {
			updated += to_string(numbers.front() - stof(curr));
		}
	}
	else {
		updated += curr;
	}

	return updated;
};

void Calculator() {
	string equation = "";
	bool iCheck = false;
	while (true) {
		std::cout << "\nRules: \nPlease Add No Spaces To Equation\nNo Alpha\nPlease Input Your Equation: ";
		std::cin >> equation;
		//check if the equation is valid
		for (char i : equation) {
			if (isalpha(i) >= 1)
			{
				std::cout << "Equation is Invalid" << endl;
				iCheck = true;
			}
		}
		if (iCheck == false) {
			break;
		}
		else {
			iCheck = false;
		}
	}

	//Since the equation is valid we do pemdas
	int i = 0;
	while (i < 10) {
		equation = Equation(equation);
		cout << equation << endl;
		i++;
	}

	std::cout << "\n\nYour Answer Is: " << equation << "\n" << endl;
	std::cout << "Another Equation? (y/n)  ";
	std::cin >> equation;
	if (equation == "y") {
		Calculator();
		return;
	}
	return;
};


int main() {
	Calculator();
	return 0;
}