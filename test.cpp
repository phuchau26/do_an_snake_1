#include<iostream>
#include "resource.h"
using namespace std;


void draw_comment(){
    // Tô màu cho toàn bộ màn hình là màu xanh
    system("color 100");

    // In một ô có màu xanh
    gotoXY(40,12);
    SetColor(2);
    cout << char(219);

    // In chữ H trên nền xanh
    SetColor(15); // Chọn màu trắng cho chữ
    gotoXY(41, 12); // Di chuyển con trỏ in lên một chút để không bị che phủ bởi ô màu xanh
    cout << "H";
}
void draw_left_right_wall(int x){
	//x = 100, 10
	int y = 2;

	if (x < 20){
		gotoXY(10,1);
		cout << char(201); // tren ben trai
		gotoXY(10,26);
		cout << char(200); // duoi ben trai
	}

	while (y <= 25){
		gotoXY(x, y);
		cout << char(186);
		y++;
	}
}

void draw_top_bottom_wall(int y){
	// y = 1, 26
	int x = 11;
	while (x <= 99){
		gotoXY(x, y);
		cout << char(205);
		x++;
	}

	if (y < 10){
		gotoXY(100,1);
		cout << char(187); // tren ben phai
	}else{
		gotoXY(100,26); // duoi ben phai
		cout << char(188);
	}
}

int main(){
	// draw_left_right_wall(10);
	// draw_left_right_wall(100);
	// draw_top_bottom_wall(1);
	// draw_top_bottom_wall(26);
	draw_comment();
	// // cout << char(188);

  
    Sleep(10000);


    return 0;
}
