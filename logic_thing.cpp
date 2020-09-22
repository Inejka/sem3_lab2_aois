//
// Created by inejka on 22.09.2020.
//

#include "logic_thing.h"

using namespace std;

logic_thing::logic_thing(string expression) {
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
            for (int c = 0; c < 2; c++) {
                string expression1 = expression;
                matr[0][a * 4 + b * 2 + c] = a;
                matr[1][a * 4 + b * 2 + c] = b;
                matr[2][a * 4 + b * 2 + c] = c;
                for (int i = 0; i < expression1.size(); i++)
                    if (expression1[i] == 'a')expression1[i] = (a + '0');
                    else if (expression1[i] == 'b')expression1[i] = (b + '0');
                    else if (expression1[i] == 'c')expression1[i] = (c + '0');
                while (expression1.size() != 1) {
                    for (int i = 0; i < expression1.size(); i++) {
                        if (expression1[i] == '!' && (expression1[i + 1] == '1' || expression1[i + 1] == '0')) {
                            expression1[i + 1] = (!((bool) (expression1[i + 1] - '0')) + '0');
                            expression1.erase(expression1.begin() + i);
                            break;
                        }
                        if ((expression1[i] == '*' || expression1[i] == '+') &&
                            ((expression1[i - 1] == '0' || expression1[i - 1] == '1') &&
                             (expression1[i + 1] == '0' || expression1[i + 1] == '1'))) {
                            if (expression1[i] == '*')
                                expression1[i + 2] = ((bool) (expression1[i - 1] - '0') &&
                                                      (bool) (expression1[i + 1] - '0')) + '0';
                            else
                                expression1[i + 2] =
                                        ((bool) (expression1[i - 1] - '0') || (bool) (expression1[i + 1] - '0')) + '0';
                            expression1.erase(i - 2, 4);
                            break;
                        }
                    }
                    matr[3][a * 4 + b * 2 + c] = expression1[0] - '0';
                }
            }
    for (int i = 0; i < 8; i++)
        if (matr[3][i]) {
            SDNF += ('(' + wtf(0, i) + "*" + wtf(1, i) + "*" + wtf(2, i) + ")+");
            binary_SDNF += ((char) (matr[0][i] + '0'));
            binary_SDNF += (char) (matr[1][i] + '0');
            binary_SDNF += (char) (matr[2][i] + '0');
            binary_SDNF += '+';
        } else {
            SKNF += ('(' + wtf(0, i) + '+' + wtf(1, i) + '+' + wtf(2, i) + ")*");
            binary_SKNF += ((char) (matr[0][i] + '0'));
            binary_SKNF += (char) (matr[1][i] + '0');
            binary_SKNF += (char) (matr[2][i] + '0');
            binary_SKNF += '*';

        }
    SDNF.erase(SDNF.size() - 1, 1);
    SKNF.erase(SKNF.size() - 1, 1);
    binary_SDNF.erase(binary_SDNF.size() - 1, 1);
    binary_SKNF.erase(binary_SKNF.size() - 1, 1);
}

void logic_thing::print() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++)
            cout << matr[i][j] << ' ';
        cout << endl;
    }

}

std::string logic_thing::wtf(int i, int j) {
    string tmp;
    if (i == 0)tmp = "a";
    if (i == 1)tmp = "b";
    if (i == 2)tmp = "c";
    if (!matr[i][j])tmp = "!" + tmp;
    return tmp;
}
