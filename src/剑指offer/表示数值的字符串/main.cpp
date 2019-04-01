#include <cstdlib>
#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define MAXLINE 4096

bool
get_unsigned_number(const char **buf)
{
    const char *ptr = *buf;
    while(**buf != '\0' && **buf >= '0' && **buf <= '9') (*buf)++;
    return ptr < *buf;
}

bool
get_signed_number(const char **buf)
{
    if(**buf == '-' || **buf == '+')
        (*buf) ++;
    return get_unsigned_number(buf);
}

bool
is_number(const char *buf)
{
    if(buf == NULL)
        return false;

    bool result = get_signed_number(&buf);

    if(*buf == '.') {
        buf++;

        result  = result || get_unsigned_number(&buf);
    }

    if(*buf == 'e' || *buf == 'E') {
        buf++;
        result = result && get_unsigned_number(&buf);
    }

    return result && *buf == '\0';
}

int
main(int argc, char *argv)
{
    char buf[MAXLINE];

    while(cin >> buf) {
        cout << is_number(buf) << endl;
    }
    return 0;
}
