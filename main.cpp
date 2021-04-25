#include <iostream>

#include "AVLTree.hpp"
using namespace itis;
using namespace std;
int main(int /*argc*/, char* /*argv*/[]) {
  AVLTree<std::string> tree;
  tree.insert("a");
  tree.insert("b");
  tree.insert("c");
  tree.insert("d");
  tree.insert("e");
  tree.insert("f");
  tree.insert("g");

  tree.display();
  cout << tree.find_max();
  return 0;
}
