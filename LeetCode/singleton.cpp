#include <iostream>
#include <mutex>
using namespace std;

// 懒汉模式
// class Singleton {
// public:
//     static Singleton* GetInstance()
//     {
//         if (!m_data) {
//             m_mutex.lock();
//             if (!m_data) {
//                 m_data = new Singleton();
//             }
//             m_mutex.unlock();
//         }
//         return m_data;
//     }
// private:
//     Singleton() = default;
//     static mutex m_mutex;
//     static Singleton *m_data;
// };

// mutex Singleton::m_mutex;
// Singleton* Singleton::m_data = nullptr;

// 懒汉模式
// class Singleton {
// public:
//     Singleton(const Singleton&) = delete;
//     Singleton& operator=(const Singleton&) = delete;
//     static Singleton* GetInstance()
//     {
//         m_mutex.lock();
//         static Singleton instance;
//         m_mutex.unlock();
//         return &instance;
//     }
// private:
//     Singleton() { }
//     static mutex m_mutex;
// };
// mutex Singleton::m_mutex;

// 饿汉模式
class Singleton {
private:
    Singleton() { }
    
    static Singleton instance;

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static Singleton& GetInstance()
    {
        return instance;
    }
};
Singleton Singleton::instance;

int main(void)
{
    Singleton &p_single = Singleton::GetInstance();

    return 0;
}