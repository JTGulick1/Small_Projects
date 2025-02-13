#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct Accounts {
public:
	int accountNum;
	string name;
	int total;
	string textfile;
	vector<string> history;
	Accounts(string n, int Anum) {
		name = n;
		accountNum = Anum;
	}
	void AddFunds(int amount) {
		total += amount;
		history.push_back("Added " + std::to_string(amount));
	}
	void expence(int amount) {
		total -= amount;
		history.push_back("Spent " + std::to_string(amount));
	}
	void OpenHistory() {
		cout << name << endl;
		for (int i = 0; i < history.size(); i++) {
			cout << history[i] << endl;
		}
	}
	void SaveHistory() {

		// Save to the txt file
	}
};


void Tranfer(Accounts acc1, Accounts acc2, int amount) {
	acc1.expence(amount);
	acc2.AddFunds(amount);
}


vector<Accounts> OpenAccounts() { //when the application opens find the text files and create the accounts
	vector<Accounts> accounts;


	return accounts;
}

void SaveAccounts(vector<Accounts> accounts) { //when the application closes save the new information to the txt files

}


int main() {
	vector<Accounts> dataBase;
	dataBase = OpenAccounts();
	


	SaveAccounts(dataBase);
	return -1;
}