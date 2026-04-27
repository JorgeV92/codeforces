#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    // Golden ratio
    double phi = ((1 + sqrt(5)) / 2);
    return round(pow(phi, n) / sqrt(5));
}

int main() {
    cout << fib(7) << '\n';
    cout << fib(9) << '\n';
    cout << fib(11) << '\n';
}