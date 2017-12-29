//============================================================================
// Name        : SymbolTableOrderArr.h
// Author      : Baskar Shanmugam
// Version     :
// Copyright   : Your copyright notice
// Description : Ordered Symbol Table using Arrays
//============================================================================
#ifndef SYMBOLTABLEORDERARR_H_
#define SYMBOLTABLEORDERARR_H_
#include <iostream>
#include <vector>

template<typename Key, typename Value>
class SymbolTableOrderArr {
public:
	//Default Ctor
    SymbolTableOrderArr(size_t cap){
        capacity = cap;
        key = new Key[capacity];
        val = new Value[capacity];
        for (size_t i = 0; i < capacity; i++) {
            key[i] = Key();
            val[i] = Value();
        }
        count = 0;
    }
    // Dtor
    ~SymbolTableOrderArr() {
        delete key;
        delete val;
    }

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
    bool isEmpty() {
        return ((count == 0)?true:false);
    }

    // number of key-value pairs in the table
    size_t size() {
        return count;
    }

    // smallest key
    Key min() {
        if (count) {
            return key[0];
        }
        return NULL;
    }

    // largest key
    Key max() {
        if (count) {
            return key[count-1];
        }
        return NULL;
    }

    // largest key less than or equal to key
    Key floor(Key key);

    // smallest key greater than or equal to key
    Key ceiling(Key key);

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
    Key* key;
    Value* val;
    size_t count;
    size_t capacity;
    Value nullitem;

    void resize(size_t cap) {
        Key* key_tmp = new Key[cap];
        Value* val_tmp  = new Value[cap];
        for (size_t itr = 0; itr < count; itr++) {
            key_tmp[itr] = key[itr];
            val_tmp[itr] = val[itr];
        }
        delete key;
        delete val;
        key = key_tmp;
        val = val_tmp;
        capacity = cap;
    }


};
#endif
