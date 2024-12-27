#include <iostream>
#include <vector>
#include <algorithm>  // For std::max
using namespace std;

/*
       
    █▀▄▀█ █▀▀█ █▀▀ █▀▀ █▀▀ 　 █▀▀█ █▀▀▄ █▀▀ █░░░█ █▀▀█ █░░ █░░█ 　 ░░ 　 █▀▀▄ █▀▀█ 
    █░▀░█ █░░█ ▀▀█ █▀▀ ▀▀█ 　 █▄▄█ █░░█ █▀▀ █▄█▄█ █░░█ █░░ █░░█ 　 ▀▀ 　 █░░█ █░░█ 
    ▀░░░▀ ▀▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ 　 ▀░░▀ ▀▀▀░ ▀▀▀ ░▀░▀░ ▀▀▀▀ ▀▀▀ ░▀▀▀ 　 ░░ 　 ▀▀▀░ █▀▀▀
*/

int maxTreasure(const vector<int>& T) {
    int n = T.size();
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return T[0];
    // Create the DP array to store the maximum treasure up to each ruin
    vector<int> DP(n);
    // Initialize the base cases
    DP[0] = T[0];
    DP[1] = max(T[0], T[1]);
    // Fill the DP array using the recursive relation
    for (int i = 2; i < n; i++) {
        DP[i] = max(DP[i-1], T[i] + DP[i-2]);
    }
    // The last element in DP contains the maximum treasure that can be collected
    return DP[n-1];
}

int main() {
    vector<int> T = {6, 7, 1, 30, 8, 2, 4};
    cout << maxTreasure(T) << endl;  // Output: 41
    return 0;
}
