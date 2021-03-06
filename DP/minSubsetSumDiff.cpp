//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#

class Solution
{
public:
    vector<int> v;
    void SubsetSum(int arr[], int n, int range)
    {
        bool dp[n + 1][range + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= range; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= range; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        // Collecting value of last line in DP table into a vector
        for (int j = 0; j <= range / 2; j++)
        {
            if (dp[n][j] == true)
                v.push_back(j);
        }
    }
    int minDifference(int arr[], int n)
    {

        int range = 0;
        for (int i = 0; i < n; i++)
        {
            range += arr[i];
        }
        SubsetSum(arr, n, range);
        int mn = INT_MAX;
        for (int i = 0; i < v.size(); i++)
        {
            if (range - 2 * v[i] < mn)
                mn = range - 2 * v[i];
        }
        return mn;
    }
};