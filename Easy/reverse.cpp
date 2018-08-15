#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed
 * integer range: [−2^31,  2^31 − 1].
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
**/
int reverse(int x) {
    long ret, tmp;
    for (ret = 0, tmp = (x<0?x*-1:x); ; ret *= 10)
    {
        ret += tmp % 10;
        tmp /= 10;
        if (tmp == 0) break;
    }
    if (ret > 2147483648 || ret < 0) return 0;
    if (x < 0) ret *= -1;
    return (int)ret;
}
