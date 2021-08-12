#include <iostream>


int main() 

{
    int sum = 0, i = 50, max = 100;
    while (i <= max) {
        sum += i;
        i++;
    } 
    std::cout << "Sum: " << sum << std::endl;

    int k = 10;
    while (k >= 0) {
        std::cout << "k: " << k << std::endl;
        k--;
    }

    std::cout << "Enter two numbers: " << std::endl;
    int left, right;
    std::cin >> left >> right;
    if (left <= right) {
        while (left <= right) {
            std::cout << "val: " << left << std::endl;
            left++;
        }
    } else {
        while (left >= right) {
            std::cout << "val: " << left << std::endl;
            left--;
        }
    }
    
    return 0;
}
