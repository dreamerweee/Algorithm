/* 设计实现双端队列。
* 你的实现需要支持以下操作：
*   MyCircularDeque(k)：构造函数,双端队列的大小为k。
*   insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
*   insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
*   deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
*   deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
*   getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
*   getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
*   isEmpty()：检查双端队列是否为空。
*   isFull()：检查双端队列是否满了。
*/

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        m_data = new int[k]();
        m_max_size = k;
        m_size = 0;
    }
    ~MyCircularDeque()
    {
        delete [] m_data;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;
        for (int i = m_size; i > 0; --i) {
            m_data[i] = m_data[i - 1];
        }
        m_data[0] = value;
        ++m_size;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;
        m_data[m_size] = value;
        ++m_size;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;
        for (int i = 0; i < m_size - 1; ++i) {
            m_data[i] = m_data[i + 1];
        }
        --m_size;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;
        --m_size;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;
        return m_data[0];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;
        return m_data[m_size-1];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return m_size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return m_size == m_max_size;
    }

private:
    int *m_data;
    int m_max_size;
    int m_size;
};
