// Topic: Sliding Window
// Problem Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/submissions/
// Approaches: O(N)
// Difficulty: MEDIUM 
// Very Similar to Max Consequetive III

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
    int LongestOncesOneDeletion(vector<int> &nums)
    {
        int zero = 0, l = 0, r = 0, k = 1, n = nums.size(), lzidx = INT_MIN, pzidx = INT_MIN, decreaseLength = 0;
        int length = 0, maxLength = INT_MIN;
        vector<int> cumSum;
        cumSum.push_back(0);
        cumSum.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            cumSum.push_back(cumSum[i] + nums[i]);
        }
        printVector(cumSum);
        if (cumSum[n] == n)
        {
            return n - 1;
        }
        while (r < n)
        {
            if (nums[r] == 0)
            {
                pzidx = lzidx;
                lzidx = r;
                zero++;
            }
            if (zero > k)
            {
                if (length > maxLength)
                {
                    maxLength = length;
                }
                length = length - (cumSum[pzidx] - cumSum[l]);
                l = pzidx + 1;
                zero = k;
            }
            if (nums[r] == 1)
            {
                length++;
            }
            r++;
        }
        if (length > maxLength)
        {
            maxLength = length;
        }
        return maxLength;
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
    int i, fl, a, sl;

    read(n);
    // write("N: ", n, "\n");
    fo(i, n)
    {
        read(a);
        input.push_back(a);
    }
    // write("K: ", k, "\n");
    // write(fl, " ", sl);
    int ans;
    Solution *sb = new Solution();
    // sb->printVector(input);
    ans = sb->LongestOncesOneDeletion(input);
    write(ans);
}