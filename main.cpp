#include <iostream>
#include <cassert>

// the code only does 3 variables MAX, with some refactoring of the code and
// making the duplicated logic into functions it could easily add larger numbers of variables

int S_calc(std::string str) {
    //some code here that pulls out the three ints from string by parsing a stopping point
    int l = str.length();
    int a{0};
    std::string strA;
    bool hasA = false;
    int b{0};
    std::string strB;
    bool hasB = false;
    int c{0};
    std::string strC;
    bool hasC = false;
    for (int i = 0; i < l; i++) {
        if (str[i] == ';' || str[i] == ',') {
            if (!hasA) {
                hasA = true;
            }
            else if (!hasB) {
                hasB = true;
            }
            else if (!hasC) {
                hasC = true;
            }
        } else if (isdigit(str[i])) {
            if (!hasA) {
                strA.append(&str[i]);
                a = std::stoi(strA);
            }
            else if (!hasB) {
                strB.append(&str[i]);
                b = std::stoi(strB);
            }
            else if (!hasC) {
                strC.append(&str[i]);
                c = std::stoi(strC);
            }
        } else {
            // for when a non-number or too many numbers, or non-valid chars are entered
            return 0;
        }
    }
    int result = (a + b + c);
    return result;
}

int main() {

    //assert statements go here...
    std::cout << S_calc("1,2,3") << std::endl;
    assert(S_calc("1,2,3") == 6);
    assert(S_calc("") == 0);
    assert(S_calc("0") == 0);
    assert(S_calc("1") == 1);
    assert(S_calc("1,2") == 3);
    assert(S_calc("4,5,6") == 15);
    assert(S_calc("14,5,6") == 25);
    assert(S_calc("a") == 0);
}