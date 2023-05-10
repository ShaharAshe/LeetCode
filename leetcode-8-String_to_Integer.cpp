/* -- Id = 8 -- */

#include <iostream>
#include <string>

int myAtoi(std::string s) {

    int ret_s;
    const int MIN = -2147483648,
              MAX = 2147483647;

    while(s[0] == ' ')
        s.erase(s.begin(), s.begin()+1);

    size_t i = (s[0] == '-' || s[0] == '+')? 1:0;
    ret_s = (s[i] < '0' || s[i] > '9')? 0:(s[i++] - '0');

    for (; i < s.size(); ++i)
    {
        if(s[i] < '0' || s[i] > '9')
            break;

        if(ret_s > MAX/10)
            return (s[0] == '-')? MIN:MAX;
        if(ret_s == MAX/10) {
            if (s[0] == '-'){
                if(s[i] >= '8')
                return MIN;
            } else {
                if (s[i] >= '7')
                    return MAX;
            }
        }

        ret_s *= 10;
        ret_s += (s[i]-'0');
    }

    return (s[0] == '-')? -ret_s: ret_s;
}

int main(int argc, char const *argv[])
{
    std::cout << myAtoi(std::string("42")) << std::endl;
    
    return 0;
}
