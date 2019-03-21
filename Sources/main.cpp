#include "container.h"
#include <stack>
#include <queue>
#include <vector>
#include <iostream>


template <class T1, class T2 = std::stack<double>>
T2 converter(T1);

void show(std::stack<double>);

void show_iter(std::stack<double>);


int main()
{
    //1
    container<std::stack<double>> sample1;
    sample1.fill("Files/for1");
    //2
    std::cout << "Container A: ";
    show(sample1.get_data());
    //3
    std::cout << "Two items were delited from container A!\n";
    sample1.change(2);
    //4
    std::cout << "Container A*: ";
    show_iter(sample1.get_data());
    //5
    container<std::queue<double>> sample2;
    sample2.fill("Files/for2");
    //6
    int n = 0;
    std::cout << "Input the number of items you want to delete: ";
    std::cin >> n;
    sample1.change(n, converter(sample2.get_data()));
    //7
    std::cout << "Container A: ";
    show(sample1.get_data());
    std::cout << "Container B: ";
    show(converter(sample2.get_data()));
    return 0;
}


template <class T1, class T2>
T2 converter(T1 temp1)
{
    T2 temp2;
    while (!temp1.empty())
    {
        temp2.emplace(temp1.front());
        temp1.pop();
    }
    return temp2;
}

void show(std::stack<double> sample)
{
    //output the stack
    while (!sample.empty())
    {
        std::cout << sample.top() << " || ";
        sample.pop();
    }
    std::cout << std::endl;
}

void show_iter(std::stack<double> sample)
{
    //output the stack via iterators
    //codemonkey was here//
    std::vector<double> vTemp;
    while (!sample.empty())
    {
        vTemp.emplace_back(sample.top());
        sample.pop();
    }
    for (std::vector<double>::iterator it = vTemp.begin();
            it != vTemp.end(); ++it)
        std::cout << *it << " || ";
    std::cout << std::endl;
}
