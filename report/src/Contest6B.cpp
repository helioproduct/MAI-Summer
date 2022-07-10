#include <bits/stdc++.h>

using complex = std::complex<double>;
using vc = std::vector<complex>;

const int BASE = 10;
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
    
    while ((1 << lg_n) < n)
        ++lg_n;
    
    for (int i = 0; i < n; ++i)
        if (i < rev_bits(i, lg_n))
            swap(a[i], a[rev_bits(i, lg_n)]);
    
    for (int layer = 1; layer <= lg_n; ++layer) {
        int cluster = 1 << layer;
        double phi = (2.0 * PI) / cluster;
        if (invert)
            phi *= -1;
    
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

    if (invert)
        for (int i = 0; i < n; ++i)
            a[i] /= n;
}


std::string fft_mult(const std::string & a, const std::string & b) {
    size_t max_size = std::max(a.size(), b.size());
    size_t n = 1;
    
    while (n < max_size)
        n *= 2;

    n *= 2;
    vc fa(n), fb(n);
    
    for (size_t i = 0; i < a.size(); ++i)
        fa[a.size() - i - 1] = complex(a[i] - '0');
    
    for (size_t i = 0; i < b.size(); ++i)
        fb[b.size() - i - 1] = complex(b[i] - '0');
    
    fft(fa, false);
    fft(fb, false);
    
    for (size_t i = 0; i < n; ++i)
        fa[i] = fa[i] * fb[i];

    fft(fa, true);
    
    std::vector<int> res(n);
    for (size_t i = 0; i < n; ++i)
        res[i] = (int64_t)round(fa[i].real());

    for (size_t i = 0; i < n - 1; ++i) {
        res[i + 1] += res[i] / BASE;
        res[i] %= BASE;
    }
    
    while (res.size() > 1 and res.back() == 0)
        res.pop_back();
    
    std::reverse(res.begin(), res.end());
    std::string ab;
    
    for (int64_t elem : res)
        ab.push_back('0' + elem);
    
    return ab;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string a, b;
    std::cin >> a >> b;
    std::string fft_res = fft_mult(a, b);
    std::cout << fft_res << std::endl;  
    
    return 0;
}