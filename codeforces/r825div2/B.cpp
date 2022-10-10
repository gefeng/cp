#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    int g = gcd(a, b);
    return a * b / g;
}

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    bool exist = true;
    for(int i = 2; i < N; i++) {
        if(gcd(lcm(A[i - 2], A[i - 1]), lcm(A[i - 1], A[i])) > A[i - 1]) {
            exist = false;
            break;
        }
    }

    cout << (exist ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
