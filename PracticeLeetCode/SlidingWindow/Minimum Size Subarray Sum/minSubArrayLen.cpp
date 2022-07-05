// Topic: Minimum Size Subarray Sum
// Problem Link: https://leetcode.com/problems/minimum-size-subarray-sum/
// Approaches: Implemented O(N), can be done in O(NLogN)[need to implement this.]
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
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0, r = 0;
        int sumTillNow = 0;
        int minLen = INT_MAX;
        int minLenNow = INT_MAX;
        int n = nums.size();

        while (r < n)
        {

            if (sumTillNow < target)
            {
                sumTillNow = sumTillNow + nums[r];
                r++;
            }
            else
            {
                sumTillNow = sumTillNow - nums[l];
                l++;
            }
            if (sumTillNow >= target)
            {
                minLenNow = r - l;
            }
            if (minLenNow < minLen)
            {
                minLen = minLenNow;
            }
        }
        while (l < r)
        {
            sumTillNow = sumTillNow - nums[l];
            l++;
            if (sumTillNow >= target)
            {
                minLenNow = r - l;
            }
        }

        if (minLenNow < minLen)
        {
            minLen = minLenNow;
        }
        if (minLen == INT_MAX)
        {
            return 0;
        }
        return minLen;
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
    read(k);
    read(n);
    // write("N: ", n, "\n");
    fo(i, n)
    {
        read(a);
        input.push_back(a);
    }

    // write("K: ", k, "\n");
    int ans;
    Solution *sb = new Solution();
    sb->printVector(input);
    ans = sb->minSubArrayLen(k, input);
    write(ans);
}