#include <iostream>
#include <cstdlib>
#include <string>


class Solution {
public:
    int calculate(std::string s, int& i) {
        int res = 0,
            temp_num=0;
        char opt = 0;
        for(; i<s.size(); ++i)
        {
            bool is_num = '0'<=s[i]&&s[i]<='9';
            if(is_num)
            {
                temp_num = ((temp_num*10) + (s[i]-'0'));
            }
            if(!is_num || i==(s.size()-1))
            {
                if(s[i]=='(') {
                    temp_num = calculate(s, ++i);
                    ++i;
                }
                if(opt==0 && (i==(s.size()-1) || s[i]!=' ')) {
                    res=temp_num;
                } else if(i<(s.size()-1) && s[i]==' ') {
                    continue;
                } else if(opt =='+') {
                    res+=temp_num;
                } else if(opt =='-') {
                    res-=temp_num;
                }
                if(s[i]=='+'||s[i]=='-') {
                    opt=0;
                    temp_num=0;
                    opt = s[i];
                } else if(s[i]==')') {
                    return res;
                }
            }
        }
        return res;
    }
    int calculate(std::string s) {
        int i = 0;
        return calculate(s,i);
    }
};


int main(){
    std::string s = "1 + 1";

    auto res = Solution().calculate(s);

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}