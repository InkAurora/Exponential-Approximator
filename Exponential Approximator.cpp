#include <iostream>

using namespace std;

double calc(double x) {
    return x * x;
}

double roundA(double x, int precision) {
    int multiplier = pow(10, precision);
    return round(x * multiplier) / multiplier;
}

int main() {
    int precision = 5;
    int a_prec = 1;
    double x = 7;

    while (1) {
        while (1) {
            if (roundA(x, a_prec) != roundA(calc(x), a_prec)) {
                if (x + ((x - calc(x)) / 2) <= 0) {
                    x -= x / 2;
                    continue;
                }
                x += (x - calc(x)) / 2;
            }
            else break;
        }
        a_prec++;
        if (a_prec > precision) break;
    }

    cout << x << endl;

    return 0;
}