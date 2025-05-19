#pragma once

template <typename T>
class RBtree_n{
    public:
        RBtree_n(T val){}
        ~RBtree_n(){}
        RBtree_n* left;
        RBtree_n* right;
        RBtree_n* parent;
        bool color; // 0 for red, 1 for black
        T val;
    private:
};

template <typename T>
class RBtree{
    public:
        RBtree(T root_n){}
        ~RBtree(){}
        void insert(T val){}
        int remove(T val){}
        void left_rotate(RBtree_n<T>* node){}
        void right_rotate(RBtree_n<T>* node){}
        void fix_tree(RBtree_n<T>* node){}
        void erase_node(RBtree_n<T>* node){}
        void fix_tree_delete(RBtree_n<T>* node){}
        RBtree_n<T>* find_sucessor_node(RBtree_n<T>* node){}
        RBtree_n<T>* root_n; // root node
    private:
};