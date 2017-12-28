/*
 * SymbolTableList.cpp
 *
 *  Created on: 28-Dec-2017
 *      Author: Baskar Shanmugam
 */

#include "SymbolTableList.h"

template<typename Key, typename Value>
SymbolTableList<Key, Value>::~SymbolTableList () {
    while(head) {
        Node *temp = head->link;
        delete head;
        head = temp;
    }
}

template<typename Key, typename Value>
void SymbolTableList<Key, Value>::put (Key key, Value val) {
    if (head == nullptr) {
        head = new Node;
        head->key = key;
        head->val = val;
        head->link = nullptr;
    } else {
        Node *temp = new Node;
        temp->key = key;
        temp->val = val;
        temp->link = head;
        head = temp;
    }
    count++;
}

template<typename Key, typename Value>
Value SymbolTableList<Key, Value>::get(Key key) {
    if (!head) {
        return nullitem;
    } else {
        Node *temp = head;
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
void SymbolTableList<Key, Value>::deleteEntry(Key key) {
    if (!head) {
        return;
    } else {
        Node *temp = head;
        Node *prev = head;
        while(temp) {
            if (temp->key == key) {
                if (temp != head) {
                    prev->link = temp->link;
                } else {
                    temp = head;
                    head = head->link;
                }
                delete temp;
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
bool SymbolTableList<Key, Value>::contains(Key key) {
    if (!head) {
        return false;
    } else {
        Node *temp = head;
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
bool SymbolTableList<Key, Value>::isEmpty() {
    return (head == nullptr? true: false);
}

template<typename Key, typename Value>
size_t SymbolTableList<Key, Value>::size() {
    return count;
}

int main() {
    std::cout<< "Next Step! All the best"<< std::endl;
    SymbolTableList<int,int> st;
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
    SymbolTableList<int, std::string> st1;
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
