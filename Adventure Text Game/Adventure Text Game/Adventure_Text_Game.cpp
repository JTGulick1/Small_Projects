#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct item {
public:
	enum Use {
		Food,
		Hydration,
		Supplies,
		Tool,
		Weapon
	};
	Use use;
	int value = 0;

	item(Use u, int val) {
		value = val;
		use = u;
	}
};


struct Enemy {
public:
	int health = 0;
	int damage = 0;
	Enemy(int h, int d) {
		health = h;
		damage = d;
	}
};


int main() {

	//Player Stats
	int health = 100;
	int attack = 5;
	int money = 0;
	int day = 0;
	vector<item>  inv;
	vector<Enemy> horde;
	string input = "";
	//Upload all Items from txt file
	

	//Upload all Enemies from txt file


	cout << "Welcome to my Text Based Game Project #7" << endl;
	cout << "(1) Start Game\n(2) Exit Game" << endl;
	cin >> input;
	if (input == "2") {
		return;
	}
	
	system("cls");
	//Player Creation Phase
	cout << "Choose 1 class" << endl;
	cout << "(1) Rogue (Damage + 2)\n(2) Brawler (Health + 10 Damage + 1) \n(3) Thief (money + 10)\n(4) Tank (Health + 20)\n(5) Survivalist (No Effects)" << endl;
	cin >> input;
	switch (stoi(input))
	{
	case 1:
		attack += 2;
	case 2:
		health += 10;
		attack += 1;
	case 3:
		money += 10;
	case 4:
		health += 20;
	}

	while (health > 0) {
		system("cls");

		//Day Phase
		cout << "Begining of Day " << day << endl;
		cout << "Traveling..." << endl;


		//Night Phase


	}
	



	return -1;
}