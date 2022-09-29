#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {

}

int main() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = 0LL;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            ans += A[i - 1] - A[i]; 
            A[i] = A[i - 1];
        }
    }

    cout << ans << '\n';
}
