#include <bits/stdc++.h>
using namespace std;

struct Customer {
    int a, b, idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Customer> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b;
        v[i].idx = i;
    }

    // Sort by arrival time
    sort(v.begin(), v.end(), [&](auto &x, auto &y){
        return x.a < y.a;
    });

    // Min-heap: (departure_time, room_number)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> room_of(n);
    int next_room = 1;

    for (auto &cust : v) {
        int arr = cust.a, dep = cust.b;

        if (!pq.empty() && pq.top().first < arr) {
            // Reuse a room
            auto [old_dep, room] = pq.top();
            pq.pop();
            room_of[cust.idx] = room;
            pq.push({dep, room});
        } 
        else {
            // Need new room
            int room = next_room++;
            room_of[cust.idx] = room;
            pq.push({dep, room});
        }
    }

    cout << next_room - 1 << "\n";
    for (int i = 0; i < n; i++)
        cout << room_of[i] << " ";
    cout << "\n";
}
