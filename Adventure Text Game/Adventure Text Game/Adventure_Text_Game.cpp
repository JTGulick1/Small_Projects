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

bool Battle(int Hnumber, vector<Enemy> horde, int& health, int attack) {
	system("cls");
	int enemnyHP = horde[Hnumber].health;
	string input = "";
	while (enemnyHP > 0 && health > 0) {
		cout << "Encountered a " << horde[Hnumber].name << endl;
		cout << "Player Stats: HP: " << health << " Damage: " << attack << endl;
		cout << "Enemy Stats: HP: " << enemnyHP << " Damage: " << horde[Hnumber].damage << endl;
		cout << "(1) Attack\n(2) Defend\n(3) Retreat" << endl;
		cin >> input;
		if (input == "1") {
			enemnyHP -= attack;
			if (enemnyHP > 0) {
				health -= horde[Hnumber].damage;
			}
		}
		else if (input == "2") {
			health -= horde[Hnumber].damage / 2;
		}
		else if (input == "3") {
			int random = rand() % 5 + 1;
			if (random == 3) {
				cout << "Flee Successful" << endl;
				return false;
			}
			else {
				cout << "Flee Failed" << endl;
			}
		}


		cin >> input;
		system("cls");
	}
	if (enemnyHP <= 0) {
		return true;
	}
	return false;
}


int main() {

	//Player Stats
	int health = 100;
	int attack = 5;
	int money = 0;
	int hunger = 100;
	int water = 100;
	int day = 0;
	int time = 1;
	int traderRep = 5;
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
	if (input == "1") {
		attack += 2;
	}
	else if (input == "2") {
		health += 10;
		attack += 1;
	}
	else if (input == "3") {
		money += 10;
	}
	else if (input == "4") {
		health += 20;
	}

	while (health > 0) {
		system("cls");

		//Day Phase
		while (time != 4) {
			cout << "Day: " << day << " Time: " << time << endl;
			cout << "Traveling..." << endl;
			cout << "HP: " << health << "      Money: " << money << endl;;
			int random = std::rand() % 6 + 1;

			if (random == 4) {
				cout << "Ran into a Trader...    Trader Reputation: " << traderRep << endl;
				//Open trading menu
				random = std::rand() % list.size();
				cout << "I am currently selling " << list[random].name << " for " << list[random].value << " are you interested?" << endl;
				cout << "(1) Yes\n(2) No\n";
				cin >> input;
				if (input == "1") {
					if (money >= list[random].value) {
						cout << "Pleasure Doing Buisness" << endl;
						money -= list[random].value;
						inv.push_back(list[random]);
						traderRep++;
					}
					else {
						cout << "Not Enough Money" << endl;
						traderRep--;
					}
				}
				else {
					cout << "Well get out of my face then..." << endl;
					traderRep--;
				}
			}
			else if (random == 3) {
				int random = std::rand() % 15 + 1;
				cout << "Found Some Money... + " << random << endl;
				money += random;
			}
			else if (random == 6 || random == 5) {
				random = std::rand() % list.size();
				cout << "Found a " << list[random].name << endl;
				inv.push_back(list[random]);
			}
			else if (random == 7 || random == 8) {
				cout << "Nothing Happends..." << endl;
			}
			else if (random == 2) {
				cout << "Stepped In A Trap (-10 HP)" << endl;
				health -= 10;
			}
			else {
				cout << "Ran Into A Enemy Horde" << endl;
				//Open  Fight Gameplay
				random = std::rand() % horde.size();
				bool batt = false;
				batt = Battle(random, horde, health, attack);
				if (batt == true) {
					cout << "Congrats you win: Money + " << horde[random].damage + horde[random].health << endl;
					money += horde[random].damage;
					money += horde[random].health;
				}
			}

			cin >> input;
			if (health <= 0) {
				break;
			}
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