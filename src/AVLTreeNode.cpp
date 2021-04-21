//
// Created by Семен Соколов on 21.04.2021.
//

#include "AVLTreeNode.hpp"
namespace itis {
  template<class T>
  AVLTreeNode<T>::AVLTreeNode(T value) : right(nullptr), left(nullptr), value(value), count(1), height(1) {}

  template<class T>
  void AVLTreeNode<T>::updateValues() {
    count = (left != nullptr ? left->count : 0) + (right != nullptr ? right->count : 0) + 1;

    height = std::max(left != nullptr ? left->height : 0, right != nullptr ? right->height : 0) + 1;
  }

  template<class T>
  int AVLTreeNode<T>::balanceFactor() {
    return (left != nullptr ? left->height : 0) - (right != nullptr ? right->height : 0);
  }

  template<class T>
  AVLTreeNode<T>* AVLTreeNode<T>::left_rotate() {
    AVLTreeNode* R = right;
    right = right->left;
    R->left = this;

    this->updateValues();  // the order is important
    R->updateValues();

    return R;
  }

  template<class T>
  AVLTreeNode<T>* AVLTreeNode<T>::right_rotate() {
    AVLTreeNode* L = left;
    left = left->right;
    L->right = this;

    this->updateValues();  // the order is important
    L->updateValues();

    return L;
  }

  template struct AVLTreeNode<int>;
  template struct AVLTreeNode<short>;
  template struct AVLTreeNode<long>;
  template struct AVLTreeNode<long long>;
  template struct AVLTreeNode<std::string>;
}