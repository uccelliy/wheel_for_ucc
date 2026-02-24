#include "RBtree.h"

template <typename T>
RBtree_n<T>::RBtree_n(T val): val(val), color(0), left(nullptr), right(nullptr), parent(nullptr) {
    color = 1;

}

template <typename T>
RBtree_n<T>::~RBtree_n() {
    
}

// 构造函数
template <typename T>
RBtree<T>::RBtree(T root_n): root_n(nullptr) {
    if (root_n == nullptr){
        root_n = new RBtree_n<T>(root_n);
        root_n->color = 1;
    }
}

// 析构函数
template <typename T>
RBtree<T>::~RBtree() {
    
}

// 插入
template <typename T>
void RBtree<T>::insert(T val) {
    RBtree_n<T>* temp_node = root_n; // 获取根节点
    while(temp_node != nullptr){     //寻找插入位置，找到叶子节点
        if(val > temp_node->val){    //找到了右侧插入位置
            if(temp_node->right == nullptr){
                temp_node->right = new RBtree_n<T>(val);
                temp_node->right->color = 0;
                temp_node->right->parent = temp_node;
                if(temp_node->color == 0){
                    fix_tree(temp_node->right);
                }
                break;
            }
            else{                     //没找到继续找
                temp_node = temp_node->right;
            }
        }
        else{
            if(temp_node->left == nullptr){  //找到了左侧插入位置
                temp_node->left = new RBtree_n<T>(val);
                temp_node->left->color = 0;
                temp_node->left->parent = temp_node;
                if(temp_node->color == 0){
                    fix_tree(temp_node->left);
                }
                break;
            }
            else{              //没找到继续找
                temp_node = temp_node->left;
            }
        }
    }
} 

// 删除
template <typename T>
int RBtree<T>::remove(T val) {
    RBtree_n<T>* temp_node = root_n; //寻找待删除节点
    while(temp_node->val != val && temp_node != nullptr){
        if(val > temp_node->val){
            temp_node = temp_node->right;
        }
        else{
            temp_node = temp_node->left;
        }
    }
    if (temp_node){
        bool color_tag = temp_node->color;
        if(temp_node->right == nullptr && temp_node->left ==nullptr){
            if(temp_node == root_n){
                root_n = nullptr;
            }
            else{
                if(temp_node == temp_node->parent->left){
                    temp_node->parent->left = nullptr;
                }
                else{
                    temp_node->parent->right = nullptr;
                }
            }
            delete temp_node;
        }
        if(temp_node->left == nullptr && temp_noed->right != nullptr){
            if(temp_node != root_n){
                if(temp_node->parent->left == temp_node){
                    temp_node->parent->left = temp_node->right;
                    temp_node->right->parent = temp_node->parent;
                }
                else{
                    temp_node->parent->right = temp_node->right;
                    temp_node->right->parent = temp_node->parent;
                }
            }
        }
        else{
            root_n = temp_node->right;
            root_n->parent = nullptr;
        }
        if(temp_node->right == nullptr && temp_node->left != nullptr){
            if(temp_node != root_n){
                if(temp_node->parent->left == temp_node){
                    temp_node->parent->left = temp_node->left;
                    temp_node->left->parent = temp_node->parent;
                }
                else{
                    temp_node->parent->right = temp_node->left;
                    temp_node->left->parent = temp_node->parent;
                }
            }
            else{
                root_n = temp_node->left;
                root_n->parent = nullptr;
            }
        }
        if(temp_node->right != nullptr && temp_node->left != nullptr){
            RBtree_n<T>* sucesor_node = find_sucessor_node(temp_node);
            if (temp_node==temp_node->parent->left){
                temp_node->parent->left = sucesor_node;
                sucesor_node->parent = temp_node->parent;
                sucesor_node->right = temp_node->right;
                succeror_node->left = temp_node->left;
                succesor_node->color = temp_node->color;
                if(succesor_node->right){
                    succesor_node->parent->left = 
                }
            } 
    }
    }}

// 左旋转
template <typename T>
void RBtree<T>::left_rotate(RBtree_n<T>* node) {
    
}

// 右旋转
template <typename T>
void RBtree<T>::right_rotate(RBtree_n<T>* node) {
    
}

template <typename T>
void RBtree<T>::fix_tree(RBtree_n<T>* node) {
    
}

template <typename T>
void RBtree<T>::erase_node(RBtree_n<T>* node) {
    
}

template <typename T>
void RBtree<T>::fix_tree_delete(RBtree_n<T>* node) {
    
}

template <typename T>
RBtree_n<T>* RBtree<T>::find_sucessor_node(RBtree_n<T>* node) {
    return nullptr;
}