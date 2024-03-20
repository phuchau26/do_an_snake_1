#include <iostream>
#include <fstream>
#include "resource.h"
using namespace std;

const int X_SCREEN_TOP = 25;
const int Y_SCREEN_TOP = 10;
const int X_SCREEN_BOTTOM = X_SCREEN_TOP + 90;
const int Y_SCREEN_BOTTOM = Y_SCREEN_TOP + 24;
const int X_BLOCK_1 = X_SCREEN_TOP + 30;
const int X_BLOCK_2 = X_SCREEN_TOP + 50;
const int MAX = 200;
const int MSSV = 8;
const int HEIGHT = 1200;
const int WIDTH = 500;
const int X_GATE = X_SCREEN_TOP + 60;
const int Y_GATE = Y_SCREEN_BOTTOM - 3;
const int SPEED = 100;
const int MAX_FOOD = 5;

int length_of_snake = 4;
int snake_direction = 0;
int score = 0;
char S[MSSV] = {'2','3','1','2','0','2','5','2'};
bool gamover = false;

void snake_init(int X[], int Y[]);
void draw_left_right_wall(int h);
void draw_top_bottom_wall(int h);
void draw_snake(int X[], int Y[]);
void delete_old_snake(int X[], int Y[]);
void snake_process(int X[], int Y[], int &x, int &y, int &xqua, int &yqua);
void create_food(int &x, int &y, int X[], int Y[]);
void draw_block(int &x_block, int &y_block, bool &block_direction, int X[], int Y[]);
void draw_comment();
void draw_score();
void gate_init();
void draw_wall_and_numbers();
void draw_mini_top_bottom_wall(int y);
bool is_snake_lying_on_food(int x, int y, int X[], int Y[]);
bool is_snake_eat_food(int xq, int yq, int x, int y);


int main(){

	draw_wall_and_numbers();	

	int x = X_SCREEN_BOTTOM/2, y = Y_SCREEN_BOTTOM/2; // toa do ban dau 
	int X[MAX], Y[MAX]; // cac mang luu toa do x, y
	bool block_direction = 0; //0: xuong, 1: len
	bool block_direction_2 = 1;

	snake_init(X, Y);
	draw_snake(X, Y);

	//Tao thuc an
	int xq = 0, yq = 0, x_block = X_BLOCK_1, y_block = Y_SCREEN_TOP+1, x_block_2 = X_BLOCK_2, y_block_2 = Y_SCREEN_BOTTOM;
	draw_block(x_block, y_block, block_direction, X, Y);
	draw_block(x_block_2, y_block_2, block_direction_2, X, Y);
	create_food(xq, yq, X, Y);

	while(gamover == false){
		if (_kbhit()){
			char character_from_keyboard = _getch();
			if (character_from_keyboard == -32){
				character_from_keyboard = _getch();
				if (character_from_keyboard == 72 && snake_direction != 0){ //len
					snake_direction = 1;
				}else if (character_from_keyboard == 80 && snake_direction != 1){ //xuong
					snake_direction = 0;
				}else if (character_from_keyboard == 75 && snake_direction != 3 ){ // trai
					snake_direction = 2;
				}else if (character_from_keyboard == 77 && snake_direction != 2){ //phai
					snake_direction = 3;
				}

			}

			if (character_from_keyboard == 'w' && snake_direction != 0){
				snake_direction = 1;
			}else if (character_from_keyboard == 's' && snake_direction != 1){
				snake_direction = 0;
			}else if (character_from_keyboard == 'a' && snake_direction != 3){
				snake_direction = 2;
			}else if (character_from_keyboard == 'd'  && snake_direction != 2){
				snake_direction = 3;
			}
		}

		if (snake_direction == 1){
			y --;
			Sleep(SPEED);
		}else if (snake_direction == 0){
			y ++;
			Sleep(SPEED);
		}else if (snake_direction == 2){
			x -= 1;
			Sleep(SPEED/1.2);
		}else if (snake_direction == 3){
			x += 1;
			Sleep(SPEED/1.2);
		}

		snake_process(X, Y, x, y, xq, yq);
		draw_block(x_block, y_block, block_direction, X, Y);
		draw_block(x_block_2, y_block_2, block_direction_2, X, Y);

		//Kiem tra ran dung tuong
		if (Y[0] == Y_SCREEN_BOTTOM+1 || Y[0] == Y_SCREEN_TOP || X[0] == X_SCREEN_TOP || X[0] == X_SCREEN_BOTTOM || (X[0] == x_block && Y[0] == y_block) || (X[0] == x_block_2 && Y[0] == y_block_2)){
			gamover = true;
		}
		//Kiem tra ran can duoi
		for (int i = 1; i < length_of_snake; i++){
			if (X[0] == X[i] && Y[0] == Y[i]){
				gamover = true;
			}
		}


	}
	Sleep(500);
	draw_comment();
	Sleep(10000);


	return 0;
}

bool is_snake_eat_food(int x_food, int y_food, int x, int y){
	if (x_food == x && y_food == y){
		return true;
	}
	return false;
}


bool is_snake_lying_on_food(int x_food, int y_food, int X[], int Y[]){

	for (int i = 0; i < length_of_snake; i++){
		if (x_food == X[i] && y_food == Y[i]){
			return true;
		}
	}

	return false;

}


void create_food(int &x_food, int &y_food, int X[], int Y[]){

	do{
		x_food = rand()%(X_SCREEN_BOTTOM - X_SCREEN_TOP -6) + X_SCREEN_TOP+5;
		y_food = rand()%(Y_SCREEN_BOTTOM- Y_SCREEN_TOP- 4) +Y_SCREEN_TOP+1;

	}while(is_snake_lying_on_food(x_food, y_food, X, Y));


	gotoXY(x_food, y_food);
	cout << 0;

	

}

void delete_old_snake(int X[], int Y[]){

	for (int j = 0; j < length_of_snake; j++){
		gotoXY(X[j],Y[j]);
		cout << ' ';
	}

}




void snake_process(int X[], int Y[], int &x, int &y, int &xq, int &yq){

	delete_old_snake(X, Y);

	if (is_snake_eat_food(xq, yq, X[0], Y[0])){
		create_food(xq, yq, X, Y);
		gotoXY(X_SCREEN_BOTTOM+12,Y_SCREEN_TOP+1);
		length_of_snake++;
		score ++;
		draw_score();
	}else if(xq == X_BLOCK_1 || xq == X_BLOCK_2){
		gotoXY(xq,yq);
		cout << ' ';
		create_food(xq, yq, X, Y);
	}


	int i;
	for (i = length_of_snake - 1; i > 0; i--){
		X[i] = X[i-1];
		Y[i] = Y[i-1];
	}
	X[i] = x;
	Y[i] = y;


	if (X[i] == X_GATE && Y[i] == Y_GATE && snake_direction != 3){
		gamover = true;

	}else if (X[i] == X_GATE && Y[i] == Y_GATE ){

		X[i] -= 50;
		Y[i] -= 5;
		x -= 50;
		y -=5;

	}



	draw_snake(X, Y);

}


void snake_init(int X[], int Y[]){
	int x = X_SCREEN_BOTTOM/2, y = Y_SCREEN_BOTTOM/2;
	for (int i = 0; i < length_of_snake; i++){
		X[i] = x;
		Y[i] = y;
		x --;

	}

}

void draw_snake(int X[], int Y[]){

	for (int i = 0; i < length_of_snake; i++){
		gotoXY(X[i], Y[i]);
		opacity_text(S[i%MSSV]);
	}


}

void draw_left_right_wall(int x){
	//x = 100, 10
	int y = Y_SCREEN_TOP+1;

	if (x < X_SCREEN_BOTTOM){
		gotoXY(X_SCREEN_TOP,Y_SCREEN_TOP);
		cout << char(201); // tren ben trai
		gotoXY(X_SCREEN_TOP,Y_SCREEN_BOTTOM+1);
		cout << char(200); // duoi ben trai
	}

	while (y <= Y_SCREEN_BOTTOM){
		gotoXY(x, y);
		if (!(x%X_SCREEN_BOTTOM == 0)){
			cout << char(186);
		}else{
			cout << char(179);
		}
		y++;
	}
}

void draw_top_bottom_wall(int y){
	// y = 1, 26
	int x = X_SCREEN_TOP+1;
	while (x <= X_SCREEN_BOTTOM-1){
		gotoXY(x, y);
		cout << char(205);
		x++;
	}

	if (y < Y_SCREEN_BOTTOM){
		gotoXY(X_SCREEN_BOTTOM,Y_SCREEN_TOP);
		cout << char(209); // tren ben phai
	}else{
		gotoXY(X_SCREEN_BOTTOM,Y_SCREEN_BOTTOM+1); // duoi ben phai
		cout << char(207);
	}
}

void draw_mini_top_bottom_wall(int y){
	int x = X_SCREEN_BOTTOM+1;
	while (x < X_SCREEN_BOTTOM + 20){
		gotoXY(x, y);
		cout << char(205);
		x++;
	}

	gotoXY(x, y);
	if (y < Y_SCREEN_BOTTOM){
		cout << char(187);
	}else{
		cout << char(188);
	}
}

void draw_score(){
	// ve diem
	gotoXY(X_SCREEN_BOTTOM+5, Y_SCREEN_TOP+4);
	cout << "Length: ";
	gotoXY(X_SCREEN_BOTTOM+13, Y_SCREEN_TOP+4);
	cout << length_of_snake;

	//ve length
	gotoXY(X_SCREEN_BOTTOM+5, Y_SCREEN_TOP+5);
	cout << "Score: ";
	gotoXY(X_SCREEN_BOTTOM+12, Y_SCREEN_TOP+5);
	cout << length_of_snake - 4;

	// ve speed
	gotoXY(X_SCREEN_BOTTOM+5, Y_SCREEN_TOP+6);
	cout << "Speed: ";
	gotoXY(X_SCREEN_BOTTOM+12, Y_SCREEN_TOP+6);
	cout << SPEED;

	//ve food
	gotoXY(X_SCREEN_BOTTOM+5, Y_SCREEN_TOP+7);
	cout << "Food: ";
	gotoXY(X_SCREEN_BOTTOM+12, Y_SCREEN_TOP+7);
	cout << MAX_FOOD - length_of_snake + 4;

}



void draw_block(int &x_block, int &y_block, bool &block_direction, int X[], int Y[]){

	gotoXY(x_block, y_block);
	cout << ' ';

	if (y_block < Y_SCREEN_BOTTOM && block_direction == 0){
		y_block ++;
	}else {
		block_direction = 1;
		y_block --;
		if (y_block == Y_SCREEN_TOP+1){
			block_direction = 0;
		}
	}

	//Kiem tra ran dung vat can
	for (int i = 1; i < length_of_snake; i++){
		if (x_block == X[i] && y_block == Y[i]){
			gamover = true;
		}
	}


	gotoXY(x_block, y_block);
	cout << 'X';
}

void draw_comment(){
	for (int x = Y_SCREEN_TOP; x < Y_SCREEN_BOTTOM+2; x++){
		for (int y = X_SCREEN_TOP; y < X_SCREEN_BOTTOM+1; y++){
			gotoXY(y, x);
			SetColor(2);
			cout << char(219);
		}
	}

	gotoXY(X_SCREEN_BOTTOM/2, Y_SCREEN_BOTTOM/2);
	SetColor(3);
	cout << "GAME OVER";

}


void gate_init(){
	gotoXY(X_GATE,Y_GATE);
	cout << ']';
	gotoXY(X_GATE-51,Y_GATE-5);
	cout << '[';
}

void draw_wall_and_numbers(){
	system("color 70");
	FixConsole();
	srand(time(NULL));
	resizeConsole(HEIGHT, WIDTH);
	ShowCur(0);
	
	draw_left_right_wall(X_SCREEN_TOP);
	draw_left_right_wall(X_SCREEN_BOTTOM);
	draw_left_right_wall(X_SCREEN_BOTTOM+20);
	draw_top_bottom_wall(Y_SCREEN_TOP);
	draw_top_bottom_wall(Y_SCREEN_BOTTOM+1);
	draw_mini_top_bottom_wall(Y_SCREEN_TOP);
	draw_mini_top_bottom_wall(Y_SCREEN_BOTTOM+1);


	draw_score();
	gate_init();

	
}


//Mở rộng sang dùng con trỏ
//Tạo một danh sách các tọa độ gameover