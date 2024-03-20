#include<iostream>
#include "resource.h"
using namespace std;

const int X_SCREEN_TOP = 20;
const int Y_SCREEN_TOP = 5;
const int X_SCREEN_BOTTOM = 100;
const int Y_SCREEN_BOTTOM = 25;
const int MAX = 200;
const int MSSV = 8;
const int HEIGHT = 1000;
const int WIDTH = 500;
const int X_BLOCK_1 = 40;
const int X_BLOCK_2 = 60;
const int X_GATE = 70;
const int Y_GATE = 22;
const int SPEED = 100;
const int MAX_FOOD = 5;

int length_of_snake = 4;
// int snake_direction = 0;
// char S[MSSV] = {'2','3','1','2','0','2','5','2'};
// bool gamover = false;

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

void gate_init(){
	gotoXY(X_GATE,Y_GATE);
	cout << ']';
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


int main(){
	
	draw_wall_and_numbers();
  
    Sleep(1000000);


    return 0;
}
