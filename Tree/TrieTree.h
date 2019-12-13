#ifndef TRIE_TREE_H
#define TRIE_TREE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieTree {
public:
  typedef struct TrieNode {
    char m_data;
    vector<TrieNode*> m_child;
    TrieNode(const char c) : m_data(c), m_child(26, nullptr) { }
  }TrieNode;

  TrieTree() : m_root(new TrieNode('/')) { }
  ~TrieTree();

  void Insert(const string &str);
  bool Search(const string &str) const;

  void Print() const
  {
    Print(m_root);
  }

private:
  void Destroy(TrieNode *node)
  {
    if (!node) {
      return;
    }
    for (int i = 0; i < 26; ++i) {
      Destroy(node->m_child[i]);
    }
    delete node;
  }

  void Print(TrieNode *node) const
  {
    cout << node->m_data;
    for (int i = 0; i < 26; ++i) {
      if (node->m_child[i]) {
        Print(node->m_child[i]);
      }
    }
  }

private:
  TrieNode *m_root;
};

TrieTree::~TrieTree()
{
  Destroy(m_root);
}

void TrieTree::Insert(const string &str)
{
  TrieNode *curr = m_root;
  auto len = str.size();
  for (size_t i = 0; i < len; ++i) {
    size_t idx = str[i] - 'a';
    if (curr->m_child[idx] == nullptr) {
      curr->m_child[idx] = new TrieNode(str[i]);
    }
    curr = curr->m_child[idx];
  }
}

bool TrieTree::Search(const string &str) const
{
  TrieNode *curr = m_root;
  auto len = str.size();
  for (size_t i = 0; i < len; ++i) {
    size_t idx = str[i] - 'a';
    if (!curr->m_child[idx]) {
      return false;
    }
    curr = curr->m_child[idx];
  }
  return true;
}

#endif // TRIE_TREE_H