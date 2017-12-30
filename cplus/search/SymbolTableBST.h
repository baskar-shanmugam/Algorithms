/*
 * SymbolTableBST.h
 *
 *  Created on: 29-Dec-2017
 *      Author: Baskar Shanmugam
 */

#ifndef SYMBOLTABLEBST_H_
#define SYMBOLTABLEBST_H_
#include <iostream>

template<typename Key, typename Value>
class SymbolTableBST {
public:
    SymbolTableBST() {
        root = nullptr;
    }

    virtual ~SymbolTableBST() {}

    // put key-value pair into the tree
    void put(Key key, Value val);

    // value paired with key
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
    class Node {
    public:
        Node(Key k, Value v) {
            key = k;
            val = v;
            count = 1;
            rnode = nullptr;
            lnode = nullptr;
        }
        Key key;
        Value val;
        size_t count;

        Node *rnode;
        Node *lnode;
    };
    Node* root;

    Node* put(Node *n, Key k, Value v) {
        if (n == nullptr) {
            return new Node(k, v);
        }
        if (n->key < k) {
            n->rnode = put(n->rnode, k, v);
        }
        if (n->key > k) {
            n->lnode = put(n->lnode, k, v);
        }
        n->count = 1 + size(n->lnode) + size(n->rnode);
        return n;
    }

    Value get(Node *n, Key k) {
        if (n == nullptr) {
            return NULL;
        }
        if (n->key < k) {
            return get(n->rnode, k);
        }
        if (n->key > k) {
            return get(n->lnode, k);
        }
        return n->val;
    }

    size_t size(Node *n) {
        if (n == nullptr) {
            return 0;
        }
        return n->count;
    }
};

#endif /* SYMBOLTABLEBST_H_ */
