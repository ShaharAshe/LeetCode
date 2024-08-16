#include <iostream>
#include <cstdlib>
#include <vector>


int maxDistance(std::vector<std::vector<int>>& arrays) {
    int max = arrays[0][arrays[0].size()-1],
        min = arrays[0][0],
        distance = -1;

    for(size_t i = 1; i<arrays.size(); ++i)
    {
        if(distance<std::abs(max-arrays[i][0]))
        {
            distance = std::abs(max-arrays[i][0]);
        }
        if(distance<std::abs(arrays[i][arrays[i].size()-1]-min))
        {
            distance = std::abs(arrays[i][arrays[i].size()-1]-min);
        }
        
        if(arrays[i][0]<min)
            min = arrays[i][0];
        
        if(max<arrays[i][arrays[i].size()-1])
            max = arrays[i][arrays[i].size()-1];
    }

    return distance;
}


int main(){
    std::vector<std::vector<int>> vec = {{1,2,3},{4,5},{1,2,3}};

    int res = maxDistance(vec);

    std::cout << res << std::endl;
}