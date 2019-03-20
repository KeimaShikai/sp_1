#include "container.h"

container::container()
{
    size = 0;
}

container::~container()
{

}

void container::fill(std::istream& in)
{
    //TODO fill container with the data from file
}

void container::change(std::istream& in)
{
    //TODO remove one element and change the others
}

void container::change(int n, std::stack<double>& in)
{
    //TODO delete n elements and add all elements from second stack
}

void container::show()
{
    //TODO output the stack
}

void container::show_iter()
{

}
