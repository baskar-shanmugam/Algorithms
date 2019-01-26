#include <iostream>
#include <vector>
#include <memory>

template<typename T>
class MaxPQ {
private:
    std::unique_ptr<std::vector<T> > cont;
    int cont_size;

    void swim(int idx) {
        int pIdx = idx/2;
        while(pIdx > 0) {
            std::cout<< "pIdx: " << pIdx << " idx: " << idx;
            if (cont->at(pIdx) < cont->at(idx)) {
                T tmp = cont->at(pIdx);
                cont->at(pIdx) = cont->at(idx);
                cont->at(idx) = tmp;
                idx = pIdx;
                pIdx = idx/2;
            } else {
                break;
            }
        }
    }

    void sink(int idx) {
        while(2*idx < cont_size) {
            int child = 2*idx;
            int rchild = child +1;
            if (rchild < cont_size)
                if (cont->at(rchild) > cont->at(child))
                    child = rchild;
            if (cont->at(child) > cont->at(idx)) {
                T tmp = cont->at(idx);
                cont->at(idx) = cont->at(child);
                cont->at(child) =  tmp;
                idx = child;
            } else {
                break;
            }
        }
    }

public:   
    MaxPQ() {
        cont = std::unique_ptr<std::vector<T> >(new std::vector<T>(2));
        //cont->insert(cont->begin(), );
        cont->push_back(-1);
        cont_size = 1;
    }

    ~MaxPQ() {}

    void insert(T e) {
        cont->insert(cont->begin()+cont_size,e);
        swim(cont_size);
        cont_size++;
    }

    T max() {
        return cont->at(1);
    }

    T delMax() {
        T top = cont->at(1);
     //   cont->erase(cont->begin()+1);
        cont_size--;
        cont->at(1) = cont->at(cont_size);
        cont->erase(cont->begin()+cont_size);
       // cont_size--;
       // cont->insert(cont->begin()+1, cont->at(cont_size));
        sink(1);
        return top;
    }

    bool isEmpty() {
        return ((cont_size-1) ? true : false);
    }
    int size() {
        return cont_size-1;
    }
    void show() {
        std::cout<< std::endl;
        for (T i: *cont) {
            std::cout<< " T: " << i;
        }
        std::cout<< std::endl;
    }

};