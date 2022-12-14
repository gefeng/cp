#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int MAX = (int)1e7;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

void run_case() {
    int N;
    cin >> N;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    
    vector<int> min_prime_divisor(MAX + 1, 0); // similar to sieve
    for(int i = 2; i <= MAX; i++) {
        if(min_prime_divisor[i] == 0) {
            min_prime_divisor[i] = i; 

            for(int j = i + i; j <= MAX; j += i) {
                min_prime_divisor[j] = i; 
            }
        }
    }

    for(auto& p : A) {
        int x = p.first;
        int y = p.second;
        int d = abs(p.first - p.second);

        if(d == 1) {
            cout << -1 << '\n';
            continue;
        }
        if(gcd(x, y) != 1) {
            cout << 0 << '\n';
            continue;
        }

        int k = MAX;
        int cur = d;
        while(cur > 1) {
            int pd = min_prime_divisor[cur]; 
            k = min(k, pd - (x % pd));
            cur /= pd;
        }
        cout << k << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}
