/*
 * SymbolTableList.h
 *
 *  Created on: 28-Dec-2017
 *      Author: Baskar Shanmugam
 */
#include <iostream>
#ifndef SYMBOLTABLELIST_H_
#define SYMBOLTABLELIST_H_

template<typename Key, typename Value>
class SymbolTableList {
public:
    SymbolTableList() {
        head = nullptr;
        count = 0;
    }
    virtual ~SymbolTableList();

    // put key-value pair into the table
    // (remove key from table if value is null)
    void put (Key key, Value val);

    // value paired with key
    // (null if key is absent)
    Value get(Key key);

    // remove key(and its value) from table
    void deleteEntry(Key key);

    // is there a value paired with key?
    bool contains(Key key);
    // is the table empty?
    bool isEmpty();

    // number of key-value pairs in the table
    size_t size();

private:
    Value nullitem;
    struct Node {
        Key key;
        Value val;
        Node *link;
    };
    Node *head;
    size_t count;
};

#endif /* SYMBOLTABLELIST_H_ */
