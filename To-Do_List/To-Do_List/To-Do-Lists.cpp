#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void AddEvent(std::vector<std::string>& lines) {
	string Event;
	cout << "\n\nPlease Enter Your Event Name:\n";
	std::getline(cin, Event);
	lines.push_back(Event);
};

void CompleteEvent(std::vector<std::string>& lines) {

};

void ChangeEvent(std::vector<std::string>& lines) {

};

void ViewEvents(std::vector<std::string>& lines) {
	for (const std::string& str : lines) {
		std::cout << str << std::endl;
	}
	cout << "\n\n\n";
}

void OpenList() {
	std::ifstream file("data.txt"); // Replace "data.txt" with your file
	std::string line;
	std::vector<std::string> lines;

	// Read each line from the file and store it in the vector
	while (std::getline(file, line)) {
		lines.push_back(line);
	}

	file.close();

	while (true)
	{
		std::cout << "Welcome to  your To-Do List..." << endl;
		std::cout << "(1) View Event\n(2) Add Event\n(3) Complete Event\n(4) Change Event\n(5) Close and Save Application" << endl;
		string number = "";
		std::cin >> number;
		if (number == "1") {
			cout << "\n\n\n\n\n\n";
			ViewEvents(lines);
		}
		else if (number == "2") {
			AddEvent(lines);
		}
		else if (number == "3") {
			CompleteEvent(lines);
		}
		else if (number == "4") {
			ChangeEvent(lines);
		}
		else if (number == "5") {
			break;
		}
		else {
			cout << "\n\n\n\n\n\n Please enter a Number 1-5 \n\n";
		}
	}
	
	
};

int main() {

	OpenList();
	return -1;
}