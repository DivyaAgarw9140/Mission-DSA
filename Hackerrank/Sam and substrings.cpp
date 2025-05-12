#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'substrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING n as parameter.
 */

int substrings(string n) {
    const int MOD = 1e9 + 7;
    long long result = 0;
    // Convert character to integer value with "- '0'"
    // dp[i] represents sum of all substrings ending at index i
    long long dp = n[0] - '0'; 
    result += dp; // Add substrings sum ending at index 0
    
    for (int i = 1; i < n.length(); i++) {
        // Sums all substrings ending at index i, 
        // sums all substrings ending at index i-1,
        // sums all substrings ending with current digit (n[i]).
        dp = (dp * 10 + (i + 1) * (n[i] - '0')) % MOD;
        result = (result + dp) % MOD;
    }
    return (int)result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
