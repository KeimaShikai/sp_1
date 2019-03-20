#include <stack>
#include <iostream>
#include <fstream>

#ifndef CONTAINER_H
#define CONTAINER_H

class container
{
private:
    std::stack<double> sample;

public:
    container() {}
    ~container() {}
    void fill(const char *fName);
    void change(int n);
    void change(int n, std::stack<double> in);
    void show();
    void show_iter();
    std::stack<double> get_stack();
};

#endif
