//
// Created by Семен Соколов on 21.04.2021.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "AVLTreeNode.hpp"
namespace itis {
  template<class T>
  struct AVLTree {
   private:
    int _size;
    AVLTreeNode<T>* root;

    void balance(std::vector<AVLTreeNode<T>**> path);
    void display(AVLTreeNode<T>* cur, int depth = 0, int state = 0);

   public:
    AVLTree();
    ~AVLTree();

    void insert(T value);
    void erase(T value);

    void clear();
    bool empty() const;
    int size() const;

    int find(T value) const;

    const T& find_min() const;
    const T& find_max() const;

    void display();
  };
}

#endif /* AVLTree_hpp */