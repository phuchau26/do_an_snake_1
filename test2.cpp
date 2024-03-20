#include <iostream>
#include <Windows.h>

void opacity_text(const char S[]) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    WORD originalColor = csbi.wAttributes;
    WORD newColor = originalColor & ~(BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
    newColor |= FOREGROUND_GREEN;
    newColor |= BACKGROUND_INTENSITY;

    SetConsoleTextAttribute(hConsole, newColor);
    std::cout << S << std::endl;
    SetConsoleTextAttribute(hConsole, originalColor);
}

int main() {

    opacity_text("Hau");

    Sleep(10000);
    return 0;
}