#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i]; 
    }

    vector<int> bits(10, 0);
    for(int x : A) {
        for(int i = 0; i < 10; i++) {
            bits[i] += (x & (1 << i)) == 0 ? 0 : 1;
        }
    }

    int min_v = 0;
    int max_v = 0;

    for(int i = 0; i < 10; i++) {
        if(bits[i] == N) {
            min_v |= 1 << i; 
        }
    }

    for(int i = 0; i < 10; i++) {
        if(bits[i] > 0) {
            max_v |= 1 << i;
        }
    }

    cout << max_v - min_v << '\n';
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
