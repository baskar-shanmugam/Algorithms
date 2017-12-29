//============================================================================
// Name        : SymbolTableOrderArr.cpp
// Author      : Baskar Shanmugam
// Version     :
// Copyright   : Your copyright notice
// Description : Ordered Symbol table using dynamic arrays
//============================================================================


#include "SymbolTableOrderArr.h"

template<typename Key, typename Value>
size_t SymbolTableOrderArr<Key, Value>::rank (Key k) {
    size_t h_pos = count;
    size_t l_pos = 0;
    size_t m_pos = 0;

    if (!count) {
        return l_pos;
    }

    while ((l_pos <= h_pos) && (l_pos < count)) {
        m_pos = (l_pos + h_pos)/2;
        if (key[m_pos] == k) {
            return m_pos;
        } else if (key[m_pos] < k) {
            l_pos = m_pos + 1;
        } else {
            h_pos = m_pos - 1;
        }
    }

    return l_pos;
}

template<typename Key, typename Value>
void SymbolTableOrderArr<Key, Value>::put (Key k, Value v) {
    if (count+1 == capacity) {
        resize(capacity*2);
    }

    size_t pos = rank(k);
    size_t mv_pos = count;
    while(pos != mv_pos) {
        key[mv_pos] = key[mv_pos-1];
        val[mv_pos] = val[mv_pos-1];
        mv_pos--;
    }

    key[pos] = k;
    val[pos] = v;

    count++;
}

template<typename Key, typename Value>
Value SymbolTableOrderArr<Key, Value>::get(Key k) {
    size_t pos = rank(k);
    if (key[pos] == k) {
        return val[pos];
    }
    return NULL;
}

template<typename Key, typename Value>
void SymbolTableOrderArr<Key, Value>::deleteEntry(Key k) {
    if (contains(k)) {
        size_t mv_pos = rank(k);

        while(count-1 > mv_pos) {
            key[mv_pos] = key[mv_pos+1];
            val[mv_pos] = val[mv_pos+1];
            mv_pos++;
        }

        key[mv_pos] = Key();
        val[mv_pos] = Value();
        count--;
    }

}

template<typename Key, typename Value>
bool SymbolTableOrderArr<Key, Value>::contains(Key k) {
    size_t pos = rank(k);
    return (key[pos] == k? true: false);
}


int main() {
	std::cout<< "Next Step! All the best"<< std::endl;
	SymbolTableOrderArr<int,int> st(10);
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
	SymbolTableOrderArr<int, std::string> st1(20);
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
