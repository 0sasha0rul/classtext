#include <iostream>
#include "text.hpp"
using namespace std;

int main(){
    cout << "starting to test IBusko::Text by ARylova!" << endl;

    IBusko::Text a = "123";
    IBusko::Text b = "123";
    IBusko::Text c = "Hello";
    IBusko::Text d = "World";
    IBusko::Text e = "World";

    a = e;
    cout << a << endl;

    if (d == e){
        cout << "Equals" << endl;
    }

    if (a != c){
        cout << "Not egual"<< endl;
    }

    cout << c + d << endl;

    cout << a.at(2) << endl;

    c.push_back("World");
    cout << c << endl;


    // чтобы окошко exe-шника не закрывалось автоматически
    cout << endl;
    cout << "ending to test IBusko::Text by ARylova!" << endl;
    int n;
    cin >> n;
    return 0;
}