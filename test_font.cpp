#include<iostream>
#include "resource.h"
using namespace std;

void draw_comment(){
	int X[100] = {};
	int Y[100] = {};
	int i = 0;
	for (int y = 1; y < 27; y++){
		for (int x = 10; x < 101; x++){
			gotoXY(x, y);

			// if (x == X[i] && y == Y[i]){
			// 	SetColor(3);
			// 	i++;
			// }

			if (i%2 == 0){
				SetColor(3);
			}else{
				SetColor(15);
			}
			i++;

			cout << char(219);
		}
	}

	SetColor(0);
	for (int x = 1; x < 27; x++){
		gotoXY(7,x);
		cout << x;
	}

	for (int x = 10; x < 101; x++){
		
		int i = 0;
		int k = x;
		
		if (x >= 100){
			gotoXY(x, 27 + i);
			cout << k/100;
			k = k%100;
			i++;
		}

		gotoXY(x, 27+i);
		cout << k/10;
		k = k%10;
		i++;

		gotoXY(x, 27+i);
		cout << k;

	}

	

}


int main(){
	system("color 70");
	draw_comment();
  
    Sleep(100000);


    return 0;
}
