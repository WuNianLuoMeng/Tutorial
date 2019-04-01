#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

bool
match_core(const char *str, const char *pattern)
{
    if(*str == '\0' && *pattern == '\0')
        return true;

    if(*str != '\0' && *pattern == '\0')
        return false;

    if(*str == *pattern || (*str != '\0' && *pattern == '.'))
        return match_core(str + 1, pattern + 1);

    if(*(pattern + 1) == '*') {
        if(*str == *pattern || (*pattern == '.' && *str != '\0'))
            return match_core(str + 1, pattern + 2) ||
                   match_core(str + 1, pattern)     ||
                   match_core(str, pattern + 2);
        else
            return match_core(str, pattern + 2);
    }

    return false;
}

bool
match(const char *str, const char *pattern)
{
    if(str == NULL || pattern == NULL)
        return false;
    return match_core(str, pattern);
}

int
main(int argc, char *argv[])
{
    char buf1[50], buf2[50];
    cin >>buf1 >> buf2;
    cout << match(buf1, buf2) << endl;
    return 0;
}
