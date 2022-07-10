#include <bits/stdc++.h>

// using namespace std;

using complex = std::complex<double>;
using vc = std::vector<complex>;

const double PI = std::acos(-1);

void fft(vc & a, bool invert) {
    size_t n = a.size();
    if (n == 1)
        return;
    
    vc a0(n / 2), a1(n / 2);
    for (size_t i = 0, j = 0; j < n; ++i, j += 2) {
        a0[i] = a[j];
        a1[i] = a[j + 1];
    }
    
    fft(a0, invert);
    fft(a1, invert);
    
    double phi = 2.0 * PI / n;
    
    if (invert)
        phi = -phi;
    
    complex w(1), wn(std::cos(phi), std::sin(phi));
    
    for (size_t i = 0; i < n / 2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[n / 2 + i] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2.0;
            a[n / 2 + i] /= 2.0;
        }
        w *= wn;
    }
}

int logbase(double a, double base)
{
   return log(a) / log(base);
}


int main()
{
    int n;
    int new_n;
    
    std::cin >> n;

    new_n = n;
    if (n != pow(2, logbase(n, 2))) {
        new_n = pow(2, logbase(n, 2) + 1);
    }


    vc a(new_n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    fft(a, false);

    for (int i = 0; i < new_n; i++) {
        std::cout << std::fixed << std::setprecision(10) << a[i].real() << " " << a[i].imag() << std::endl;
    }

}
