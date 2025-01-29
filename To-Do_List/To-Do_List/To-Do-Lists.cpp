#include <iostream>

using namespace std;

class Events
{
public:
	int number = 0;
	string eventName = "";
	Events(int num, string name);
};

Events::Events(int num, string name)
{
	number = num;
	eventName = name;
}

void AddEvent() {

};

void CompleteEvent() {

};

void ChangeEvent() {

};

void ViewEvents() {

}

void OpenList() {
	std::cout << "Welcome to  your To-Do List..." << endl;
	std::cout << "(1) View Event\n(2) Add Event\n(3) Complete Event\n(4) Change Event" << endl;

};

int main() {

	OpenList();
	return -1;
}