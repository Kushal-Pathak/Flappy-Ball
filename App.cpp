#include <iostream>
#define h 25
#define w 50
using namespace std;

char buffer[h][w];

void init_buffer();
void render();

int main() {
	init_buffer();
	render();
}

void init_buffer() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			buffer[i][j] = '*';
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