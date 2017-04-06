#ifndef SortAlgo_h
#define SortAlgo_h

#include <vector>
#include <iostream>
#include <random>
#include <ctime>

#include "random_vector.h"

using namespace std;

template <typename Comparable>
void insertionSort( vector<Comparable> & a, int left, int right )
{
    for( int p = left + 1; p <= right; ++p )
    {
        Comparable tmp = std::move( a[ p ] );
        int j;

        for( j = p; j > left && tmp < a[ j - 1 ]; --j )
            a[ j ] = std::move( a[ j - 1 ] );
        a[ j ] = std::move( tmp );
    }
}

#endif
