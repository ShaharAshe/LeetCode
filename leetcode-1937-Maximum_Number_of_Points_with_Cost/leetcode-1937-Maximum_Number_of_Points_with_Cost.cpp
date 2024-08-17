#include <iostream>
#include <cstdlib>
#include <vector>


long long maxPoints(std::vector<std::vector<int>>& points) {
    long long sum = -1;
    std::vector<long long> temp_vec(points[0].size(), 0);

    for(size_t r = 0; r<points.size(); ++r)
    {
        for(int c = 0; c<points[r].size(); ++c)
        {
            temp_vec[c] += points[r][c];
        }
        
        for(int c = 1; c<points[r].size(); ++c)
        {
            if(temp_vec[c-1]-1 < temp_vec[c])
                temp_vec[c] = temp_vec[c];
            else
                temp_vec[c] = temp_vec[c-1]-1;
        }

        for(int c = points[r].size()-2; c>=0; --c)
        {
            if(temp_vec[c+1]-1 < temp_vec[c])
                temp_vec[c] = temp_vec[c];
            else
                temp_vec[c] = temp_vec[c+1]-1;
        }
    }

    for(size_t i = 0; i<temp_vec.size(); ++i)
    {
        if(sum < temp_vec[i])
            sum = temp_vec[i];
    }
    return sum;
}

int main(){
    // std::vector<std::vector<int>> vec = {{1,2,3},{1,5,1},{3,1,1}};
    std::vector<std::vector<int>> vec = {{1,5},{2,3},{4,2}};

    // std::vector<std::vector<int>> vec = {{0,3,0,4,2},{5,4,2,4,1},{5,0,0,5,1},{2,0,1,0,3}};
    // std::vector<std::vector<int>> vec = {{10,8,8,9,5,7,9,8},{6,8,7,2,7,7,4,3},{10,4,8,7,10,3,4,7},{1,4,3,4,5,5,8,1},{2,2,3,6,2,3,1,6},{6,5,8,7,6,0,3,6}};

    long long res = maxPoints(vec);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}