#include <iostream>
#include <fstream>
#include <vector>


#ifndef CONTAINER_H
#define CONTAINER_H

template <class T1>
class container
{
private:
    T1 sample;

public:
    container() {}
    ~container() {}
    void fill(const char *fName);
    void change(int n);
    void change(int n, int index, T1 in);
    T1 get_data();
};

template <class T1>
void container<T1>::fill(const char *fName)
{
    //fill container with the data from file
    std::ifstream is(fName);
    if (!is.is_open())
    {
        std::cout << "Can't open the '" << *fName << "' file!\n";
        exit(0);
    }
    else
    {
        for(double d; is >> d;)
            sample.emplace(d);
    }
    is.close();
}

template <class T1>
void container<T1>::change(int n)
{
    //remove some elements
    for (int i = 0; i < n; ++i)
        sample.pop();

    //change the others
    std::cout << "Now change other " << sample.size() << " elements.\n";
    T1 temp;
    double elem = 0;
    for (int i = 0; i < sample.size(); ++i)
    {
        std::cout << "New " << i + 1 << " element: ";
        std::cin >> elem;
        temp.emplace(elem);
    }
    std::swap(sample, temp);
}

template <class T1>
void container<T1>::change(int n, int index, T1 in)
{
    //delete n elements
    int counter = 0;
    if (index < 0 && index > sample.size())
    {
        std::cout << "The index is out of range!\n";
    }
    else if ((index + n) > sample.size())
    {
        std::cout << "The number is too big!\n"
                  << "The program wiil delete all items in the stack!\n";
        counter = sample.size();
    }
    else
    {
        counter = index + n;
    }

    if (counter != 0)
    {
        std::vector<double> vTemp;
        while (!sample.empty())
        {
            vTemp.emplace_back(sample.top());
            sample.pop();
        }
        vTemp.erase(vTemp.begin() + index, vTemp.begin() + counter);
        while (!vTemp.empty())
        {
            sample.emplace(vTemp.back());
            vTemp.pop_back();
        }
    }

    //add all elements from second stack
    while (!in.empty())
    {
        sample.emplace(in.top());
        in.pop();
    }
}

template <class T1>
T1 container<T1>::get_data()
{
    return sample;
}

#endif
