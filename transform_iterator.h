#include <iostream>
#include <boost/iterator/counting_iterator.hpp> 
#include <boost/iterator/transform_iterator.hpp> 

// https://stackoverflow.com/questions/6971620/sequence-iterator-isnt-there-one-in-boost
template <typename I, typename F>
boost::transform_iterator<
    F,
    boost::counting_iterator<I>>
make_sequence_iterator(I i, F f)
{
    return boost::make_transform_iterator(
        boost::counting_iterator<I>(i), f);
}

struct mult_generator{
    int i;
    mult_generator(int i=0) : i(i) {}
    int operator ++() { return ++i; }
    int operator ==(mult_generator &rhs) { return i == rhs.i; }
    
    int operator*(){return i;}
};

void print_transformed()
{
    //auto mult = [](int i) -> int { return i*2; };
    
    auto beg = boost::counting_iterator<mult_generator>(mult_generator());
    auto end = boost::counting_iterator<mult_generator>(mult_generator(10));

    for(; beg != end; ++beg)
    {
        std::cout << *beg << ' ';
    }
    std::cout << "\n\n";
}