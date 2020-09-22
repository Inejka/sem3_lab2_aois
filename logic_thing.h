//
// Created by inejka on 22.09.2020.
//

#ifndef SEM3_LAB2_AOIS_LOGIC_THING_H
#define SEM3_LAB2_AOIS_LOGIC_THING_H
#include <iostream>
#include <string>

class logic_thing {
    bool matr[4][8];
    std::string wtf(int, int );
public:
    logic_thing(std::string);
    void print();
    std::string SDNF,SKNF,binary_SDNF,binary_SKNF,decimal_SDNF,decimal_SKNF;
    int index;
};


#endif //SEM3_LAB2_AOIS_LOGIC_THING_H
