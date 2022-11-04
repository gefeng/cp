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

    int min_v = 1e9;
    for(int x : A) {
        min_v = min(min_v, x);
    }

    if(A[0] == min_v) {
        cout << "Bob" << '\n';
    } else {
        cout << "Alice" << '\n';
    }
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
