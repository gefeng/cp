#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int sum = 0;
    for(int i = 0; i < N; i++) {
        if(i && i % 2 == 1) {
            sum += A[i] - 1; 
        } else {
            sum += A[i];
        }
    }

    cout << (sum <= X ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
