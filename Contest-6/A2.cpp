#include <bits/stdc++.h>

using complex = std::complex<double>;
using vc = std::vector<complex>;
const double PI = std::acos(-1);

int rev_bits(int x, int lg_n) {
    int y = 0;
    for (int i = 0; i < lg_n; ++i) {
        y = y << 1;
        y ^= (x & 1);
        x = x >> 1;
    }
    return y;
}


void fft(vc & a, bool invert) 
{
    int n = a.size();
    int lg_n = 0;
    
    while ((1 << lg_n) < n) {
        ++lg_n;
    }
    
    for (int i = 0; i < n; ++i) {
        if (i < rev_bits(i, lg_n)) {
            swap(a[i], a[rev_bits(i, lg_n)]);
        }
    }
    
    for (int layer = 1; layer <= lg_n; ++layer) {
        int cluster = 1 << layer;
        double phi = (2.0 * PI) / cluster;
        if (invert) {
            phi *= -1;
        }
    
        complex wn = complex(std::cos(phi), std::sin(phi));
    
        for (int i = 0; i < n; i += cluster) {
            complex w(1);
            for (int j = 0; j < cluster / 2; ++j) {
                complex u = a[i + j];
                complex v = a[i + j + cluster / 2] * w;
                a[i + j] = u + v;
                a[i + j + cluster / 2] = u - v;
                w *= wn;
            }
        }
    }

    if (invert) {
        for (int i = 0; i < n; ++i) {
            a[i] /= n;
        }
    }
}

int logbase(double a, double base)
{
   return log(a) / log(base);
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
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