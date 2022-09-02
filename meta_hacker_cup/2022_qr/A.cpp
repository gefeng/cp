#include <iostream>
#include <fstream>
#include <vector>
#include <array>

using namespace std;

ifstream in;
ofstream out;

void run_case(int T) {
    int N, K;
    in >> N >> K;
    
    vector<int> S(N, 0);
    array<int, 101> cnt{0};
    for(int i = 0; i < N; i++) {
        in >> S[i];
        cnt[S[i]]++;
    }

    bool ok = true;
    for(int i = 1; i <= 100; i++) {
        if(cnt[i] > 2) {
            ok = false;
            break;
        }
    } 

    ok = ok && N <= K * 2;

    out << "Case #" << T << ": " << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    in.open("input.txt");
    out.open("output.txt");

    int T;
    in >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }

    in.close();
    out.close();
}
