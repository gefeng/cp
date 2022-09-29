#include <iostream>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    if(N == 2 || N == 3) {
        cout << "NO SOLUTION" << '\n';
        return;
    }

    vector<int> p(N, 0);
    for(int i = 1, j = 1; i < N; i += 2, j++) {
        p[i] = j;
    }
    for(int i = 0, j = N / 2 + 1; i < N; i += 2, j++) {
        p[i] = j;
    }

    for(int i = 0; i < N; i++) {
        cout << p[i] << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
