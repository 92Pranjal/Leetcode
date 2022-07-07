// Topic: Two Sliding Windows in a single problem [Tricky] Must Practice
// Problem Link: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
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
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
    {
        // write("FirstLength SecondLength: ", findMaxNonOverlappingSubArray(nums, firstLen, secondLen), "\n", "SecondLength FirstLength: ", findMaxNonOverlappingSubArray(nums, secondLen, firstLen), "\n");
        int result = max(findMaxNonOverlappingSubArray(nums, firstLen, secondLen), findMaxNonOverlappingSubArray(nums, secondLen, firstLen));
        return result;
    }

    int findMaxNonOverlappingSubArray(vector<int> &nums, int firstLen, int secondLen)
    {
        // write("First Time\n");
        int lSum = 0, rSum = 0, maxSum = 0, n = nums.size();

        for (int i = 0; i < firstLen; i++)
        {
            lSum += nums[i];
        }
        for (int i = firstLen; i < firstLen + secondLen; i++)
        {
            rSum += nums[i];
        }

        maxSum = lSum + rSum;
        int start = 0, firstShift = firstLen, secondShift = firstLen + secondLen;
        int leftTillMax = lSum;
        while (secondShift < n)
        {
            lSum = lSum - nums[start] + nums[firstShift];

            rSum = rSum - nums[firstShift] + nums[secondShift];

            // write("Left: ", lSum);
            leftTillMax = max(leftTillMax, lSum);
            // write("Left Max: ", leftTillMax, "\n");

            maxSum = max(maxSum, leftTillMax + rSum);
            start++;
            firstShift++;
            secondShift++;
        }
        // write("Max Sum: ", maxSum);
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
    int i, fl, a, sl;

    read(n);
    // write("N: ", n, "\n");
    fo(i, n)
    {
        read(a);
        input.push_back(a);
    }
    read(fl);
    read(sl);
    // write("K: ", k, "\n");
    // write(fl, " ", sl);
    int ans;
    Solution *sb = new Solution();
    // sb->printVector(input);
    ans = sb->maxSumTwoNoOverlap(input, fl, sl);
    write(ans);
}