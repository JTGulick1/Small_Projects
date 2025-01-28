#include <iostream>
#include <stack>
#include <string>

using namespace std;

void Calculator() {
	stack<float> stk;
	stack<char> equ;
	string equation = "";
	bool iCheck = false;
	while (true) {
		std::cout << "\nRules: \nPlease Add No Spaces To Equation\nNo Alpha\nPlease Input Your Equation: ";
		cin >> equation;
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

	while (true) {
		string num = "";
		int pre = 0; // WIP
		int exp = 0; // WIP
		int md = 0; // mult or div
		int as = 0; // add or subtr
		for (char i : equation) { 
			if (isdigit(i) >= 1) {
				num += i;
			}
			else if(i == '*' || i == '/')
			{
				if (md >= 1) {
					char temp = equ.top();
					int first = stk.top();
					stk.pop();
					equ.pop();
					if (temp == '*') {
						num = to_string(first * stof(num));
						md--;
					}
					else if (temp == '/') {
						num = to_string(first / stof(num));
						md--;
					}
					
				}
				md++;
				stk.push(stof(num));
				equ.push(i);
				num = "";
			}
			else if (i == '+' || i == '-') {
				if (md >= 1) {
					char temp = equ.top();
					float first = stk.top();
					stk.pop();
					equ.pop();
					if (temp == '*') {
						num = to_string(first * stof(num));
						md--;
					}
					else if (temp == '/') {
						num = to_string(first / stof(num));
						md--;
					}
					
				}
				else if (as >= 1) {
					char temp = equ.top();
					float first = stk.top();
					stk.pop();
					equ.pop();
					if (temp == '+') {
						num = to_string(first + stof(num));
						as--;
					}
					else if (temp == '-') {
						num = to_string(first - stof(num));
						as--;
					}
				}

				as++;
				equ.push(i);
				stk.push(stof(num));
				num = "";
			}
		}
		if (pre == true) {
			std::cout << "Invalid Equation" << endl;
			break;
		}


		if (md >= 1) {
			char temp = equ.top();
			float first = stk.top();
			stk.pop();
			equ.pop();
			if (temp == '*') {
				num = to_string(first * stof(num));
			}
			else if (temp == '/') {
				num = to_string(first / stof(num));
			}
			md = false;
			stk.push(stof(num));
		}


		if (as >= 1) {
			char temp = equ.top();
			float first = stk.top();
			stk.pop();
			num = to_string(stk.top());
			stk.pop();
			equ.pop();
			if (temp == '+') {
				num = to_string(first + stof(num));
			}
			else if (temp == '-') {
				num = to_string(first - stof(num));
			}
			md = false;
			stk.push(stof(num));
		}

		if (equ.empty() == true) {
			break;
		}
		else { //rewrite equation and run it agian
			equation.clear();
			while (stk.empty() == false || equ.empty() == false) {
				std::cout << equation << "    ";
				equation += to_string(stk.top());
				if (equ.empty() != false) {
					equation += equ.top();
					equ.pop();
				}
				stk.pop();
			}
		}
	}

	std::cout << "\n\nYour Answer Is: " << stk.top() << endl;
	std::cout << "Another Equation? (y/n)  ";
	cin >> equation;
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