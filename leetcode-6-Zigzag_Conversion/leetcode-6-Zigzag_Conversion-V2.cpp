#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


std::string convert(std::string s, int numRows) {
    std::vector<std::string> zig;
    zig.resize(numRows);

    size_t i = 0;
    while(i<s.size())
    {
        int row = 0;
        while(i<s.size() && row<numRows)
        {
            zig[row++] += s[i++];
        }
        --row;
        while(i<s.size() && 1<row)
        {
            zig[--row] += s[i++];
        }
    }

    std::string res;
    for(size_t row = 0; row<numRows; ++row)
    {
        res += zig[row];
    }

    return res;
}


int main(){
    std::string s = "PAYPALISHIRING";
    int numRows = 3;

    auto res = convert(s, numRows);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}