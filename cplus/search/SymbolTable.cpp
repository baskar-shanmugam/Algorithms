//============================================================================
// Name        : SymbolTable.cpp
// Author      : Baskar Shanmugam
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "SymbolTable.h"


template<typename Key, typename Value>
void SymbolTable<Key, Value>::put (Key key, Value val) {
    st.push_back(std::make_pair(key,val));
}

template<typename Key, typename Value>
Value SymbolTable<Key, Value>::get(Key key) {
    //for(std::vector<Key, Value>::iterator it = st.begin(); it != st.end(); ++it) {
    for (auto& entry : st) {
        if (entry.first == key) {
            return entry.second;
        }
    }
	return 0;
}

template<typename Key, typename Value>
void SymbolTable<Key, Value>::deleteEntry(Key key) {
    for(auto it = st.begin(); it != st.end(); ++it) {
        if (it->first == key) {
            st.erase(it);
            return;
        }
    }
}

template<typename Key, typename Value>
bool SymbolTable<Key, Value>::contains(Key key) {
    for (auto& entry : st) {
        if (entry.first == key) {
                return true;
        }
    }
    return false;
}

template<typename Key, typename Value>
bool SymbolTable<Key, Value>::isEmpty() {
    return ((st.size()) == 0)?true:false;
}

template<typename Key, typename Value>
int SymbolTable<Key, Value>::size() {
    return st.size();
}

int main() {
	std::cout<< "Next Step! All the best"<< std::endl;
	SymbolTable<int,int> st;
	std::cout << st.size() << " " << st.isEmpty() << std::endl;
	st.put(10, 1000);
	st.put(20, 20000);
	std::cout << "Key 10: Value: " << st.get(10) << std::endl;
	std::cout << "Key 20: Value: " << st.get(20) << std::endl;
	std::cout << st.size() << " " << st.isEmpty()<< std::endl;
	st.deleteEntry(20);
	std::cout << st.size() << " " << st.isEmpty()<< std::endl;
	st.deleteEntry(10);
	std::cout << st.size() << " " << st.isEmpty()<< std::endl;
	SymbolTable<int, std::string> st1;
	std::cout << st.size() << " " << st.isEmpty() << std::endl;
    st1.put(10, "5000");
    st1.put(20, "7000");
    std::cout << "Key 10: Value: " << st1.get(10) << std::endl;
    std::cout << "Key 20: Value: " << st1.get(20) << std::endl;
    std::cout << st1.size() << " " << st1.isEmpty()<< std::endl;
    st1.deleteEntry(20);
    std::cout << st1.size() << " " << st1.isEmpty()<< std::endl;
    st1.deleteEntry(10);
    std::cout << st1.size() << " " << st1.isEmpty()<< std::endl;

}
