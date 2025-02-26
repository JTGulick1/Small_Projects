#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include <cstdlib>

using namespace std;

struct item {
public:
	enum Use {
		Food, // 5
		Hydration, // 3
		Supplies, // 3
		Tool, // 5
		Weapon // 5
	};
	Use use;
	string name = "";
	int value = 0;

	explicit item(const string& u, int val, const string& n)
		: value(val), name(n), use(Use::Supplies) { // Default to Supplies

		static const unordered_map<string, Use> useMap = {
			{"Food", Use::Food},
			{"Hydration", Use::Hydration},
			{"Supplies", Use::Supplies},
			{"Tool", Use::Tool},
			{"Weapon", Use::Weapon}
		};

		auto it = useMap.find(u);
		if (it != useMap.end()) {
			use = it->second;
		}
		else {
			cerr << "Warning: Invalid use type '" << u << "', defaulting to Supplies." << endl;
		}
	}
};

 
struct Enemy { // 10
public:
	string name = "";
	int health = 0;
	int damage = 0;
	Enemy(string n,int h, int d) {
		health = h;
		damage = d;
		name = n;
	}
};


int main() {

	//Player Stats
	int health = 100;
	int attack = 5;
	int money = 0;
	int hunger = 100;
	int water = 100;
	int day = 0;
	int time = 1;
	vector<item>  inv;
	vector<item> list;
	vector<Enemy> horde;
	string input = "";
	//Upload all Items from txt file
	ifstream file("Items.txt");
	for (int i = 0; i < 20; i++) {
		string use = "";
		string name = "";
		string value = "";
		std::getline(file, use);
		std::getline(file, name);
		std::getline(file, value);
		item  it = item(use, stoi(value), name);
		list.push_back(it);
	}

	file.close();

	ifstream enms("Enemy.txt");
	for (int i = 0; i < 9; i++) {
		string name = "";
		string health = "";
		string damage = "";
		std::getline(enms, name);
		std::getline(enms, health);
		std::getline(enms, damage);
		Enemy  enemy = Enemy(name, stoi(health), stoi(damage));
		horde.push_back(enemy);
	}

	enms.close();

	

	//Upload all Enemies from txt file


	cout << "Welcome to my Text Based Game Project #7" << endl;
	cout << "(1) Start Game\n(2) Exit Game" << endl;
	cin >> input;
	if (input == "2") {
		return -1;
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
		while (time != 4) {
			cout << "Day: " << day << " Time: " << time << endl;
			cout << "Traveling..." << endl;
			int random = rand();

			if (random % 4 == 0) {
				cout << "Ran into a Trader..." << endl;
				//Open trading menu
			}
			else if (random % 3 == 0) {
				cout << "Ran Into A Enemy Horde" << endl;
				//Open  Fight Gameplay
			}
			else if (random % 2 == 0 && random % 10 == 0) {
				cout << "Stepped In A Trap (-10 HP)" << endl;
			}
			else {
				cout << "Nothing Happened..." << endl;
			}

			cin >> input;

			system("cls");
			time++;
		}
		time = 0;

		//Night Phase
		while (true) {
			cout << "Night and Camping Menu" << endl;
			cout << "(1) Consume Something In Inventory\n(2) Open Shop\n(3) Continue To Next Day\n";
			cin >> input;
			if (input == "1") {
				//Open Inv
			}
			else if (input == "2") {
				//Open Night Trader
				//Chance to Spawn Mobs
			}
			else if (input == "3") {
				break;
			}
			system("cls");
		}
		
		day++;

	}
	



	return -1;
}