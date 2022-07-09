// Topic: Minimum Size Subarray Sum
// Problem Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/submissions/
// Approaches: Simple Idea focus on when you initialize the map while traversing the string
// Difficulty: MEDIUM

#include <bits/stdc++.h>
#include <unordered_map>
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
    long MOD = 1e9 + 7;
    long powMod(long x, int y)
    {
        long res = 1;
        while (y > 0)
        {
            if (y & 1) // if y odd
                res = (res * x) % MOD;
            y = y >> 1;
            x = (x * x) % MOD;
        }
        return res;
    }
    int longestSubstring(string s, int k)
    {
        int n = s.length(), length = 0, maxLength = INT_MIN, l = 0, r;
        if (n == 0 || n < k)
            return 0;
        if (k <= 1)
            return s.length();
        unordered_map<char, int> mp;
        for (char c : s)
        {
            mp[c] += 1;
        }

        while (l < n && mp[s[l]] >= k)
            l++;
        if (l >= n - 1)
            return l;
        int ls1 = longestSubstring(s.substr(0, l), k);
        while (l < n && mp[s[l]] < k)
            l++;
        int ls2 = l < n ? longestSubstring(s.substr(l), k) : 0;
        return max(ls1, ls2);
    }

    void printVector(vector<int> vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            write(vec[i], " ");
        }
        write("\n");
    }

    void printVectorString(vector<string> vec)
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
    string s;
    read(s);
    // write(s);
    read(k);
    // write(" K: ", k);
    Solution *sb = new Solution();
    // sb->printVector(input);
    int ans;
    ans = sb->longestSubstring(s, k);
    write(ans);
    // sb->printVectorString(ans);
}