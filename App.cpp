#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#define h 15
#define w 30
#define block (char)254
#define ball_body 'O';
using namespace std;

char buffer[h][w];
struct Ball {
	int x = w / 2, y = h / 2;
};
int step = 0, delay = 150;

Ball ball;

void init_buffer();
void bind_ball();
void unbind_ball();
void render();
void generate_obstacle();
void shift_obstacles();
void update();

int main() {
	srand((unsigned int)time(0));
	init_buffer();
	bind_ball();
	while (1) {
		render();
		update();
		//Sleep(delay);
	}
}

void update() {
	shift_obstacles();
	generate_obstacle();
	step++;
}
void shift_obstacles() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w - 1; j++) {
			if (buffer[i][j+1] == block) {
				buffer[i][j] = block;
				buffer[i][j + 1] = ' ';
			}
			if (buffer[i][0] == block) buffer[i][0] = ' ';
		}
	}
}
void generate_obstacle() {
	if (step % 10 == 0) {
		int r1 = 1 + rand() % 4;
		for (int i = 1; i <= r1; i++) {
			buffer[i][w - 1] = block;
		}
		Sleep(delay);
		int r2 = 1 + rand() % 2;
		for (int i = 1; i <= r2; i++) {
			buffer[h - 1 - i][w - 1] = block;
		}
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
