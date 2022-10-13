#include <iostream>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    map<int, int> tickets;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;
        tickets[X]++;
    }

    vector<int> Q(M, 0);
    for(int i = 0; i < M; i++) {
        cin >> Q[i];
    }

    for(int i = 0; i < M; i++) {
        auto it = tickets.upper_bound(Q[i]);
        if(it == tickets.begin()) {
            cout << -1 << '\n'; 
        } else {
            it--;
            int p = it->first;
            int c = it->second;
            if(c == 1) {
                tickets.erase(p);
            } else {
                it->second--;
            }

            cout << p << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
