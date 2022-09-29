#include <iostream>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N + 1, 0);
    for(int i = 0; i < N - 1; i++) {
        int X;
        cin >> X;
        A[X] = 1;
    }
    
    for(int i = 1; i <= N; i++) {
        if(!A[i]) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
