//
// Created by Administrator on 2022/10/6.
//
#include "./_M_STL.h"

struct _base_A{
    virtual inline
    void print(){
        cout << _base_A << endl;
    }
private:
    int _base_A = 0;
};

struct A:public _base_A{
    virtual inline
    void print(){
        cout << _a << endl;
    }
private:
    int _a = 1;
};

int main(){
    std::shared_ptr<A> ptr = std::make_shared<A>();
    std::shared_ptr<_base_A> ptr1(ptr);
    ptr1->print();
    return 0;
}
