#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void AddEvent(std::vector<std::string>& lines) {
	string Event;
	cout << "\n\nPlease Enter Your Event Name:\n";
	std::cin.ignore();
	std::getline(std::cin, Event);
	lines.push_back(Event);
	system("cls");
};


void ViewEvents(std::vector<std::string>& lines) {
	system("cls");
	cout << "To-Do List: " << endl;
	for (int i = 0; i < lines.size(); i++) {
		std::cout << "(" << (i + 1) << ") " << lines[i] << std::endl;
	}
	cout << "\n\n\n";
}


void ChangeEvent(std::vector<std::string>& lines) {
	ViewEvents(lines);
	cout << "What Event Do You Want To Change?";
	string number;
	cin >> number;
	string Event = "";
	cout << "Change the event to: ";
	std::cin.ignore();
	std::getline(std::cin, Event);
	lines[stoi(number) - 1] = Event; 
	system("cls");
};

void CompleteEvent(std::vector<std::string>& lines, std::vector<std::string>& completed) {
	ViewEvents(lines);
	cout << "What Event Did You Complete?";
	string number;
	cin >> number;
	string eve = lines[stoi(number) - 1];
	completed.push_back(eve);
	lines.erase(lines.begin() + stoi(number) - 1);
	system("cls");
};

void ViewCompleted(std::vector<std::string>& lines) {
	system("cls");
	cout << "Completed List: " << endl;
	for (int i = 0; i < lines.size(); i++) {
		std::cout << "(" << (i + 1) << ") " << lines[i] << std::endl;
	}
	cout << "\n\n\n";
}

void SaveList(std::vector<std::string>& lines, std::vector<std::string>& completed){
	std::ofstream tasks("Tasks.txt");

	// Check if the file is open
	if (!tasks.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
	}
	else {
		for (int i = 0; i < lines.size(); i++) {
			tasks << lines[i] <<"\n";
		}
	}
	tasks.close();

	std::ofstream comps("Completed.txt");

	// Check if the file is open
	if (!comps.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
	}
	else {
		for (int i = 0; i < completed.size(); i++) {
			comps << completed[i] << "\n";
		}
	}
}

void OpenList() {
	
	std::ifstream file("Tasks.txt"); 
	std::string line;
	std::vector<std::string> lines;

	// Read each line from the file and store it in the vector
	while (std::getline(file, line)) {
		lines.push_back(line);
	}

	file.close();

	std::ifstream comp("Completed.txt");
	std::vector<std::string> completed;

	// Read each line from the file and store it in the vector
	while (std::getline(comp, line)) {
		completed.push_back(line);
	}

	comp.close();

	while (true)
	{
		std::cout << "Welcome to  your To-Do List..." << endl;
		std::cout << "(1) View Event\n(2) Add Event\n(3) Complete Event\n(4) Change Event\n"
			"(5) View Completed Tasks\n(6) Clear Current List\n(7) Clear Completed List\n(9) Close and Save Application" << endl;
		string number = "";
		std::cin >> number;
		if (number == "1") {
			ViewEvents(lines);
		}
		else if (number == "2") {
			AddEvent(lines);
		}
		else if (number == "3") {
			CompleteEvent(lines, completed);
		}
		else if (number == "4") {
			ChangeEvent(lines);
		}
		else if (number == "5") {
			ViewCompleted(completed);
		}
		else if (number == "6") {
			cout << "\nAre you sure about clearing your current list? (y/n)";
			cin >> number;
			if (number == "y") {
				lines.clear();
			}
		}
		else if (number == "7") {
			cout << "\nAre you sure about clearing your completed list? (y/n)";
			cin >> number;
			if (number == "y") {
				completed.clear();
			}
		}
		else if (number == "9") {
			SaveList(lines, completed);
			break;
		}
		else {
			system("cls");
			cout << "Please enter a Number 1-5 \n\n";
		}
	}
	
	
};

int main() {

	OpenList();
	return -1;
}