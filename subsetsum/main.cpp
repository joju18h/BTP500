#include <iostream>
#include <vector>

bool isSubsetSum(const std::vector<int>& set, int sum) {
    int n = set.size();
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(sum + 1, false));

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    // Fill the dp table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
        }
    }

    return dp[n][sum];
}

int main() {
    // Test Cases
    std::vector<std::vector<int>> testCases = {
        {3, 34, 4, 12, 5, 2},   // Test case 1
        {1, 2, 3, 4, 5},        // Test case 2
        {2, 4, 6, 8, 10},       // Test case 3
        {10, 20, 30, 40, 50},   // Test case 4
    };

    std::vector<int> targets = { 9, 11, 14, 100 }; // Corresponding target sums for test cases

    for (int i = 0; i < testCases.size(); ++i) {
        std::cout << "Test Case " << i + 1 <<std::endl;
        for (int j = 0; j < targets.size(); ++j) {
            if (isSubsetSum(testCases[i], targets[j]))
                std::cout << "Target Sum " << targets[j] << ": Found a subset with the given sum" << std::endl;
            else
                std::cout << "Target Sum " << targets[j] << ": No subset with the given sum" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
