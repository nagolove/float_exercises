#include <cassert>
#include <cstdio>
#include <string>
#include <cmath>
#include <bitset>

void examine_float(float n) {
    assert(sizeof(int) == sizeof(float));
    std::string buf, nospaceBuf;
    for (int i = 31; i >= 0; i--) {
        if ((*(int*)(&n) >> i) & 1) {
            buf += "1";
            if (i < 31 && i > 7) {
            nospaceBuf += "1";
            }
        } else {
            buf += "0";
            if (i < 31 && i > 7) {
            nospaceBuf += "0";
            }
        }

        buf += " ";

        if (i == 31) buf += "  ";
        else if (i == 8) buf += "  ";
    }
    printf("%s\n", buf.c_str());
    printf("nospaceBuf %s\n", nospaceBuf.c_str());
    unsigned long long mant = std::bitset<64>(nospaceBuf).to_ulong();
    printf("mant %llu", mant);
    printf("\n");
}

// возвращает число в десятичной системе счисления. На вход подается число
// в системе счисления от 2 в виде строки
int from2BaseToDec(const std::string& str, int from, int to) {
    int num = 0;
    for(int i = str.size() - 1 + from; i >= 0 + to; i--) {
        if (str[i] == '1') {
            num += pow(2, str.size() - i - 1);
        }
    }
    return num;
}

void wrap_Base2Dec(const std::string& str, int from = 0, int to = 0) {
    printf("binary %s\n", str.c_str());
    printf("dec %d\n", from2BaseToDec(str, 0, 0));
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
    wrap_Base2Dec("000", 0, 3);
    wrap_Base2Dec("001", 0, 3);
    wrap_Base2Dec("010", 0, 3);
    wrap_Base2Dec("011", 0, 3);
    wrap_Base2Dec("100", 0, 3);
    wrap_Base2Dec("101", 0, 3);
    wrap_Base2Dec("110", 0, 3);
    wrap_Base2Dec("111", 1, 3);

    wrap_Base2Dec("1001");
    wrap_Base2Dec("1011");
    wrap_Base2Dec("0011");
    wrap_Base2Dec("1111");

    return 0;
}
