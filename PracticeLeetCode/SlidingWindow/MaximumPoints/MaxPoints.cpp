// Topic: Standard Sliding Window with Prefix Sum
// Problem Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Approaches: O(N)
// Difficulty: MEDIUM

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; i < n; i++)

template <typename... T>
void read(T &...args)
{
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&...args)
{ // rvalue reference is new to C++
    ((cout << args << " "), ...);
}
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int l = 0, r = 0, n = cardPoints.size();
        int totalCardPoints = 0;
        for (int i = 0; i < cardPoints.size(); i++)
        {
            totalCardPoints += cardPoints[i];
        }
        vector<int> prefixSum;
        prefixSum.push_back(0);
        prefixSum.push_back(cardPoints[0]);
        for (int i = 1; i < n; i++)
        {
            prefixSum.push_back(prefixSum[i] + cardPoints[i]);
        }
        if (n == k)
        {
            return prefixSum[n];
        }
        int maxSum = INT_MIN;
        int sumTillNow = 0;
        while (r < n)
        {
            if (r - l + 1 < n - k)
            {
                r++;
            }
            else
            {
                sumTillNow = totalCardPoints - (prefixSum[r + 1] - prefixSum[l]);
                l++;
                r++;
            }
            if (maxSum < sumTillNow)
            {
                maxSum = sumTillNow;
            }
        }
        // sumTillNow = totalCardPoints - (prefixSum[r] - prefixSum[l]);
        if (maxSum < sumTillNow)
        {
            maxSum = sumTillNow;
        }
        return maxSum;
    }

    void printVector(vector<int> vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            write(vec[i], " ");
        }
        write("\n");
    }
};

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    vector<int> input;
    int i, k, a;

    read(n);
    // write("N: ", n, "\n");
    fo(i, n)
    {
        read(a);
        input.push_back(a);
    }
    read(k);
    // write("K: ", k, "\n");
    int ans;
    Solution *sb = new Solution();
    // sb->printVector(input);
    ans = sb->maxScore(input, k);
    write(ans);
}