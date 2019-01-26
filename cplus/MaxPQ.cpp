#include "MaxPQ.hpp"

int main(void) {
    MaxPQ<int> mq;
    std::cout<< " size of mq: " << mq.size();
    mq.insert(80);
    mq.insert(70);
    mq.insert(60);
    std::cout<< "dtop is: " << mq.delMax();
    mq.insert(40);
     mq.show();
    mq.insert(100);
    mq.insert(100);
    std::cout<< "dtop is: " << mq.delMax();
    mq.insert(4);

    mq.show();

    std::cout<< " size of mq: " << mq.size();
    int cnt = mq.size();
    for(int i = 0; i < cnt; i++) {
        std::cout<< std::endl;
         std::cout<< "top is: " << mq.delMax();
        std::cout<< " size of mq: " << mq.size();
        mq.show();
    }
}