#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

int x = 1;
int y = 1;
int bot_x = 9;
int bot_y = 9;
char hero_char = 254;
char bot_char = 35;
char game_field[11][21];

int check_if_loose() {
	int game_over = 1;
	if (bot_x == x && bot_y == y){
		game_over = 0;
	}

	return game_over;
}

void make_field() {
	game_field[0][0] = 43;
	for (int column_index = 1; column_index < 20; column_index++){
		game_field[0][column_index] = 45;
	}
	game_field[0][19] = 43;

	game_field[10][0] = 43;
	for (int column_index = 1; column_index < 20; column_index++) {
		game_field[10][column_index] = 45;
	}
	game_field[10][19] = 43;

	for (int row_index = 1; row_index < 10; row_index++){
		game_field[row_index][0] = 124;
	}

	for (int row_index = 1; row_index < 10; row_index++) {
		game_field[row_index][19] = 124;
	}

	for (int row_index = 1; row_index < 10; row_index++) {
		for (int column_index = 1; column_index < 19; column_index++) {
			game_field[row_index][column_index] = 32;
		}
	}
	
}

void update_field() {
	for (int row_index = 1; row_index < 10; row_index++) {
		for (int column_index = 1; column_index < 19; column_index++) {
			game_field[row_index][column_index] = 32;
		}
	}
}

void display_field() {
	for (int row_index = 0; row_index  < 11; row_index ++){
		for (int column_index = 0; column_index < 20; column_index++){
			cout << game_field[row_index][column_index];
		}
		cout << "\n";
	}
}

void listen_movements() {
	if (GetAsyncKeyState(VK_LEFT)) {
		if (x > 1) {
			x -= 2;
			Sleep(100);
		}
	}

	if (GetAsyncKeyState(VK_RIGHT)) {
		if (x < 18) {
			x += 2;
			Sleep(20);
		}
	}

	if (GetAsyncKeyState(VK_UP)) {
		if (y > 1) {
			y -= 2;
			Sleep(100);
		}
	}

	if (GetAsyncKeyState(VK_DOWN)) {
		if (y < 9) {
			y += 2;
			Sleep(100);
		}
	}
	game_field[y][x] = hero_char;
}

void move_bot() {
	if (bot_x > x) {
		bot_x--;
	}else {
		bot_x++;
	}

	if (bot_y > y) {
		bot_y--;
	}
	else {
		bot_y++;
	}
	Sleep(100);
	game_field[bot_y][bot_x] = bot_char;
	
}

int main() {
	srand(time(NULL));
	make_field();
	while (check_if_loose()) {
		update_field();
		listen_movements();
		move_bot();
		display_field();
		system("cls");
	}
	cout << "You lost";
	return 0;
}