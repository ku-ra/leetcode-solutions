#include "template.h"

class Solution {
public:
    /*
    Read in and ignore any leading whitespace.
    Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
    Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
    Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
    If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
    Return the integer as the final result.
    //State Machine?
    */
    int myAtoi(string s) {
        int i = 0, n = 0;
        bool p = true;

        while (s[i] == ' ') {
            i++;
        }

        if (s[i] == '-' || s[i] == '+') {
            p = s[i] == '+';
            i++;
        }


        while (s[i] >= '0' && s[i] <= '9') {
            int d = s[i] - '0';

            if (n > INT_MAX / 10 || (n == INT_MAX / 10 && s[i] - '0' > 7))
                return p ? INT_MAX : INT_MIN;

            n = n * 10 + d;
            i++;
        }

        return p ? n : -n;
    }
};