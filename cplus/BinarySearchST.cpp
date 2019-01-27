#include "BinarySearchST.hpp"

int main(void) {
    BinarySearchST<std::string,std::string> st;
    std::cout<< "size: " << st.tableSize();
    st.put("c","get");
    st.put("d","it");
    st.put("e","done");
    st.put("a","hi");
    st.put("b","basky");
    std::cout<< "size: " << st.tableSize();
    std::cout<< "min: " << st.min();
    std::cout<< "max: " << st.max();
    std::cout<< std::endl<< "get: " << st.get("a");
    std::cout<< std::endl<< "get: " << st.get("b");
    std::cout<< std::endl<< "get: " << st.get("c");
    std::cout<< std::endl<< "get: " << st.get("d");
    std::cout<< std::endl<< "get: " << st.get("e");
    std::cout<< std::endl<< "get: " << st.get("h");
    std::cout<< std::endl<< "contain: " << st.contains("h");
    st.show();
    st.deleteKey("e");
    std::cout<< std::endl<< "contain: " << st.contains("e");
    std::cout<< "size: " << st.tableSize();
    st.show();
}