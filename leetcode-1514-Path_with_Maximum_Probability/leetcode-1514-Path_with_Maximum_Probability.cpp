#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cmath>


double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start_node, int end_node) {
    std::vector<double> relax;
    std::queue<int> need_to_visit;
    std::vector<std::vector<std::pair<int, double>>> graph(n);
    
    for (int i = 0; i < edges.size(); ++i) {
        graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
        graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
    }
    
    need_to_visit.push(start_node);

    relax.resize(n, -1);
    relax[start_node] = 0;

    while(!need_to_visit.empty())
    {
        for(size_t v = 0; v<graph[need_to_visit.front()].size(); ++v)
        {
            double node_total = 0;
            
            node_total = relax[need_to_visit.front()];
            node_total += -1*(std::log2(graph[need_to_visit.front()][v].second));

            if(relax[graph[need_to_visit.front()][v].first] == -1 || relax[graph[need_to_visit.front()][v].first] > node_total)
            {
                relax[graph[need_to_visit.front()][v].first] = node_total;
                need_to_visit.push(graph[need_to_visit.front()][v].first);
            }
        }
        need_to_visit.pop();
    }

    if(relax[end_node]==-1)
    {
        return 0;
    }
    
    return std::pow(2,(-1*relax[end_node]));
}


int main(){
    // int n = 3;
    // std::vector<std::vector<int>> edges = {{0,1},{1,2},{0,2}};
    // std::vector<double> succProb = {0.5,0.5,0.2};
    // int start_node = 0;
    // int end_node = 2;

    // int n = 5;
    // std::vector<std::vector<int>> edges = {{2,3},{1,2},{3,4},{1,3},{1,4},{0,1},{2,4},{0,4},{0,2}};
    // std::vector<double> succProb = {0.06, 0.26, 0.49, 0.25, 0.2,  0.64, 0.23, 0.21, 0.77};
    // int start_node = 0;
    // int end_node = 3;

    // int n = 3;
    // std::vector<std::vector<int>> edges = {{0,1}};
    // std::vector<double> succProb = {0.5};
    // int start_node = 0;
    // int end_node = 2;

    // int n = 5;
    // std::vector<std::vector<int>> edges = {{1,4},{2,4},{0,4},{0,3},{0,2},{2,3}};
    // std::vector<double> succProb = {0.37,0.17,0.93,0.23,0.39,0.04};
    // int start_node = 3;
    // int end_node = 4;

    // int n = 3;
    // std::vector<std::vector<int>> edges = {{0,1},{1,2},{0,2}};
    // std::vector<double> succProb = {0.5,0.5,0.2};
    // int start_node = 0;
    // int end_node = 2;

    int n = 3;
    std::vector<std::vector<int>> edges = {{0,1},{1,2},{0,2}};
    std::vector<double> succProb = {0.5,0.5,0.3};
    int start_node = 0;
    int end_node = 2;

    double res = maxProbability(n, edges, succProb, start_node, end_node);

    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}