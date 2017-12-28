/*
 * SymbolTableListSP.h
 *
 *  Created on: 28-Dec-2017
 *      Author: baskars
 */



#ifndef SYMBOLTABLELISTSP_H_
#define SYMBOLTABLELISTSP_H_
#include <iostream>
#include <memory>

template<typename Key, typename Value>
class SymbolTableListSP {
public:
    SymbolTableListSP() {
        head = nullptr;
        count = 0;
    }
    virtual ~SymbolTableListSP(){}

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
        std::shared_ptr<Node> link;
    public:
        ~Node() {
            std::cout<< "Destructor";
        }
    };
    typedef std::shared_ptr<Node> nodeSP;
    nodeSP head;
    size_t count;
};

#endif /* SYMBOLTABLELISTSP_H_ */
