// Topic: Sliding Window/ Monotonique Queue
// Problem Link: https://leetcode.com/problems/sliding-window-maximum/submissions/
// Approaches: Use Heap/Multiset O(NlonN) / Use  Monotonic Queue O(N)
// Difficulty: HARD

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
    int maxErasureValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixSum;
        prefixSum.push_back(0);
        prefixSum.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            prefixSum.push_back(prefixSum[i] + nums[i]);
        }
        int l = 0, r = 0, start;
        map<int, int> mp;
        int maxSum = INT_MIN;
        int sumTillNow = INT_MIN;
        while (r < n)
        {
            if (mp.find(nums[r]) == mp.end())
            {
                mp[nums[r]] = r;
            }
            else
            {
                if (mp[nums[r]] < r && l <= mp[nums[r]])
                {
                    sumTillNow = prefixSum[r] - prefixSum[l];
                    l = mp[nums[r]] + 1;
                }
                mp[nums[r]] = r;
            }
            r++;
            if (sumTillNow > maxSum)
            {
                maxSum = sumTillNow;
            }
        }
        if (prefixSum[r] - prefixSum[l] > maxSum)
        {
            maxSum = prefixSum[r] - prefixSum[l];
        }
        return maxSum;
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
    fo(i, n)
    {
        read(a);
        input.push_back(a);
    }
    int ans;
    Solution *sb = new Solution();
    ans = sb->maxErasureValue(input);
    write(ans);
}