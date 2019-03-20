#include "container.h"

int main()
{
    //1
    container sample1;
    sample1.fill("Sources/items/for1");
    //2
    std::cout << "Container A: ";
    sample1.show();
    //3
    sample1.change(2);
    //4???
    std::cout << "Container A: ";
    sample1.show();
    //5
    container sample2;
    sample2.fill("Sources/items/for2");
    //6
    int n = 0;
    std::cout << "Input the number of items you want to delete: ";
    std::cin >> n;
    sample1.change(n, sample2.get_stack());
    //7
    std::cout << "Container A: ";
    sample1.show();
    std::cout << "Container B: ";
    sample2.show();
    return 0;
}
