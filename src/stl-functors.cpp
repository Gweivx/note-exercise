// Copyright 2021 Gweivx
/**
 * @file stl-functors.cpp
 * @author Gweivx
 * @brief 使用仿函数作为参数，调用一些STL函数
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>

/**
 * @brief a functor used to mutilple two objs
 * 
 * @tparam T 
 */
template<class T>
class MyMultiple {
 public:
    int operator() (T a, T b) {
        return a * b;
    }
};

/**
 * @brief a functor used to judge if lhs < rhs
 * 
 * @tparam T 
 */
template<class T>
class LessThan {
 public:
    explicit LessThan(const T& t) : rhs(t) {}
    int operator() (T lhs) {
        return lhs < rhs;
    }
 private:
    const T rhs;
};

int main() {
    std::vector<int> v{2, 1, 1, 2, 3, 4};

    int product = std::accumulate(v.begin(), v.end(), 1, MyMultiple<int>());
    std::cout << "product: " << product << std::endl;

    int cnt = std::count_if(v.begin(), v.end(), LessThan<int>(3));
    std::cout << "count, less than 3: " << cnt << std::endl;
}
