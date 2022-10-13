#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    node* next;

    node(int v) : val(v) {
        next = nullptr;
    }
    node(int v, node* next) : val(v), next(next) {

    }
};

void run_case() {
    int N;
    cin >> N;

    node* head = new node(1); 
    node* cur = head;
    for(int i = 2; i <= N; i++) {
        node* x = new node(i);
        cur->next = x;
        cur = x;
    }        

    cur->next = head;

    node* pre = head;
    cur = head->next;
    for(int i = 0; i < N; i++) {
        cout << cur->val << " \n"[i == N - 1];

        if(pre != cur) {
            pre->next = cur->next;
            cur->next = nullptr;

            pre = pre->next;
            cur = pre->next;
        } 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
