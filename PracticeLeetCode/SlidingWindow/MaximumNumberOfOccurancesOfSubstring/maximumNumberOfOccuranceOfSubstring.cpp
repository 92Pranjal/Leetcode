// Topic: Sliding Window
// Problem Link: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/submissions/
// Approaches: Use Sliding Window with a trick mentioned in the sheet / Use Rolling Hash with the same sheet.
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
    // Modular power x^y
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

    // Using Rolling Hash Technique
    int maxFreqRollingHash(string s, int maxLetters, int minSize, int maxSize)
    {
        unordered_map<int, int> count;
        unordered_map<long, int> substr_count;
        int result = 0;
        int l = 0, n = s.length();
        int hash = 0, pow = powMod(53, minSize - 1);

        for (int r = 0; r < n; r++)
        {
            count[s[r]]++;
            if (r - l + 1 > minSize)
            {
                hash = hash - (s[l] - 'a') * pow;
                if (--count[s[l]] == 0)
                {
                    count.erase(s[l]);
                }
                l++;
            }
            hash = (hash * 53 + s[r] - 'a') % MOD;
            if (r - l + 1 == minSize && count.size() <= maxLetters)
            {
                result = max(result, ++substr_count[hash]);
            }
        }
        return result;
    }

    // Using Sliding Window
    int maxFreqSlidingWindow(string s, int maxLetters, int minSize, int maxSize)
    {
        unordered_map<int, int> count;
        unordered_map<string, int> substr_count;
        int result = 0;
        int l = 0, n = s.length();

        for (int r = 0; r < n; r++)
        {
            count[s[r]]++;
            if (r - l + 1 > minSize)
            {
                if (--count[s[l]] == 0)
                {
                    count.erase(s[l]);
                }
                l++;
            }
            if (r - l + 1 == minSize && count.size() <= maxLetters)
            {
                result = max(result, ++substr_count[s.substr(l, r - l + 1)]);
            }
        }
        return result;
    }
};

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    int maxLetters, minSize, maxSize;
    read(s, maxLetters, minSize, maxSize);
    int ans;
    Solution *sb = new Solution();
    int ansSW = sb->maxFreqSlidingWindow(s, maxLetters, minSize, maxSize);
    int ansRH = sb->maxFreqRollingHash(s, maxLetters, minSize, maxSize);
    write(ansSW, "\n");
    write(ansRH);
}