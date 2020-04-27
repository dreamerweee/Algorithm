/*
* 策略模式，由三部分组成：
*   strategy 接口API，基类
*   concrete_strategy  具体的策略，继承自 strategy
*   context  上下文  使用 strategy角色，包含 concrete_strategy 对象，并使用它去实现需求
*/

#include <iostream>
#include <memory>

using namespace std;

class Strategy {
public:
    Strategy()
    {
        cout << "constructor Strategy." << endl;
    }
    virtual ~Strategy()
    {
        cout << "destructor Strategy." << endl;
    }
    virtual void Interface() = 0;
};

class HasC {
public:
    HasC()
    {
        cout << "constructor HasC." << endl;
    }
    ~HasC()
    {
        cout << "destructor HasC." << endl;
    }
};

class ConcreteStrategyA : public Strategy {
public:
    ConcreteStrategyA()
    {
        cout << "constructor ConcreteStrategyA." << endl;
    }
    ~ConcreteStrategyA()
    {
        cout << "destructor ConcreteStrategyA." << endl;
    }
    void Interface()
    {
        cout << "use A." << endl;
    }

private:
    HasC c;
};

class ConcreteStrategyB : public Strategy {
public:
    ConcreteStrategyB()
    {
        cout << "constructor ConcreteStrategyB." << endl;
    }
    ~ConcreteStrategyB()
    {
        cout << "destructor ConcreteStrategyB." << endl;
    }
    void Interface()
    {
        cout << "use B." << endl;
    }
};

class Context {
public:
    Context(unique_ptr<Strategy> ptr) : m_strategy_ptr(move(ptr))
    {
        cout << "constructor Context." << endl;
    }
    ~Context()
    {
        cout << "destructor Context." << endl;
    }
    void DealAction()
    {
        m_strategy_ptr->Interface();
    }
private:
    unique_ptr<Strategy> m_strategy_ptr;
};

int main(void)
{
    unique_ptr<Strategy> ptr(new ConcreteStrategyA());
    Context context(move(ptr));
    context.DealAction();

    unique_ptr<Strategy> ptr2(new ConcreteStrategyB());
    Context context2(move(ptr2));
    context2.DealAction();

    return 0;
}
