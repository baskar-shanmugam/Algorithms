/*
 * SymbolTableBST.cpp
 *
 *  Created on: 29-Dec-2017
 *      Author: Baskar Shanmugam
 */

#include "SymbolTableBST.h"

template<typename Key, typename Value>
void SymbolTableBST<Key, Value>::put (Key key, Value val) {
    root = put(root, key, val);
}



template<typename Key, typename Value>
Value SymbolTableBST<Key, Value>::get(Key key) {
    return get(root, key);
}

template<typename Key, typename Value>
void SymbolTableBST<Key, Value>::deleteEntry(Key key) {

}

template<typename Key, typename Value>
bool SymbolTableBST<Key, Value>::contains(Key key) {
    return (get(root, key) != NULL)? true:false;
}

template<typename Key, typename Value>
bool SymbolTableBST<Key, Value>::isEmpty() {
    return (root==nullptr?true:false);
}

template<typename Key, typename Value>
size_t SymbolTableBST<Key, Value>::size() {
    return size(root);
}
template<typename Key, typename Value>
size_t SymbolTableBST<Key, Value>::rank(Key key) {
    size_t rk = 0;
    bool match = false;
    if (!contains(key)) {
        return rk;
    }
    rank(root, key, &rk, &match);
    return rk;
}


int main() {
    std::cout<< "Next Step! All the best"<< std::endl;
    SymbolTableBST<int,int> st;
    std::cout << st.size() << " " << st.isEmpty() << std::endl;
    st.put(40, 4000);
    st.put(10, 10000);
    st.put(30, 30000);
    st.put(5,  50000);
    st.put(55, 55000);
    st.put(45, 45000);
    st.put(47, 47000);
    st.put(43, 43000);
    st.put(77, 77000);
    std::cout << st.size() << " " << st.isEmpty()<< std::endl;
    std::cout << "Key 10: Value: " << st.get(10) << std::endl;
    std::cout << "Key 5: Value: " << st.get(5) << std::endl;
    std::cout << "Key 45: Value: " << st.get(45) << std::endl;
    std::cout << "Key 77: Value: " << st.get(77) << std::endl;
    std::cout << "Key 43: Value: " << st.get(43) << std::endl;
    std::cout << "Key 30: Value: " << st.get(30) << std::endl;
    std::cout << st.size() << " " << st.isEmpty()<< std::endl;
    std::cout << "Min Key: " << st.min() << " Max Key: "<< st.max() << std::endl;
    std::cout << "floor of 6: " << st.floor(6) << std::endl;
    std::cout << "floor of 32: " << st.floor(32) << std::endl;
    std::cout << "floor of 29: " << st.floor(29) << std::endl;
    std::cout << "floor of 30: " << st.floor(30) << std::endl;
    std::cout << "floor of 48: " << st.floor(48) << std::endl;
    std::cout << "floor of 78: " << st.floor(78) << std::endl;
    std::cout << "floor of 42: " << st.floor(42) << std::endl;
    std::cout << "ceiling of 42: " << st.ceiling(42) << std::endl;
    std::cout << "ceiling of 56: " << st.ceiling(56) << std::endl;
    std::cout << "contains of 43: " << st.contains(43) << std::endl;
    std::cout << "contains of 77: " << st.contains(77) << std::endl;
    std::cout << "contains of 55: " << st.contains(55) << std::endl;
    std::cout << "contains of 30: " << st.contains(30) << std::endl;
    std::cout << "contains of 40: " << st.contains(40) << std::endl;
    std::cout << "contains of 41: " << st.contains(41) << std::endl;
    std::cout << "rank of 43: " << st.rank(43) << std::endl;
    std::cout << "rank of 77: " << st.rank(77) << std::endl;
    std::cout << "rank of 55: " << st.rank(55) << std::endl;
    std::cout << "rank of 30: " << st.rank(30) << std::endl;
    std::cout << "rank of 40: " << st.rank(40) << std::endl;

 //   st.deleteEntry(20);
    std::cout << st.size() << " " << st.isEmpty()<< std::endl;
 //   st.deleteEntry(10);
    std::cout << st.size() << " " << st.isEmpty()<< std::endl;

/*
    SymbolTableBST<int, std::string> st1;
    std::cout << st.size() << " " << st.isEmpty() << std::endl;
    st1.put(10, "5000");
    st1.put(20, "7000");
    std::cout << "Key 10: Value: " << st1.get(10) << std::endl;
    std::cout << "Key 20: Value: " << st1.get(20) << std::endl;
    std::cout << st1.size() << " " << st1.isEmpty()<< std::endl;
    st1.deleteEntry(20);
    std::cout << st1.size() << " " << st1.isEmpty()<< std::endl;
    st1.deleteEntry(10);
    std::cout << st1.size() << " " << st1.isEmpty()<< std::endl;*/

}

