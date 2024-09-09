#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Precompute factorials up to 15!
vector<long long> factorial(16, 1);

void precompute_factorials() {
    for (int i = 1; i <= 15; ++i) {
        factorial[i] = factorial[i - 1] * i;
    }
}

// Function to find the rank of a given permutation
long long find_rank(const vector<int>& perm, int N) {
    long long rank = 0;
    vector<bool> used(N + 1, false);  // Track which numbers are used
    
    for (int i = 0; i < N; ++i) {
        int count = 0;
        for (int j = 1; j < perm[i]; ++j) {
            if (!used[j]) {
                ++count;
            }
        }
        rank += count * factorial[N - 1 - i];  // Calculate rank based on unused elements
        used[perm[i]] = true;  // Mark current number as used
    }
    return rank + 1;  // Ranks are 1-based
}

// Function to find the X-th permutation (1-based)
vector<int> find_permutation(long long X, int N) {
    vector<int> perm;
    vector<int> available(N);  // Available numbers (1, 2, ..., N)
    for (int i = 0; i < N; ++i) available[i] = i + 1;

    --X;  // Convert X to 0-based index

    for (int i = 0; i < N; ++i) {
        long long idx = X / factorial[N - 1 - i];  // Which number to pick
        perm.push_back(available[idx]);  // Add it to the permutation
        available.erase(available.begin() + idx);  // Remove it from the list
        X %= factorial[N - 1 - i];  // Update X for the remaining elements
    }

    return perm;
}

int main() {
    precompute_factorials();
    
    int T;  // Number of test cases
    cin >> T;
    
    while (T--) {
        int N, query_type;
        cin >> N >> query_type;
        
        if (query_type == 1) {
            // Type 1: Find rank of the given permutation
            vector<int> perm(N);
            for (int i = 0; i < N; ++i) {
                cin >> perm[i];
            }
            cout << find_rank(perm, N) << endl;
            
        } else if (query_type == 2) {
            // Type 2: Find the X-th permutation
            long long X;
            cin >> X;
            vector<int> perm = find_permutation(X, N);
            for (int i = 0; i < N; ++i) {
                cout << perm[i] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
