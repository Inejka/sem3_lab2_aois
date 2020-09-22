#include <iostream>
#include "logic_thing.h"
using namespace std;
int main() {
    logic_thing a("!((!a+b)*!(!a*c))");
    a.print();
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < 2 ; j++)
            for(int k = 0 ; k  < 2 ; k++){
                bool a = i , b = j , c = k ;
                cout << !((b||!c)&&!(!b&&!c));
            }
    cout << endl << a.SDNF << endl << a.SKNF << endl << a.binary_SDNF << endl << a.binary_SKNF;
}
