#include "container.h"

container::container()
{

}

container::~container()
{

}

void container::fill(const char *fName)
{
    //fill container with the data from file
    std::ifstream is(fName);
    if (!is.is_open())
        std::cout << "Can't open the '" << *fName << "' file!\n";
    else
        for(double d; is >> d;)
            sample.push(d);
    is.close();
}

void container::change()
{
    //remove one element
    sample.pop();

    //change the others
    //TODO how to change elements in stack smart (CHECK!)
    std::stack<double> temp;
    double elem = 0;
    for (int i = 0; i < sample.size(); ++i)
    {
        std::cout << "New " << i + 1 << " element: ";
        std::cin >> elem;
        temp.push(elem);
    }
    std::swap(sample, temp);
}

void container::change(int n, std::stack<double>& in)
{
    //delete n elements
    for (int i = 0; i < n; ++i)
        sample.pop();
    
    //TODO add all elements from second stack
    
}

void container::show()
{
    //TODO output the stack
}

void container::show_iter()
{
    //TODO output the stack via iterators
}
