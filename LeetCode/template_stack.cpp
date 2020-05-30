#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
class Stack {
private:
    std::vector<T> elems_;
public:
    void push(const T &);
    void pop();
    T top() const;
    bool empty() const
    {
        return elems_.empty();
    }
};

template <typename T>
void Stack<T>::push(const T &elem)
{
    elems_.push_back(elem);
}

template <typename T>
void Stack<T>::pop()
{
    if (empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elems_.pop_back();
}

template <typename T>
T Stack<T>::top() const
{
    if (empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems_.back();
}

int main()
{
    Stack<int> my_stack;
    if (my_stack.empty()) {
        std::cout << "empty stack" << std::endl;
    }
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);
    for (int i = 0; i < 3; ++i) {
        std::cout << my_stack.top() << std::endl;
        my_stack.pop();
    }

    return 0;
}