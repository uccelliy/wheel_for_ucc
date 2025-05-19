#include "RBtree.h"

template <typename T>
RBtree_n<T>::RBtree_n(T val): val(val), color(0), left(nullptr), right(nullptr), parent(nullptr) {
    color = 1;

}

template <typename T>
RBtree_n<T>::~RBtree_n() {
    
}

template <typename T>
RBtree<T>::RBtree(T root_n): root_n(root_n) {
    
}