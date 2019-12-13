#include "TrieTree.h"

int main()
{
    TrieTree my_trie;
    my_trie.Insert("how");
    my_trie.Insert("hi");
    my_trie.Insert("hello");
    my_trie.Insert("her");
    my_trie.Insert("so");
    my_trie.Insert("see");
    my_trie.Print();
    cout << boolalpha << my_trie.Search("how") << endl;
    return 0;
}