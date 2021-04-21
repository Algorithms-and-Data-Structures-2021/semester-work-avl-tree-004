#include <iostream>

#include "AVLTree.hpp"
using namespace std;

int main(int  /*argc*/, char * /*argv*/[]) {
  AVLTree<std::string> tree;
  tree.insert("a");
  tree.insert("b");
  tree.insert("c");
  tree.insert("d");
  tree.insert("e");


  tree.display();



  std::cout<<tree.find("c");
}