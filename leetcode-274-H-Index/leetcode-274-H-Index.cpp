#include <iostream>
#include <cstdlib>
#include <vector>

int hIndex(std::vector<int>& citations) {
    int max = -1;

    for (const auto& a:citations)
    {
        if(max<a)
        {
            max = a;
        }
    }
    
    std::vector<int> temp_count;
    temp_count.resize(max+1);

    for(const auto& a:citations)
    {
        for(int i = a; 0<=i; --i)
        {
            ++temp_count[i];
        }
    }
    
    for(int i = max; 0<=i; --i)
    {
        if(i<=temp_count[i])
        {
            return i;
        }
    }

    return 0;
}


int main(){
    std::vector<int> vec = {3,0,6,1,5};
    int res = hIndex(vec);

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}