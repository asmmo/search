#include<vector>
#include <iostream>
#include <optional>

template <typename T, template <typename E = T, typename Alloc = std::allocator<E>> typename Container = std::vector>
std::optional<size_t> binarySearch( const Container<T, std::allocator<T> > & array, T element)
{
    int begin {};
    int end = array.size();
    int center;

    while( end - begin > 0){
        center = (begin + end - 1) / 2;
        if ( element < array[ center ])  end = center;
        else if ( element > array[ center ]) begin = center + 1;
        else return center;

    }
    return std::optional<size_t> {};
}

int main(){
    std::vector vec { -7000, -1000, 7, 8};
    std::optional<size_t > res{};
    std::cout <<( (res = binarySearch(vec, -1000) ) ? std::to_string(res.value()) : "non");
}
