#include <bits/stdc++.h>

int main(){
    using namespace std;
    constexpr unsigned long MOD = 998244353;
    size_t N, M;
    cin >> N >> M;
    auto modpow = [&MOD](unsigned long a, unsigned long n, unsigned long b = 1) -> unsigned long{
        auto ret = b % MOD;
        a %= MOD;
        while(n){
            if(n & 1)(ret *= a) %= MOD;
            (a *= a) %= MOD;
            n >>= 1;
        }
        return ret;
    };
    auto modbinomial = [&MOD, &modpow](unsigned long n, unsigned long k) -> unsigned long{
        unsigned long ret = 1, den = 1;
        for(unsigned long i = 1; i <= k; ++i){
            (ret *= (n - i + 1)) %= MOD;
            (den *= i) %= MOD;
        }
        return modpow(den, MOD - 2, ret);
    };
    auto a = modbinomial(MOD - N, 3 * M) + N * modbinomial(MOD - N, M - 1);
    a = M & 1 ? MOD - a % MOD : a % MOD;
    if(M + 1 < N){
        auto ub = min(N, 3 * M), lb = M, sz = (ub - lb) / 2;
        vector<unsigned long> A(sz), B(sz);
        {
            auto k = M + 2;
            auto nn = N, dd = k;
            A[0] = modbinomial(nn, dd);
            for(unsigned long i = 1; i < sz; ++i){
                A[i] = modpow((dd + 1) * (dd + 2), MOD - 2, A[i - 1] * (nn - dd) % MOD * (nn - dd - 1));
                dd += 2;
            }
        }
        {
            auto nn = N - 1 + (3 * M - (ub & ~(ub & 1))) / 2, dd = N - 1;
            B.back() = modbinomial(nn, dd);
            for(unsigned long i = sz - 1; i--; ++nn)B[i] = modpow(nn - dd + 1, MOD - 2, B[i + 1] * (nn + 1));
        }
        a += MOD - inner_product(A.begin(), A.end(), B.begin(), 0UL, plus<>(), [&MOD](auto a, auto b){return a * b % MOD;}) % MOD;
    }
    cout << a % MOD << endl;
    return 0;
}
