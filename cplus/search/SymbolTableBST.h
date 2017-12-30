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

    // smallest key
      Key min() {
          if (root) {
              return min(root);
          }
          return NULL;
      }

      // largest key
      Key max() {
          if (root) {
              return max(root);
          }
          return NULL;
      }

      // largest key less than or equal to key
      Key floor(Key key) {
          return floor(root, key);
      }

      // smallest key greater than or equal to key
      Key ceiling(Key key) {
          return ceiling(root, key);
      }

      // number of keys less than key
      size_t rank(Key key);

      // key of rank k
      Key select(int k);

      // delete smallest key
      void deleteMin() {
          deleteEntry(min());
      }

      // delete largest key
      void deleteMax() {
          deleteEntry(max());
      }

      // number of keys in [lo..hi]
      int size(Key lo, Key hi);

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
    Key min(Node *n) {
        return (n->lnode ==nullptr? n->key:min(n->lnode));
    }
    Key max(Node *n) {
        return (n->rnode ==nullptr? n->key:max(n->rnode));
    }
    Key floor(Node *n, Key k) {
        if (n == nullptr) {
            return NULL;
        }
        if (n->key == k) {
            return k;
        }

        if (n->key < k) {
            Key tmp = floor(n->rnode, k);
            if (tmp == NULL) {
                return n->key;
            } else {
                return tmp;
            }
        }
        if (n->key > k) {
                return floor(n->lnode, k);
        }
        return NULL;
    }
    Key ceiling(Node *n, Key k) {
        if (n == nullptr) {
            return NULL;
        }
        if (n->key == k) {
            return k;
        }

        if (n->key > k) {
            Key tmp = ceiling(n->lnode, k);
            if (tmp == NULL) {
                return n->key;
            } else {
                return tmp;
            }
        }
        if (n->key < k) {
            return ceiling(n->rnode, k);
        }
        return NULL;
    }
};

#endif /* SYMBOLTABLEBST_H_ */
