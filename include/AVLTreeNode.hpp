//
// Created by Семен Соколов on 21.04.2021.
//

#ifndef AVLTreeNode_hpp
#define AVLTreeNode_hpp

#include <string>
#include <algorithm>
namespace itis {
  template<class T>

  struct AVLTreeNode {

    AVLTreeNode* right;
    AVLTreeNode* left;
    const T value;
    int count;   // сколько вершин в поддереве
    int height;  // высота

    explicit AVLTreeNode(T value);
    void updateValues();
    int balanceFactor();

    AVLTreeNode* left_rotate();
    AVLTreeNode* right_rotate();
  };
}  // namespace itis

#endif /* AVLTreeNode_hpp */
