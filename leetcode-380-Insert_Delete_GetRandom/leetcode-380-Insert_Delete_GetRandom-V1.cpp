#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>


class RandomizedSet {
public:
    RandomizedSet(){}
    
    bool insert(int val) {
        if(this->m_vals.find(val) != this->m_vals.end())
            return false;
        this->m_vals.emplace(std::make_pair(val, true));
        return true;
    }
    
    bool remove(int val) {
        if(this->m_vals.find(val) == this->m_vals.end())
            return false;
        this->m_vals.erase(this->m_vals.find(val));
        return true;
    }
    
    int getRandom() {
        auto it = this->m_vals.begin();
        int random = rand()%this->m_vals.size();
        std::advance(it, random);
        return it->first;
    }
private:
    std::unordered_map<int, bool> m_vals;
};



int main(){
    RandomizedSet* randomizedSet = new RandomizedSet();

    // std::vector<std::string> operations = {"RandomizedSet","insert","getRandom","getRandom","getRandom","insert","insert","insert","insert","insert","getRandom","getRandom","insert","getRandom","insert","insert","getRandom","getRandom","getRandom","getRandom","remove","insert","getRandom","getRandom","insert","remove","remove","insert","getRandom","getRandom","insert","insert","getRandom","remove","remove","insert","remove","getRandom","getRandom","remove","getRandom","insert","insert","getRandom","remove","remove","remove","getRandom","insert","insert","insert","insert","getRandom","insert","getRandom","remove","insert","insert","insert","getRandom","getRandom","insert","getRandom","insert","insert","getRandom","getRandom","remove","getRandom","remove","insert","getRandom","insert","insert","insert","getRandom","insert","insert","getRandom","insert","getRandom","insert","getRandom","getRandom","getRandom","insert","getRandom","getRandom","insert","insert","insert","getRandom","remove","insert","insert","getRandom","insert","insert","insert","insert"};

    // std::vector<std::vector<int>> inputs = {{},{-7},{},{},{},{6},{7},{10},{3},{8},{},{},{-8},{},{6},{-8},{},{},{},{},{2},{2},{},{},{5},{-5},{-8},{-8},{},{},{-4},{10},{},{7},{-1},{8},{-6},{},{},{9},{},{7},{0},{},{-10},{-4},{-3},{},{-4},{-5},{8},{-2},{},{-9},{},{7},{-2},{7},{4},{},{},{-6},{},{-8},{2},{},{},{9},{},{-1},{3},{},{0},{-3},{-1},{},{-8},{-10},{},{3},{},{4},{},{},{},{-10},{},{},{0},{-2},{5},{},{-2},{5},{10},{},{9},{0},{7},{-2}};

    // std::vector<std::string> operations = {"RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"};

    // std::vector<std::vector<int>> inputs = {{},{1},{2},{2},{},{1},{2},{}};

    std::vector<std::string> operations = {"RandomizedSet","insert","insert","remove","insert","remove","getRandom"};

    std::vector<std::vector<int>> inputs = {{},{0},{1},{0},{2},{1},{}};

    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i] == "insert") {
            std::cout << "insert(" << inputs[i][0] << ") -> " << randomizedSet->insert(inputs[i][0]) << std::endl;
        } else if (operations[i] == "remove") {
            std::cout << "remove(" << inputs[i][0] << ") -> " << randomizedSet->remove(inputs[i][0]) << std::endl;
        } else if (operations[i] == "getRandom") {
            std::cout << "getRandom() -> " << randomizedSet->getRandom() << std::endl;
        }
    }
    
    return EXIT_SUCCESS;
}