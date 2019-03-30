#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    using std::istringstream;
    /*
    string line;
    while(getline(cin, line)) {
        istringstream in(line);
        string result = "";
        string word;
        while(in >> word) {
            result += word;
            result += "%20";
        }
        result.erase(result.end() - 3, result.end());
        cout << result << endl;
    }
    */

    /*
    string line;
    while(getline(cin, line)) {
        string word;
        string result;
        for(auto i = line.begin(); i != line.end(); i++) {
            if(*i != ' ')
                word += (*i);
            else {
                result += word + "%20";
                word.clear();
            }
        }
        result += word;

        cout << result << endl;
    }
    */

    char str[1000];
    while(fgets(str, 999, stdin) != 0) {

        int cnt = 0, length = 0;
        for(char *ptr = str; *ptr != '\0' && *ptr != '\n'; ++ptr) {
            ++length;
            if(*ptr == ' ')
                cnt++;
        }
        str[length] = '\0';
        int newLength = length + 2 * cnt;
        int q = newLength;
        int p = length;
        str[q] = '\0';

        while(p >= 0 && q >= 0) {
            while(p >= 0 && str[p] != ' ') str[q--] = str[p--];

            str[q--] = '0';
            str[q--] = '2';
            str[q--] = '%';

            --p;
            //--q;
        }
        printf("%s\n", str);
    }
    return 0;
}
