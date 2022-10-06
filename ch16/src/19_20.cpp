//
// Created by Administrator on 2022/9/14.
//
/**
 * 题目：
 * 编写函数，接收一个容器的引用，打印容器中的元素
 */
/**
 * 待优化：
 * #issue1：模板实例化时接收嵌套了容器的容器,operator<< 无法正常处理容器内的容器元素。
 * 方案1：采用递归，边界条件为容器内元素为非容器对象。
 * 暂时无法通过编译
*/

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <deque>
#include <type_traits>
#include <string>

using std::cout;
using std::endl;

template<typename T>
void print_Container(const T &contain){
    for(auto it = contain.cbegin(); it != contain.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

//针对issue1进行优化
template<typename T,typename... Types>
class IsContainer{
    public:
    static const bool value = false;
    };

template<typename T,typename... Types>
class IsContainer<std::list<T,Types...>> {
public:
    static const bool value = true;
};


template<typename T,typename... Types>
class IsContainer<std::vector<T,Types...>>{
public:
    static const bool value = true;
};

//获取容器类型的模板
template<typename T, typename... Types>
constexpr bool is_container = IsContainer<T, Types...>::value;


//template<typename T>
//void print_Container_Optimize(const T &contain){
//    for (auto it = contain.begin(); it != contain.end(); ++it) {
//        auto item = *it;
//       if(is_container<decltype(item)>){
//           print_Container_Optimize(item);
//       } else
//    }
//    cout << endl;
//}
int main(){
    std::string string = "Stringxxxx";
    print_Container(string);

    std::vector<std::string> vs = {string, string, "Wexxx"};
//    print_Container_Optimize(vs);

    std::vector<std::vector<std::string>> vvs = {vs, vs, vs};
//    print_Container_Optimize(vvs);
    return 0;
}