#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const int MAX = (int)3e6;

vector<bool> is_p;

void run_case() {
    LL N;
    cin >> N;

    /*for(int i = 2; i <= MAX; i++) {
        if(!is_p[i]) continue;

        LL x = 1LL * i * i;
        if(N % x == 0) {
            cout << i << ' ' << N / x << '\n';
            return;
        }
    } 

    for(int i = 2; i <= MAX; i++) {
        if(!is_p[i]) continue;

        if(N % i == 0) {
            cout << i << ' ' << (LL)sqrt(N / i) << '\n';
            return;
        }
    }*/
    
    for(int i = 2; i <= MAX; i++) {
        if(N % i == 0) {
            LL x = 1LL * i * i;
            if(N % x == 0) {
                cout << i << ' ' << N / x << '\n';
            } else {
                cout << (LL)sqrt(N / i) << ' ' << i << '\n'; 
            }
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    /*is_p.resize(MAX + 1, true);
    is_p[0] = false;
    is_p[1] = false;
    
    for(int i = 2; i <= MAX; i++) {
        if(is_p[i]) {
            for(int j = i + i; j <= MAX; j += i) {
                is_p[i] = false;
            }
        }
    }*/

    while(T--) {
        run_case();
    }
}
