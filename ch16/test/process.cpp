//
// Created by Administrator on 2022/10/6.
//
#include <iostream>
#include <memory>

using std::endl;
using std::cout;

int *pInt = nullptr;
void process(std::shared_ptr<int> ptr){

    cout << *ptr << endl;
}

void process2(std::shared_ptr<int> &ptr){

}

void process3(){
    std::shared_ptr<int> ptrInt = std::make_shared<int>(1024);
    pInt = ptrInt.get();
}
template<typename T>
void deI(T *p){
    *p = 0;
}
int main(){
    std::shared_ptr<int> ptr = std::make_shared<int>(1024);
    std::unique_ptr<int> ptr1;
    std::unique_ptr<int> ptr2(new int(1111));
//    std::unique_ptr<int, > u2;
    return 0;
}
