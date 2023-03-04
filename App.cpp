#include <iostream>
#define h 21
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

int main() {
	init_buffer();
	bind_ball();
	render();
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