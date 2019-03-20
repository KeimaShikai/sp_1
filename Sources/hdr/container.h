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
    container();
    ~container();
    void fill(const char *fName);
    void change();
    void change(int n, std::stack<double>& in);
    void show();
    void show_iter();
};

#endif
