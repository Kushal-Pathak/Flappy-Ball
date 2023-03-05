#include <iostream>
#include <conio.h>
#include <ctime>
#define h 15
#define w 51
#define block (char)254
#define ball_body 'O';
using namespace std;

char buffer[h][w];
struct Ball {
	int x = w / 2, y = h / 2;
};

Ball ball;

void init_buffer();
void bind_ball();
void unbind_ball();
void render();
void generate_obstacle();

int main() {
	srand((unsigned int)time(0));
	init_buffer();
	bind_ball();
	generate_obstacle();
	render();
}
void generate_obstacle() {
	int r1 = 1 + rand() % 4;
	int r2 = 1 + rand() % 2;
	for (int i = 1; i <= r1; i++) {
		buffer[i - 1][w - 1] = block;
	}
	for (int i = 1; i <= r1; i++) {
		buffer[h - 1 - i][w - 1] = block;
	}
}
void bind_ball() {
	buffer[ball.y][ball.x] = ball_body;
}
void unbind_ball() {
	buffer[ball.y][ball.x] = ' ';
}
void init_buffer() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			buffer[i][j] = ' ';
			buffer[0][j] = '-';
			buffer[h - 1][j] = '_';
		}
	}
}
void render() {
	system("cls");
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << buffer[i][j] << " ";
		}
		cout << endl;
	}
}
