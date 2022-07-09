// Topic: Minimum Size Subarray Sum
// Problem Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/submissions/
// Approaches: Simple Idea focus on when you initialize the map while traversing the string.
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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
       int n = s.length(), length = 0, maxLength = INT_MIN, l = 0, r;
        unordered_map<char, int> mp;
        if (k == 0)
            return 0;
        for (r = 0; r < n; r++)
        {
            // write("Map Size: ", mp.size());
            mp.find(s[r]) == mp.end() ? mp[s[r]] = 1 : mp[s[r]]++;
            while (mp.size() > k)
            {
                length = r - l;
                // write("\nLength: ", length);
                // write("\nMap Size: ", mp.size(), "\nCharacter: ", s[l], "\n L: ", l, "\n", "Map Value: ", mp[s[l]]);

                if (mp[s[l]] > 1)
                {
                    mp[s[l]] = mp[s[l]] - 1;
                }
                else
                {
                    mp.erase(s[l]);
                }
                if (length > maxLength)
                {
                    maxLength = length;
                }
                l++;
            }
        }
        // write("L: ", l, "\n");
        // write("R: ", r, "\n");
        // write("Map Size: ", mp.size());
        // write("Max Length: ", maxLength);
        // write("Length: ", length);
        if (length > maxLength)
            maxLength = length;

        if (mp.size() <= k && maxLength < r - l)
        {
            // write("\nEntering here!!");
            maxLength = r - l;
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
    ans = sb->lengthOfLongestSubstringKDistinct(s, k);
    write(ans);
    // sb->printVectorString(ans);
}