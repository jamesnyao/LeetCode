#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Determine whether an integer is a palindrome.
 * An integer is a palindrome when it reads the same backward as forward.
**/
bool isPalindrome(int x) {
    if (x < 0) return false;
    string str = to_string(x);
    for (int i = 0; i < str.length()/2; i++)
    {
        if (str[i] != str[str.length()-1-i]) return false;
    }
    return true;
}

/**
 * Same as above but without converting to string
**/
bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    if (x%10 == 0) return false;
    int tmp;
    for (tmp = 0; tmp < x;)
    {
        if (tmp) tmp *= 10;
        tmp += x%10;
        x /= 10;
    }
    if (tmp == x) return true;
    if (tmp/10 == x) return true;
    return false;
}