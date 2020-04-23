#include<vector>
#include <iostream>
#include <optional>

template <typename T, template <typename E = T, typename Alloc = std::allocator<E>> typename Container = std::vector>
std::optional<size_t> binarySearch( const Container<T, std::allocator<T> > & array, T element)
{
    int begin {};
    int end = array.size();
    int center {(begin + end - 1) / 2};

    while( end - begin > 0){
        if ( element < array[ center ]) {
            end = center;
            center = (begin + end - 1) / 2;
        }
        else if ( element > array[ center ]) {
            begin = center + 1;
            center = (begin + end - 1) / 2;
        }
        else return center;

    }
    return std::optional<size_t> {};

}
