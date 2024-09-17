#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


int strStr(std::string haystack, std::string needle) {
    std::vector<int> sub_vals(needle.size(),0);

    for(size_t i=1, j=0; i<sub_vals.size() && j<sub_vals.size();)
    {
        if(needle[i] == needle[j])
        {
            sub_vals[i++] = ++j;
        } else {
            if(j)
            {
                j = sub_vals[j-1];
            } else {
                ++i;
            }
        }
    }

    size_t i=0,
           j=0;
    while(j<haystack.size())
    {
        if(needle[i] == haystack[j])
        {
            ++i;
            ++j;
        }
        if(i==needle.size())
        {
            return j-i;
        }
        if (j < haystack.size() && needle[i] != haystack[j])
        {
            if(i)
            {
                i = sub_vals[i-1];
            } else {
                ++j;
            }
        }
    }
    return -1;
}


int main(){
    std::string haystack = "sadbutsad",
                needle = "sad";

    auto res = strStr(haystack, needle);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}