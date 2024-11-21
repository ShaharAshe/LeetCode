#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>


class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> path_val;

        for(size_t i = 0; i<path.size(); ++i)
        {
            std::string temp_path = "";

            while(i<path.size() && path[i]!='/')
            {
                temp_path += path[i++];
            }
            if(temp_path == ".."){
                if(!path_val.empty()) {
                    path_val.pop();
                }
            } else if(temp_path.empty() || temp_path == ".") {
                continue;
            } else {
                path_val.push(temp_path);
            }
        }
        std::string res = "";
        while(!path_val.empty())
        {
            if(!res.empty())
            {
                res='/'+res;
            }
            res = path_val.top()+res;
            path_val.pop();
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