#include <iostream>
#include <memory>

template<typename K, typename V>
class BinarySearchST {
private:
    std::unique_ptr<K[]> key;
    std::unique_ptr<V[]> val;
    int cont_size;
    int size;

    void resize() {

        auto tmpk = std::unique_ptr<K[]>(new K[size*2]());
        auto tmpv = std::unique_ptr<V[]>(new V[size*2]());
        for (int i = 0; i < size; i++) {
            tmpk[i] = key[i];
            tmpv[i] = val[i];
        }
        delete[] key.release();
        delete[] val.release();
        key = std::move(tmpk);
        val = std::move(tmpv);
        cont_size = size*2;
    }

public:
    BinarySearchST() {
        key = std::unique_ptr<K[]>(new K[10]());
        val = std::unique_ptr<V[]>(new V[10]());
        cont_size = 10;
        size = 0;
    }
    ~BinarySearchST() {

    }
    int tableSize() {
        return size;
    }

    void put(K k, V v) {
        if (size+1 == cont_size) {
            resize();
        }
        int idx = rank(k);
        std::cout<< "\n rank idx: " << idx <<std::endl;
        if (contains(k)) {
            std::cout<< "\n Present Already: " << std::endl;
            val[idx] = v;
        } else {
            for (int i = size-1; i >= idx; i--) {
                key[i+1] = key[i];
                val[i+1] = val[i];
            }
            key[idx] = k;
            val[idx] = v;
            size++;
        }
    }

    V get(K k) {
        int idx = rank(k);
        if (key[idx] == k) {
            return val[idx];
        }
        return V();
    }

    void deleteKey(K k) {
        if (contains(k)) {
            int idx = rank(k);
            for (int i = idx; i < size; i++) {
                key[i] = key[i+1];
                val[i] = val[i+1];
            }
            size--;
        }
        return;
    }

    bool contains(K k) {
        int idx = rank(k);
        if (key[idx] == k)
            return true;
        else
            return false;
    }

    bool isEmpty() {
        return (size?false:true);
    }

    K min() {
        return key[0];
    }
    
    K max() {
        return key[size-1];
    }

    K floor(K k) {
        int idx = rank(k);
        if (idx == 0) {
            return k;
        } else {
            return key[idx-1];
        }
    }

    K cieling(K k) {
        int idx = rank(k);
        if (idx == (size-1)) {
            return k;
        } else {
            return key[idx+1];
        }
    }

    int rank(K k) {
        int high = size;
        int low = 0;
        int mid = (low + high)/ 2;
        while (high > low) {
            if (k > key[mid]) {
                low = mid + 1;
            } else if (k < key[mid]) {
                high = mid - 1;
            } else {
                break;
            }
            mid = (low + high)/2;
        }
        return mid;
    }

    //K select(int k) {
    //
    //}
    void deleteMin() {
        delete(key[0]);
    }
    void deleteMax() {
        delete(key[size-1]);
    }
    int keyRangeSize(K lo, K hi) {
        return (rank(hi) - rank(lo));
    }
    // iterator keys(Key lo, Key hi)
    // iterator keys()
    void show() {
        for(int i = 0; i < size; i++) {
            std::cout<< std::endl;
            std::cout<< "key: " << key[i] << " val: " << val[i] << std::endl;
        }
    }

};