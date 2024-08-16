#include <iostream>
#include <cstdlib>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    int profit = 0,
        min = 0;
    for(size_t i = 0; i<prices.size(); ++i)
    {
        int max = prices[i];
        for(size_t j = i+1; j<prices.size(); ++j)
        {
            if(prices[j] < prices[i])
            {
                profit += max-prices[i];
                i = (--j);
                break;
            }
            if(max<=prices[j])
            {
                max = prices[j];
            } else {
                profit += max-prices[i];
                i = (--j);
            }
            
            if((j == (prices.size()-1)))
            {
                profit += max-prices[i];
                i = j;
            }
        }
    }
    return profit;
}


int main(){
    std::vector<int> vec = {7,1,5,3,6,4};
    int res = maxProfit(vec);

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}