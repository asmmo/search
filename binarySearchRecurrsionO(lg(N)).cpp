#include <vector>
#include <iostream>
#include <optional>

template <typename T, template <typename E = T, typename Alloc = std::allocator<E>> typename Container = std::vector>
std::optional<size_t> binarySearchHelper( const Container<T, std::allocator<T> > & array, T element, size_t begin, size_t end )
{
    if (end - begin == 1)
        if (array[begin] == element) return begin;
        else return std::optional <size_t> {};


    size_t center = (begin + end) / 2;
    if(element < array[ center ]) return binarySearchHelper(array, element, begin, center);
    else if(element > array[ center ]) return binarySearchHelper(array, element, center, end);
    else return center;

}

template <typename T, template <typename E = T, typename Alloc = std::allocator<E>> typename Container = std::vector>
std::optional<size_t> binarySearch( const Container<T, std::allocator<T> > & array, T element)
{
    return binarySearchHelper(array, element, 0, array.size());
}


int main(){
    std::vector vec { -1000};
    std::optional<size_t > res{};
    std::cout <<( (res = binarySearch(vec, -1000) ) ? std::to_string(res.value()) : "non");
}
