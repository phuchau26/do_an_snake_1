#include <iostream>
#include "resource.h"
using namespace std;
#define MAX 100

int soluong = 5, huong = 0;
char S[12] = {'2','3','1','2','0','2','5','2','2','3','1','2'};

void ve_tuong_tren(){
	int x = 10, y = 1;
	while (x <= 100){
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}

void ve_tuong_duoi(){
	int x = 10, y = 26;
	while (x <= 100){
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}

void ve_tuong_phai(){
	int x = 100, y = 1;
	while (y <= 26){
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}

void ve_tuong_trai(){
	int x = 10, y = 1;
	while (y <= 26){
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}

void khoi_tao_ran(int X[], int Y[]){
	int x = 50, y = 13;
	for (int i = 0; i < soluong; i++){
		X[i] = x;
		Y[i] = y;
		x --;

	}

}

void ve_ran(int X[], int Y[]){

	for (int i = 0; i < soluong; i++){
		gotoXY(X[i], Y[i]);
		cout << S[i];
	}


}

void xoa_cu(int X[], int Y[]){

	gotoXY(X[soluong-1], Y[soluong-1]);
	cout << " ";


}


void them(int A[], int n, int x){
	for (int i = n; i > 0; i--){
		A[i] = A[i-1];
	}
	A[0] = x;
	soluong ++;
}

void xoa(int A[], int n, int vt){
	for (int i = vt; i < n; i++){
		A[i] = A[i+1];
	}
	soluong --;
}

bool kiemtraRanAn(int x, int y, int xq, int yq){
	if (xq == x && yq == y){
		return true;
	}
	return false;
}

bool kiemtraRanchamQua(int xq, int yq, int X[], int Y[]){

	for (int i = 0; i < soluong; i++){
		if ((xq == X[i]) && yq == Y[i]){
			return true;
		}
	}

	return false;

}


void taoThucAn(int &x, int &y, int X[], int Y[]){
	
	x = rand()%(99-11+1) +11;
	y = rand()%(25-1+1) +2;

	do{
		gotoXY(x, y);
		cout << 0;
	}while(kiemtraRanchamQua(x, y, X, Y));

}


void xuly_ran(int X[], int Y[], int x, int y, int xq, int yq){

	xoa_cu(X, Y);

	them(X, soluong, x);
	them(Y, soluong, y);

	if(kiemtraRanAn(X[0], Y[0], xq, yq)){
		soluong += 1;
		taoThucAn(xq, yq, X, Y);
	}

	xoa(X, soluong,soluong-1);
	xoa(Y, soluong,soluong-1);

	ve_ran(X, Y);

}

bool kiemtraRan(int x0, int y0){
	if (y0 == 1 || y0 == 26 || x0 == 10 || x0 == 100){
		return true;
	}
	return false;
}

bool kiemtraRanchamDuoi(int X[], int Y[]){
	for (int i = 1; i < soluong; i++){
		if (X[0] == X[i] && Y[0] == Y[i]){
			return true;
		}
	}
	return false;
}




int main(){
	srand(time(NULL));

	bool gamover = false;

	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_phai();
	ve_tuong_trai();

	int x = 50, y = 13;
	 // 1 la len, 0 la xuong, 2 qua trai, 3 qua phai

	int X[MAX], Y[MAX];
	khoi_tao_ran(X, Y);
	ve_ran(X, Y);

	//Tao thuc an
	int xq = 0, yq = 0;
	taoThucAn(xq, yq, X, Y);

	while (gamover == false){

		//Dieu khien
		if (_kbhit()){
			char kitu = _getch();
			if (kitu == -32){
				kitu = _getch();
				if (kitu == 72 && huong != 0){ //len
					huong = 1;
				}else if (kitu == 80 && huong != 1){ //xuong
					huong = 0;
				}else if (kitu == 75 && huong != 3 ){ // trai
					huong = 2;
				}else if (kitu == 77 && huong != 2){ //phai
					huong = 3;
				}

			}

			if (kitu == 'w'){
				huong = 1;
			}else if (kitu == 's'){
				huong = 0;
			}else if (kitu == 'a'){
				huong = 2;
			}else if (kitu == 'd'){
				huong = 3;
			}
		}

		if (huong == 1){
			y --;
		}else if (huong == 0){
			y ++;
		}else if (huong == 2){
			x -=3;
		}else if (huong == 3){
			x+=3;
		}

		if (Y[0] == 26){
			huong = 1;
		}else if(Y[0] == 1){
			huong = 0;
		}else if (X[0] == 15){
			huong = 3;
		}else if (X[0] == 90){
			huong = 2;
		}

		//Kiem tra ran cham tuong hay duoi
		gamover = (kiemtraRan(X[0], Y[0]) || kiemtraRanchamDuoi(X, Y));

		xuly_ran(X, Y, x, y, xq, yq);
		Sleep(100);

	}




	_getch();
	return 0;
}