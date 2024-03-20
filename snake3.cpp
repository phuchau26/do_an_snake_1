#include <iostream>
#include "resource.h"
using namespace std;
#define MAX 100
void vetuongtren();
void vetuongduoi();
void vetuongtrai();
void vetuongphai();
void vetuong();
void khoitaoran(int X[], int Y[]);
void veran(int X[], int Y[]);
void them(int a[], int x);
void xoa(int a[], int vt);
void xulyran(int X[], int Y[], int x, int y, int &xqua, int &yqua);
void xoadulieucu(int X[], int Y[]);
bool kiemtraranchamtuong(int x0, int y0);
bool kiemtraranchamduoi(int X[], int Y[]);
void taoqua(int &x, int &y, int X[], int Y[]);
bool kiemtrarandequa(int xqua, int yqua, int X[], int Y[]);
bool kiemtrarananqua(int xqua, int yqua, int x0, int y0);

int soluong = 11;
int main(){
	srand(time(NULL));
	int xqua = 0, yqua = 0;
	int X[MAX], Y[MAX];
	vetuong();
	khoitaoran(X, Y);
	veran(X,Y);
	taoqua(xqua, yqua, X, Y);
	int x =50, y =13;
	int check = 2; // 0 xuong 1 len 2 phai 3 trai
	bool gameover = false;
	while (!gameover){
		
		xoadulieucu(X, Y);


		if (_kbhit()){
			char kitu = _getch();
			if (kitu == -32){
				kitu = _getch();
				if (kitu == 72 && check != 0){
					check = 1;
				}else if (kitu == 80 && check != 1){
					check = 0;
				}else if (kitu == 77 && check != 3){
					check = 2;
				}else if (kitu == 75 && check != 2){
					check = 3;
				}
			}
		}

		if (check == 0){
			y++;
		}else if(check ==1){
			y--;
		}else if (check == 2){
			x++;

		}else if (check == 3){
			x--;
		}

		xulyran(X,Y,x,y,xqua, yqua);
		gameover = kiemtraranchamduoi(X, Y) ||  kiemtraranchamtuong(X[0], Y[0]);
		Sleep(100);

	}


	_getch();

	return 0;
}


void vetuongtren(){
	int x = 10, y =1;
	while (x <=100){
		gotoXY(x,y);
		cout << '+';
		x++;
	}
}
void vetuongduoi(){
	int x = 10, y =26;
	while (x <=100){
		gotoXY(x,y);
		cout << '+';
		x++;
	}
}
void vetuongphai(){
	int x = 100, y =1;
	while (y <= 26){
		gotoXY(x,y);
		cout << '+';
		y++;
	}
}
void vetuongtrai(){
	int x = 10, y =1;
	while (y <= 26){
		gotoXY(x,y);
		cout << '+';
		y++;
	}
}

void vetuong(){
	vetuongtren();
	vetuongduoi();
	vetuongtrai();
	vetuongphai();
}

void veran(int X[], int Y[]){
	gotoXY(X[0], Y[0]);
	cout << "0";
	for (int i = 1; i < soluong; i++){
		gotoXY(X[i],Y[i]);
		cout << 'o';
	}
}

void xoadulieucu(int X[], int Y[]){

	for (int i = 0; i < soluong; i++){
		gotoXY(X[i],Y[i]);
		cout << ' ';
	}
}

void khoitaoran(int X[], int Y[]){
	int x =50, y =13;
	for (int i = 0; i < soluong; i++){
		X[i] = x;
		Y[i] = y;
		x--;
	}
}

void xulyran(int X[], int Y[], int x, int y, int &xqua, int &yqua){
	them(X,x);
	them(Y,y);

	if (kiemtrarananqua(xqua, yqua, X[0], Y[0]) == false){
		xoa(X,soluong -1);
		xoa(Y,soluong -1);

	}else{
		taoqua(xqua, yqua, X,Y);
	}


	veran(X,Y);

}

void them(int a[], int x){
	for (int i = soluong; i > 0; i--){
		a[i] = a[i-1];
	}
	a[0] = x;
	soluong++;
}

void xoa(int a[], int vt){
	for (int i = vt; i < soluong; i++){
		a[i] = a[i+1];
	}
	soluong--;
}

bool kiemtraranchamtuong(int x0, int y0){
	if (y0 == 1 || y0 == 26 || x0 == 1 || x0 == 100){
		return true;
	}
	return false;
}

bool kiemtraranchamduoi(int X[], int Y[]){
	for (int i = 1; i < soluong; i++){
		if (X[0] == X[i] && Y[0] == Y[i]){
			return true;
		}
	}
	return false;
}

void taoqua(int &xqua, int &yqua, int X[], int Y[]){

	do{
		xqua = rand()%(99-11+1) +11;
		yqua = rand()%(25-2+1)+2;
	}while(kiemtrarandequa(xqua, yqua, X, Y));
	gotoXY(xqua, yqua);
	cout << '$';
}

bool kiemtrarandequa(int xqua, int yqua, int X[], int Y[]){
	for (int i = 0; i < soluong; i++){
		if (xqua == X[i] && yqua == Y[i]){
			return true;
		}
	}
	return false;
}

bool kiemtrarananqua(int xqua, int yqua, int x0, int y0){
	if (x0 == xqua && y0 == yqua){
		return true;
	}
	return false;
}