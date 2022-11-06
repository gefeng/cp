#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL gcd(LL a, LL b) {
    if(a == 0LL) {
        return b;
    }
    return gcd(b % a, a);
}

LL lcm(LL a, LL b) {
    return a * b / gcd(a, b);
}

void run_case() {
    LL N, A, B;
    cin >> N >> A >> B;

    LL sum = (N + 1LL) * N / 2LL;
    
    LL tot_a = N / A;
    LL tot_b = N / B; 
    
    LL AB = lcm(A, B);
    LL tot_ab = N / AB;

    sum -= (A + A * tot_a) * tot_a / 2LL;
    sum -= (B + B * tot_b) * tot_b / 2LL;
    sum += (AB + AB * tot_ab) * tot_ab / 2LL;

    cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
