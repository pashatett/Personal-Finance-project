#include <iostream>
using namespace std;
#include <vector>

#include "PF.h"
int main(){
    MyBank obj;
    char c;
    do {
        obj.RegistrMenu();
        cout << "Sozdatb es4e karty?(1/0)";
        cin >> c;
    } while (c != 0);

}