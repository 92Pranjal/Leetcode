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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> finalAns;
        deque<int> dq;

        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() && i - k == dq.front())
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                finalAns.push_back(nums[dq.front()]);
            }
        }
        return finalAns;
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
    fo(i, n)
    {
        read(a);
        input.push_back(a);
    }
    read(k);
    vector<int> ans;
    Solution *sb = new Solution();
    ans = sb->maxSlidingWindow(input, k);
    sb->printVector(ans);
}