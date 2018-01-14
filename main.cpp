#include <iostream>
#include <boost/iterator/function_input_iterator.hpp> 
#include "transform_iterator.h"

struct range_generator{
    typedef int result_type; // required for function iterator
    result_type i = 0;
    result_type end;
    range_generator(result_type end) : end(end) {}
    result_type operator() () { return i++; }
    int size() const { return end; }
};

class range
{
    range_generator generator;
public:
    //typedef boost::function
    range(int end) : generator(end) {}
    auto begin() { return boost::make_function_input_iterator( generator, 0 ); }
    auto end()   { return boost::make_function_input_iterator( generator, generator.size() ); }
    int  size()  { return generator.size(); }
};

int main()
{
	std::cout << "hello world\n";

    //range_generator r;
    //auto beg = boost::make_function_input_iterator(r,0);
    //auto end = boost::make_function_input_iterator(r,10);
    
    for(auto i : range( 12 ))
    {
        std::cout << i << ' ';
    }
    std::cout << "\n\n";
    
    print_transformed();
    
    return 0;
}
