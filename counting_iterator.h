#include <iostream>
#include <boost/iterator/counting_iterator.hpp> 

void print_sequence()
{
    auto beg = boost::counting_iterator<int>(0);
    auto end = boost::counting_iterator<int>(10);

    for(; beg != end; ++beg)
    {
        std::cout << beg << ' ';
    }

}