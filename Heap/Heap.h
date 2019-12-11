#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
  MinHeap() = default;
  MinHeap(vector<int> &vect)
    : m_data(vect), m_size(vect.size())
  {
    Create();
  }
  void Insert(int value);
  void Pop();  // 删除堆顶元素
  void Create();

  bool Empty() const
  {
    return m_size == 0;
  }

private:
  void Heapify(size_t idx)
  {
    while (true) {
      auto min_idx = idx;
      auto l_idx = 2 * idx + 1;
      auto r_idx = 2 * idx + 2;
      if (l_idx < m_size && m_data[l_idx] < m_data[idx]) {
        min_idx = l_idx;
      }
      if (r_idx < m_size && m_data[r_idx] < m_data[min_idx]) {
        min_idx = r_idx;
      }
      if (min_idx == idx) {
        break;
      }
      swap(m_data[idx], m_data[min_idx]);
      idx = min_idx;
    }
  }

private:
  vector<int> m_data;
  size_t m_size = 0;
};

void MinHeap::Insert(int value)
{
  m_data.push_back(value);
  ++m_size;
  auto idx = m_size - 1;
  while (idx > 0) {
    auto parent_idx = (idx - 1) / 2;  // 父节点下标
    if (m_data[idx] < m_data[parent_idx]) {
      swap(m_data[idx], m_data[parent_idx]);
      idx = parent_idx;
    } else {
      break;
    }
  }
}

void MinHeap::Pop()
{
  if (--m_size == 0) {
    return;
  }
  m_data[0] = m_data[m_size];
  Heapify(0);
}

void MinHeap::Create()
{
  int idx = (m_size - 1) / 2;  // 第一个非叶子节点
  for (; idx >= 0; --idx) {
    Heapify(idx);
  }
}

#endif // HEAP_H