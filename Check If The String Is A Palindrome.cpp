#include <bits/stdc++.h> 

#include <cctype>

bool checkPalindrome(string s)

{

    int left = 0, right = s.length() - 1;

    while (left < right) {

        while (left < right && !isalnum(s[left]))

            left++;

        while (left < right && !isalnum(s[right]))

            right--;

        if (tolower(s[left++]) != tolower(s[right--]))

            return false;

    }

    return true;

}
