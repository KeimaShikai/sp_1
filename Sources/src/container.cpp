#include "container.h"

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

void container::change(int n)
{
    //remove some elements
    for (int i = 0; i < n; ++i)
        sample.pop();

    //change the others
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

void container::change(int n, std::stack<double> in)
{
    //delete n elements
    for (int i = 0; i < n; ++i)
        sample.pop();
    
    //add all elements from second stack
    for (int i = 0; i < in.size(); ++i)
    {
        sample.push(in.top());
        in.pop();        
    }
}

void container::show()
{
    //output the stack
    std::stack<double> temp = sample;
    while (temp.size() != 0)
    {
        std::cout << temp.top() << " || ";
        temp.pop();
    }
    std::cout << std::endl;
}

void container::show_iter()
{
    //TODO output the stack via iterators???
}

std::stack<double> container::get_stack()
{
    return sample;
}
