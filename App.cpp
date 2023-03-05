#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#define h 15
#define w 30
#define block (char)254
#define ball_body 'O';
using namespace std;

char buffer[h][w], play='y';
struct Ball {
	float x = w / 2, y = h / 2;
};
Ball ball;
int step = 0, game_over = 0, jump_limit = (int)ball.y - 3, score = 0;
int delay = 50;
float vy = 0.5;

void init_buffer();
void bind_ball();
void unbind_ball();
void render();
void generate_obstacle();
void shift_obstacles();
void update();
void control();
void detect_collision();
void game_over_message();
void home_screen();
void reset_game();
void count_score();

int main() {
	srand((unsigned int)time(0));
	while (play == 'y') {
		reset_game();
		while (!game_over) {
			render();
			control();
			update();
			//detect_collision();
			//Sleep(delay);
		}
		game_over_message();
	}
}

void count_score() {
	if (buffer[h - 2][(int)ball.x - 1] == block) {
		score++;
	}
}
void home_screen() {
	cout << "w : to jump";
}
void reset_game() {
	game_over = 0;
	score = 0;
	play = 'y';
	vy = 0.5;
	step = 0;
	ball.x = w / 2; ball.y = h / 2;
	step = 0;
	init_buffer();
	bind_ball();
}
void game_over_message() {
	cout << "Game Over!" << endl << "Play again (y): ";
	play = 'n';
	cin >> play;
}
void detect_collision() {
	int tx = (int)round(ball.x);
	int ty = (int)round(ball.y);
	if (buffer[ty][tx] == block) {
		game_over = 1;
	}
	if (ty <= 0 || ty >= h - 1) {
		game_over = 1;
	}
}

void control() {
	if (_kbhit()) {
		char c = _getch();
		if (c == 'w') {
			vy = -0.5;
			jump_limit = ball.y - 3;
		}
	}

}

void update() {
	count_score();
	if (ball.y == jump_limit) {
		vy = 0.5;
	}
	unbind_ball();
	ball.y += vy;
	detect_collision();
	bind_ball();
	shift_obstacles();
	generate_obstacle();
	step++;
}
void shift_obstacles() {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w - 1; j++) {
				if (buffer[i][j + 1] == block) {
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
		int r2 = 1 + rand() % 4;
		for (int i = 1; i <= r2; i++) {
			buffer[h - 1 - i][w - 1] = block;
		}
	}
}
void bind_ball() {
	int tx = (int)round(ball.x);
	int ty = (int)round(ball.y);
	if (buffer[ty][tx] != block) {
		buffer[ty][tx] = ball_body;
	}
}
void unbind_ball() {
	int tx = (int)round(ball.x);
	int ty = (int)round(ball.y);
	buffer[ty][tx] = ' ';
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
	cout << "Score: " << score << endl;
}
