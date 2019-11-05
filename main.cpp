#include <cassert>
#include <cstdio>
#include <string>
#include <cmath>

void examine_float(float n) {
    assert(sizeof(int) == sizeof(float));
    std::string buf;
    for (int i = 31; i >= 0; i--) {
        if ((*(int*)(&n) >> i) & 1) buf += "1";
        else buf += "0";

        buf += " ";

        if (i == 31) buf += "  ";
        else if (i == 8) buf += "  ";
    }
    printf("%s\n", buf.c_str());
    printf("\n");
}

// возвращает число в десятичной системе счисления. На вход подается число
// в системе счисления от 2 до 16 в виде строки и основание base
int fromBaseToDec(const char* str, int base) {
    int num = 0;
    for(int i = 0; str[i] != 0; i++) {
        printf("str[%d] = %c\n", i, str[i]);
    }
    return num;
}

int from2BaseToDec(const std::string& str) {
    int num = 0;
    for(int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == '1') {
            printf("i = %d, str[i] = %c, pos = %d\n", i, str[i], 
                    (int)(str.size() - i - 1));
            num += pow(2, str.size() - i - 1);
        } else {
            printf("0\n");
        }
    }
    return num;
}

void wrap_Base2Dec(const std::string& str) {
    printf("binary %s\n", str.c_str());
    printf("dec %d\n", from2BaseToDec(str));
}

void wrap_examine(float n) {
    printf("examine %f\n", n);
    examine_float(n);
}

int main(int argc, char *argv[])
{
    wrap_examine(0.0f);
    wrap_examine(-0.0f);
    wrap_examine(1.0f);
    wrap_examine(2.0f);
    wrap_examine(3.0f);
    wrap_examine(30.0f);
    wrap_examine(-1.0f);
    wrap_examine(-1.013f);
    wrap_examine(10.40f);
    wrap_examine(10000.40f);
    wrap_examine(10000.040f);
    wrap_examine(-10000.040f);

    wrap_Base2Dec("1");
    wrap_Base2Dec("000");
    wrap_Base2Dec("001");
    wrap_Base2Dec("010");
    wrap_Base2Dec("011");
    wrap_Base2Dec("100");
    wrap_Base2Dec("101");
    wrap_Base2Dec("110");
    wrap_Base2Dec("111");

    return 0;
}
