#include <iostream>
#include <locale.h>
#include <windows.h>
setlocale(LC_ALL, "ru");
#include <locale.h>
    char numbers[] = {'I','II','III','IV','V','VI','VII','VIII','IX','X', '\0'};

using namespace std;

int main() 
{ 
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(12510);
    cout << "привет" << endl;
    return 0; 
}