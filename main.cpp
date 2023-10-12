#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

const double GOLDEN_RATIO = (1 + sqrt(5)) / 2;

void GOLDEN_RATIO_METOD();
void OPTIMAL_PASSIVE_SEARCH();

#define e 0.1

double func(double x) {
    return cos(x)*tanh(x);
}

void GOLDEN_RATIO_METOD() {
    double a = 1.5, b = 4;
    double x1 = a, x2 = b;
    cout <<"*** The golden ratio method ***\n\n";
    cout <<"Start of the\t\tEnd of the\t\tLength of" <<endl;
    cout <<"interval\t\tinterval\t\tthe interval\t\tf(ak)\t\tf(bk)" <<endl;
    cout <<"(ak)\t\t(bk)\t\t(l)                                 " <<endl;
    cout <<setfill('-') <<setw(120) <<"-" <<endl;
    while (fabs(b - a) > e) {
        cout
            << a << "\t\t"
            << b  << "\t\t"
            << abs(b-a)  << "\t\t"
            << func(a)  << "\t\t"
            << func(b)  << endl;

        x1 = b - (b - a) / GOLDEN_RATIO;
        x2 = a + (b - a) / GOLDEN_RATIO;

        if (func(x1) <= func(x2) )
            b = x2;
        else a = x1;
    }

    cout << "\t\t"
        << a  << "\t\t"
        << b  << "\t\t"
        << abs(b-a);

    if (b-a < e)
        cout <<"\t\tl < epsilon" <<endl;

    cout <<"\nMinimum x = "  <<fixed <<setprecision(3) << (a + b) / 2 <<" +- " <<(b-a)/2 <<endl;
    cout <<endl <<endl;
}

void OPTIMAL_PASSIVE_SEARCH() {
    double a = 1.5, b = 4;
    double x1 = a, x2 = b;
    cout <<"*** Optimal passive search: ***\n\n";
    a = 1.5;
    b = 4;
    int N = 1;
    cout << "Number of\t\tValue of x" <<endl;
    cout << "points(N)\t\tin the min" <<endl;
    cout <<setfill('-') <<setw(50) <<"-" <<endl;

    while ((b - a) / N > e){
        cout << N ;
        double a1 = a, b1 = b;
        double d = (b1 - a1) / (N + 1);
        while (b1 - a1 > 2 * d){
            x1 = a1 + d;
            x2 = b1 - d;
            if (func(x1) <= func(x2)) {
                b1 = x2;
            } else a1 = x1;
        } cout << "\t\t"
              << (b1 + a1)/2
              << " +- "
              << d  << endl;
        N++;
    }
}

int main() {
    GOLDEN_RATIO_METOD();
    OPTIMAL_PASSIVE_SEARCH();
    return 0;
}
