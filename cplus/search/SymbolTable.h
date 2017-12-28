//============================================================================
// Name        : SymbolTable.h
// Author      : Baskar Shanmugam
// Version     :
// Copyright   : Your copyright notice
// Description : UnOrdered Sysmbol Table
//============================================================================

#include <vector>

template<typename Key, typename Value>
class SymbolTable {
public:
	//Default Ctor
    SymbolTable(){}

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
    int size();

private:
    std::vector<std::pair<Key, Value> > st;

};
