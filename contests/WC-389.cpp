// https://leetcode.com/contest/weekly-contest-389/

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();

        for(int i = 0; i + 1 < n; ++i) {
        	string substr = s.substr(i, 2);
            reverse(begin(substr), end(substr));

        	if(s.find(substr) != string::npos)
        		return true;
        }

        return false;
    }
};

class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt = 0;
        int occ = 0;

        for(char ch : s) {
        	if(ch == c) {
        		++occ;
        		cnt += occ;
        	}
        }

        return cnt;
    }
};

class Solution {
    const int INF = INT_MAX;
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        int best = INF;
        int del = 0;

        for(char ch : word)
        	++freq[ch - 'a'];

        sort(rbegin(freq), rend(freq));

        for(int i = 25; i >= 0; --i) {
        	int cur = del;

        	for(int j = 0; j < i; ++j)
        		cur += max((freq[j] - freq[i]) - k, 0);

        	best = min(best, cur);
        	del += freq[i];
        }
        

        return best;
    }
};