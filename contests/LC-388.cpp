// https://leetcode.com/contest/weekly-contest-388/

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(begin(apple), end(apple), 0);
        sort(rbegin(capacity), rend(capacity));
        int cnt = 0;

        while(sum > 0 && cnt < capacity.size())
        	sum -= capacity[cnt++];

        return cnt;
    }
};

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(rbegin(happiness), rend(happiness));
        long long sum = 0;

        for(int i = 0; i < k; ++i)
        	sum += max(happiness[i] - i, 0);

        return sum;
    }
};

class Solution {
	const int INF = INT_MAX;
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
    	int n = arr.size();
        unordered_set<string> substrs[n];
        vector<string> res(n);

        for(int idx = 0; idx < n; ++idx) {
        	string str = arr[idx];
        	string cur;

        	for(int i = 0; i < str.size(); ++i) {
        		for(int j = i; j < str.size(); ++j) {
        			cur += str[j];
        			substrs[idx].insert(cur);
        		}
        		cur.clear();
        	}
        }

        for(int i = 0; i < n; ++i) {
        	int len = INF;

        	for(auto& substr : substrs[i]) {
        		bool found = false;

        		for(int j = 0; j < n; ++j) {
        			if(i == j) 
        				continue;

        			if(substrs[j].count(substr)) {
        				found = true;
        				break;
        			}
        		}

        		if(!found) {
        			if(substr.size() < len) {
        				res[i] = substr;
        				len = substr.size();
        			}
        			else if(substr.size() == len && substr < res[i])
        				res[i] = substr;
        		}
        	}
        }

        return res;
    }
};