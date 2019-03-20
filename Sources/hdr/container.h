#include <stack>
#include <iostream>

#ifndef CONTAINER_H
#define CONTAINER_H

class container
{
private:
    std::stack<double> sample;
    int size;
public:
    container();
    ~container();
    void fill(std::istream& in);
    void change(std::istream& in);
    void change(int n, std::stack<double>& in);
    void show();
    void show_iter();
};

#endif
