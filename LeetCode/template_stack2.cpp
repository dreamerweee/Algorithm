#include <iostream>
#include <stdexcept>

template <typename T, int MAXSIZE>
class Stack {
private:
    T elems_[MAXSIZE];
    int size_;

public:
    Stack();
    void push(const T&);
    void pop();
    T top() const;
    bool empty() const
    {
        return size_ == 0;
    }
    bool full() const
    {
        return size_ == MAXSIZE;
    }
};

template <typename T, int MAXSIZE>
Stack<T, MAXSIZE>::Stack() :
    size_(0)
{ }

template <typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(const T &elem)
{
    if (full()) {
        throw std::out_of_range("Stack<>::push() stack is full");
    }
    elems_[size_++] = elem;
}

template <typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::pop()
{
    if (empty()) {
        throw std::out_of_range("Stack<>::pop() stack is empty");
    }
    --size_;
}

template <typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::top() const
{
    if (empty()) {
        throw std::out_of_range("Stack<>::top() stack is empty");
    }
    return elems_[size_ - 1];
}

int main()
{
    Stack<int, 10> int_stack;
    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);
    std::cout << int_stack.top() << std::endl;
    int_stack.pop();
    std::cout << int_stack.top() << std::endl;

    return 0;
}