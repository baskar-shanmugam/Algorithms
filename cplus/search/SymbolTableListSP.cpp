/*
 * SymbolTableListSP.cpp
 *
 *  Created on: 28-Dec-2017
 *      Author: baskars
 */

#include "SymbolTableListSP.h"


template<typename Key, typename Value>
void SymbolTableListSP<Key, Value>::put (Key key, Value val) {
    if (head == nullptr) {
        head = std::make_shared<Node>();
        head->key = key;
        head->val = val;
        head->link = nullptr;
    } else {
        nodeSP temp = std::make_shared<Node>();
        temp->key = key;
        temp->val = val;
        temp->link = head;
        head = temp;
    }
    count++;
}

template<typename Key, typename Value>
Value SymbolTableListSP<Key, Value>::get(Key key) {
    if (!head) {
        return nullitem;
    } else {
        nodeSP temp = head;
        while(temp) {
            if (temp->key == key) {
                return temp->val;
            } else {
                temp = temp->link;
            }
        }
        return nullitem;
    }

}

template<typename Key, typename Value>
void SymbolTableListSP<Key, Value>::deleteEntry(Key key) {
    if (!head) {
        return;
    } else {
        nodeSP temp = head;
        nodeSP prev = head;
        while(temp) {
            if (temp->key == key) {
                if (temp != head) {
                    prev->link = temp->link;
                } else {
                    temp = head;
                    head = head->link;
                }
                count--;
                return;
            } else {
                prev = temp;
                temp = temp->link;
            }
        }
    }
}

template<typename Key, typename Value>
bool SymbolTableListSP<Key, Value>::contains(Key key) {
    if (!head) {
        return false;
    } else {
        nodeSP temp = head;
        while(temp) {
            if (temp->key == key) {
                return true;
            } else {
                temp = temp->link;
            }
        }
        return false;
    }
}

template<typename Key, typename Value>
bool SymbolTableListSP<Key, Value>::isEmpty() {
    return (head == nullptr? true: false);
}

template<typename Key, typename Value>
size_t SymbolTableListSP<Key, Value>::size() {
    return count;
}

int main() {
    std::cout<< "Next Step! All the best"<< std::endl;
    SymbolTableListSP<int,int> st;
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

    SymbolTableListSP<int, std::string> st1;
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

