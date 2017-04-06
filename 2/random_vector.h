#ifndef random_vector_h
#define random_vector_h

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

using namespace std;

std::vector<int> random_vector(int leng, const int low, const int high)
{
    static std::default_random_engine e(time(0));
    static std::uniform_int_distribution<unsigned> u(low, high);

    std::vector<int> vec;
    for (int i = 0; i < leng; i++)
        vec.push_back(u(e));
    return vec;
}

#endif
