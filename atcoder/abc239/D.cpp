#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
    vector<bool> is_prime(201, true);
    is_prime[1] = false;
    
    for(int i = 2; i <= 200; i++) {
        if(is_prime[i]) {
            for(int j = i + i; j <= 200; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for(int i = A; i <= B; i++) {
        bool ok = true;
        for(int j = C; j <= D; j++) {
            if(is_prime[i + j]) {
                ok = false;
                break;
            } 
        }

        if(ok) {
            cout << "Takahashi" << '\n';
            return;
        }
    }

    cout << "Aoki" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
