#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>


class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::string res = "";

        for(size_t i = 0; i<path.size(); ++i)
        {
            std::string temp_path = "";

            while(i<path.size() && path[i]!='/')
            {
                temp_path += path[i++];
            }
            if (temp_path == "..") {
                while(!res.empty() && res[res.size()-1]!='/')
                {
                    res.pop_back();
                }
                if(!res.empty())
                {
                    res.pop_back();
                }
            } else if (temp_path.empty() || temp_path == ".") {
                continue;
            } else {
                 if(!res.empty())
                {
                    res+='/';
                }
                res+=temp_path;
            }
        }
        return '/'+res;
    }
};


int main(){
    std::string path = "/home/";

    auto res = Solution().simplifyPath(path);

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}