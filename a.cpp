#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findKthClosestDistance(const vector<int>& A, int b, int k) {
    vector<int> distances;
    for (int a : A) {
        distances.push_back(abs(a - b));
    }
    nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
    return distances[k - 1];
}

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());

    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    for (const auto& query : queries) {
        int b = query.first;
        int k = query.second;
        
        int distance = findKthClosestDistance(A, b, k);
        cout << distance << endl;
    }
    
    return 0;
}
