#include <iostream>
#include <vector>
using namespace std;

string split_array(vector<int> arr) {
    int total_weight = 0;
    for (int i = 0; i < arr.size(); i++) {
        total_weight += arr[i];
    }
    if (total_weight % 2 != 0) {
        return "NO";
    }
    int half_weight = total_weight / 2;
    vector<bool> dp(half_weight + 1, false);
    dp[0] = true;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = half_weight; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    return dp[half_weight] ? "YES" : "NO";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << split_array(arr) << endl;
    return 0;
}
