#include <iostream>
#include <vector>
using namespace std;

bool Play(vector<string>& board, string input, int player) {
	if (player == 1) {
		if (input == "1" && board[0] == "_") {
			board[0] = "X";
			return true;
		}
		if (input == "2" && board[1] == "_") {
			board[1] = "X";
			return true;
		}
		if (input == "3" && board[2] == "_") {
			board[2] = "X";
			return true;
		}
		if (input == "4" && board[3] == "_") {
			board[3] = "X";
			return true;
		}
		if (input == "5" && board[4] == "_") {
			board[4] = "X";
			return true;
		}
		if (input == "6" && board[5] == "_") {
			board[5] = "X";
			return true;
		}
		if (input == "7" && board[6] == "_") {
			board[6] = "X";
			return true;
		}
		if (input == "8" && board[7] == "_") {
			board[7] = "X";
			return true;
		}
		if (input == "9" && board[8] == "_") {
			board[8] = "X";
			return true;
		}
	}
	else {
		if (input == "1" && board[0] == "_") {
			board[0] = "O";
			return true;
		}
		if (input == "2" && board[1] == "_") {
			board[1] = "O";
			return true;
		}
		if (input == "3" && board[2] == "_") {
			board[2] = "O";
			return true;
		}
		if (input == "4" && board[3] == "_") {
			board[3] = "O";
			return true;
		}
		if (input == "5" && board[4] == "_") {
			board[4] = "O";
			return true;
		}
		if (input == "6" && board[5] == "_") {
			board[5] = "O";
			return true;
		}
		if (input == "7" && board[6] == "_") {
			board[6] = "O";
			return true;
		}
		if (input == "8" && board[7] == "_") {
			board[7] = "O";
			return true;
		}
		if (input == "9" && board[8] == "_") {
			board[8] = "O";
			return true;
		}
	}
	return false;
}
void DrawBoard(vector<string> board) {
	for (int i = 0; i < board.size(); i++) {
		std::cout << " | " << board[i] << " | ";
		if (i == 2 || i == 5 || i == 8) {
			std::cout << endl;
		}
	}
}
bool checkWins(vector<string> board) {
	//X CHeck
	if (board[0] == "X" && board[1] == "X" && board[2] == "X") {std::cout << "X Wins" << endl; return true;} // top
	if (board[3] == "X" && board[4] == "X" && board[5] == "X") { std::cout << "X Wins" << endl; return true; }//middle
	if (board[6] == "X" && board[7] == "X" && board[8] == "X") { std::cout << "X Wins" << endl; return true; }//bottom
	if (board[0] == "X" && board[3] == "X" && board[6] == "X") { std::cout << "X Wins" << endl; return true; }//left
	if (board[1] == "X" && board[4] == "X" && board[7] == "X") { std::cout << "X Wins" << endl; return true; }//middle col
	if (board[2] == "X" && board[5] == "X" && board[8] == "X") { std::cout << "X Wins" << endl; return true; }//right
	if (board[0] == "X" && board[4] == "X" && board[8] == "X") { std::cout << "X Wins" << endl; return true; }//diag left to right
	if (board[2] == "X" && board[4] == "X" && board[6] == "X") { std::cout << "X Wins" << endl; return true; }//diag right to left
	//O Check
	if (board[0] == "O" && board[1] == "O" && board[2] == "O") { std::cout << "O Wins" << endl; return true; } // top
	if (board[3] == "O" && board[4] == "O" && board[5] == "O") { std::cout << "O Wins" << endl; return true; }//middle
	if (board[6] == "O" && board[7] == "O" && board[8] == "O") { std::cout << "O Wins" << endl; return true; }//bottom
	if (board[0] == "O" && board[3] == "O" && board[6] == "O") { std::cout << "O Wins" << endl; return true; }//left
	if (board[1] == "O" && board[4] == "O" && board[7] == "O") { std::cout << "O Wins" << endl; return true; }//middle col
	if (board[2] == "O" && board[5] == "O" && board[8] == "O") { std::cout << "O Wins" << endl; return true; }//right
	if (board[0] == "O" && board[4] == "O" && board[8] == "O") { std::cout << "O Wins" << endl; return true; }//diag left to right
	if (board[2] == "O" && board[4] == "O" && board[6] == "O") { std::cout << "O Wins" << endl; return true; }//diag right to left

	//Tie Check
	if (board[0] != "_" && board[1] != "_" && board[2] != "_" && board[3] != "_" &&
		board[4] != "_" && board[5] != "_" && board[6] != "_" &&
		board[7] != "_" && board[8] != "_") {
		cout << "Tie" << endl;
		return true;
	}
	return false;
}
void Play2() {
	vector<string> board = {"_","_","_","_","_","_","_","_","_" };
	string input = "";
	bool p1 = false;
	bool p2 = false;
	while (true) {
		system("cls");
		DrawBoard(board);
		
		while (p1 == false) {
			std::cout << "Choose Square (1-9)" << endl;
			std::cin >> input;
			p1 = Play(board, input, 1);
		}
		system("cls");
		if (checkWins(board) == true) {
			return;
		}
		DrawBoard(board);
		while (p2 == false) {
			std::cout << "Choose Square (1-9)" << endl;
			std::cin >> input;
			p2 = Play(board, input, 2);
		}
		if (checkWins(board) == true) {
			return;
		}
		p1 = false;
		p2 = false;
	}
	

}

void PlayAI() {

}



int main() {
	vector<int> board;
	string input = "";
	while (true) {
		std::cout << "Play TicTacToe?" << endl;
		std::cout << "(1) 2 Players\n(2) Player vs AI\n(3) Quit Application" << endl;
		std::cin >> input;
		if (input == "1") {
			Play2();
		}
		else if (input == "2") {
			PlayAI();
		}
		else if (input == "3") {
			return -1;
		}
	}

	return -1;
}