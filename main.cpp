#include <iostream>
#include "text.hpp"
using namespace std;

int main(){
    cout << "starting to test IBusko::Text by ARylova!" << endl;

    IBusko::Text a = "123";
    IBusko::Text b = "123";
    
    cout << a.at(2);

    // чтобы окошко exe-шника не закрывалось автоматически
    cout << endl;
    cout << "ending to test IBusko::Text by ARylova!" << endl;
    int n;
    cin >> n;
    return 0;
}