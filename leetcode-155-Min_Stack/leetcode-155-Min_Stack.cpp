#include <iostream>
#include <cstdlib>
#include <vector>


class MinStack {
public:
    MinStack() : m_stack_capacity(0), m_stack_size(0) {}
    
    void push(int val) {
        int min_temp = val;
        if(this->m_stack_size && this->m_stack[this->m_stack_size-1].second<min_temp)
        {
            min_temp = this->m_stack[this->m_stack_size-1].second;
        }
        if(this->m_stack_size<this->m_stack_capacity)
        {
            this->m_stack[this->m_stack_size++] = std::make_pair(val,min_temp);
        } else {
            this->m_stack.emplace_back(std::make_pair(val,min_temp));
            ++this->m_stack_capacity;
            ++this->m_stack_size;
        }
    }
    
    void pop() {
        --this->m_stack_size;
        if(this->m_stack_size<0)
        {
            this->m_stack_size = 0;
        }
    }
    
    int top() {
        return this->m_stack[this->m_stack_size-1].first;
    }
    
    int getMin() {
        return this->m_stack[this->m_stack_size-1].second;
    }
private:
    std::vector<std::pair<int,int>> m_stack;
    size_t m_stack_size,
           m_stack_capacity;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main(){
     MinStack* obj = new MinStack();
     obj->push(-2);
     obj->push(0);
     obj->push(-3);
     std::cout << obj->getMin() << std::endl;
     obj->pop();
     std::cout << obj->top() << std::endl;
     std::cout << obj->getMin() << std::endl;

     return EXIT_SUCCESS;
}