#include <iostream>
#include "my_string.h"

int main() {
    String s = "Hello, world!";
    std::cout << s.size() << "\n";
    std::cout << s.find(',') << "\n";
    std::cout << s.substr(7, 5) << "\n";
    return 0;
}
