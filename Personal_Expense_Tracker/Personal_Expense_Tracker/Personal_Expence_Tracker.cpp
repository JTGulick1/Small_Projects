#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

struct Accounts {
public:
	int accountNum;
	string name;
	int total = 0;
	string textfile;
	vector<string> history;
	Accounts(string n, int Anum) {
		name = n;
		accountNum = Anum;
	}
	void AddFunds(int amount) {
		total += amount;

		history.push_back("Added: " + std::to_string(amount));
	}
	void expence(int amount) {
		total -= amount;
		history.push_back("Spent: " + std::to_string(amount));
	}
	void OpenHistory() {
		cout << name << endl;
		for (int i = 0; i < history.size(); i++) {
			cout << history[i] << endl;
		}
	}
	void ChangeName(string n) {
		name = n;
	}
	void SaveHistory() {

		// Save to the txt file
	}
};


void Tranfer(Accounts& acc1, Accounts& acc2, int amount) {
	acc1.expence(amount);
	acc2.AddFunds(amount);
}


vector<Accounts> OpenAccounts() { //when the application opens find the text files and create the accounts
	vector<Accounts> accounts;
	std::string line = "";
	for (int i = 1; i < 7; i++) {
		std::ifstream file(to_string(i) + ".txt");
		string name = "";
		int bal = 0;
		std::getline(file, line);
		if (line != "") {
			name = line;
		}
		std::getline(file, line);
		if (line != "") {
			bal = stoi(line);
		}
		Accounts acc = Accounts(name, i);
		acc.total = bal;
		while (std::getline(file, line)) {
			acc.history.push_back(line);
		}
		file.close();
		if (acc.name != "") {
			accounts.push_back(acc);
		}
	}
		
	return accounts;
}

void SaveAccounts(std::vector<Accounts>& accounts) {
	for (int i = 1; i < 7; i++) {
		if (accounts.size() < i) {
			std::cerr << "Skipping file " << i << ".txt: Not enough accounts.\n";
			continue;
		}

		std::ofstream file(std::to_string(i) + ".txt");
		if (!file) {
			std::cerr << "Error opening file: " << i << ".txt\n";
			continue;
		}

		file << accounts[i - 1].name << "\n";   // Save account name
		file << accounts[i - 1].total << "\n"; // Save balance

		for (const std::string& entry : accounts[i - 1].history) {
			file << entry << "\n"; // Save history
		}

		file.close();
	}
}


int main() {
	vector<Accounts> dataBase;
	dataBase = OpenAccounts();
	string choice = "";
	string choice2 = "";
	string amount = "";
	while (true) {
		cout << "Account Manager:\nPlease Select an Account: " << endl;
		for (int i = 0; i < dataBase.size(); i++) {
			cout << "(" << i + 1 << ") " << dataBase[i].name << endl;
		}
		cout << "(" << dataBase.size() + 1 << ")" << " Create New Account (Max 6 Accounts)" << endl;
		cout << "(" << dataBase.size() + 2 << ")" << " Tranfer Amount" << endl;
		cout << "(" << dataBase.size() + 3 << ")" << " Exit Application" << endl;
		cin >> choice;


		if (choice == to_string(dataBase.size() + 1) && dataBase.size() < 6) {
			cout << "Name of the new account" << endl;
			std::cin.ignore();
			std::getline(cin, choice);
			Accounts newAcc = Accounts(choice, dataBase.size() + 1);
			dataBase.push_back(newAcc);
			system("cls");
		}
		else if (choice == to_string(dataBase.size() + 2)) {
			cout << "First Account Number (From or Take Out Account): " << endl;
			cin >> choice;
			cout << "Second Account Number (To or Income Account): " << endl;
			cin >> choice2;
			cout << "Amount " << endl;
			cin >> amount;
			Tranfer(dataBase[stoi(choice) - 1], dataBase[stoi(choice2) - 1], stoi(amount));
		}
		else if (choice == to_string(dataBase.size() + 3)) {
			break;
		}
		else if (stoi(choice) < dataBase.size() + 1 && stoi(choice) > -1) {
			system("cls");
			while (true) {
				cout << "Acount: " << dataBase[stoi(choice) - 1].name << endl;
				cout << "Amount: " << dataBase[stoi(choice) - 1].total << endl;
				cout << "(1) Add Funds\n(2) Remove Funds\n(3) See History\n(4) Change Name " << endl;
				cin >> choice2;
				if (choice2 == "1")
				{
					cout << "How much would you like to add to your account?" << endl;
					cin >> choice2;
					dataBase[stoi(choice) - 1].AddFunds(stoi(choice2));
				}
				else if (choice2 == "2") {
					cout << "How much would you like to remove from your account?" << endl;
					cin >> choice2;
					dataBase[stoi(choice) - 1].expence(stoi(choice2));
				}
				else if (choice2 == "3") {
					dataBase[stoi(choice) - 1].OpenHistory();
					cin >> choice2;
				}
				else if (choice2 == "4") {
					cout << "Change Acount Name To What?" << endl;
					cin >> choice2;
					dataBase[stoi(choice) - 1].ChangeName(choice2);
				}
				else {
					system("cls");
					break;
				}


				system("cls");
			}

		}
		else {
			system("cls");
		}
	}




	SaveAccounts(dataBase);
	return -1;
}