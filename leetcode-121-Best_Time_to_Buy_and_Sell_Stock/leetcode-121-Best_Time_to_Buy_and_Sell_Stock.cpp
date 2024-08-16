#include <iostream>
#include <cstdlib>
#include <vector>


int maxProfit(std::vector<int>& prices) {
    int profit = 0,min = 0;
    for(size_t i = 0; i<prices.size(); ++i){
        if(i == 0 || prices[i]<min){
            min = prices[i];
        } else {
            continue;
        }
        for(size_t j = i+1; j<prices.size(); ++j){
            if(prices[j]<prices[i] || prices[j]==prices[i])
                continue;
            if(profit<prices[j]-prices[i])
            {
                profit = prices[j]-prices[i];
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