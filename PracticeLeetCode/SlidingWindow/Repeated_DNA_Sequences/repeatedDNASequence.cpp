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
    vector<string> repeatedDNASequence(string s)
    {
        int l = 0, r, n = s.length();
        map<string, int> substringCount;
        long hash = 0;
        for (r = 0; r < n; r++)
        {
            if (r - l + 1 == 10)
            {
                // hash = hash - (s[r] - 'a') * pow;
                string p = s.substr(l, r - l + 1);
                if (substringCount.find(p) == substringCount.end())
                {
                    substringCount[p] = 1;
                }
                else
                {
                    substringCount[p]++;
                }

                l++;
            }

            // hash = (hash * 53 + s[r] - 'a') % MOD;
        }

        map<string, int>::iterator it;
        vector<string> ans;
        for (it = substringCount.begin(); it != substringCount.end(); it++)
        {
            write("it First: ", it->first, "it Second: ", it->second, "\n");
            if (it->second > 1)
            {

                ans.push_back(it->first);
            }
        }
        return ans;
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
    write(s);
    Solution *sb = new Solution();
    // sb->printVector(input);
    vector<string> ans;
    ans = sb->repeatedDNASequence(s);
    // write(ans);
    sb->printVectorString(ans);
}