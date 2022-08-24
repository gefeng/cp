#include <iostream>
#include <array>
#include <vector>

using namespace std;

void run_case() {
    int X, Y, N;
    cin >> X >> Y >> N;
    
    if(Y > X * 3) {
        cout << X * N << '\n';
    } else {
        cout << ((N / 3) * Y + (N % 3) * X) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
