#include <cassert>
#include <cstdio>
#include <string>

//#define CHECK_BIT(variable, pos) ((int)(variable) & (1 << pos))

void examine_float(float n) {
    assert(sizeof(int) == sizeof(float));
    std::string buf;
    for (int i = 31; i >= 0; i--) {
        if ((*(int*)(&n) >> i) & 1) buf += "1";
        else buf += "0";

        buf += " ";

        if (i == 0) buf += "  ";
        else if (i == 8) buf += "  ";
    }
    printf("%s\n", buf.c_str());
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
    wrap_examine(-1.0f);
    wrap_examine(-1.013f);
    wrap_examine(10.40f);
    return 0;
}
