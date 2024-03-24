// https://leetcode.com/contest/biweekly-contest-126/

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
         
        for(int num : nums) {
            string str = to_string(num);
            int mx = *max_element(begin(str), end(str));
            for(char& ch : str) ch = mx;
            sum += stoi(str);
        }
        
        return sum;
    }
};

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        multiset<array<int, 2>> st;
        vector<long long> res(m);
        long long total = accumulate(begin(nums), end(nums), 0LL);
        long long vis = 0;
        
        for(int i = 0; i < nums.size(); ++i)
            st.insert({ nums[i], i });
        
        for(int i = 0; i < m; ++i) {
            int idx = queries[i][0];
            int num = nums[idx];
            int k = queries[i][1];
                                    
            if(st.count({ num, idx })) {
                st.erase({ num, idx });
                vis += num;
            }
            
            while(!st.empty() && k > 0) {
                auto it = st.begin();
                vis += (*it)[0];
                st.erase(it);
                --k;
            }
                        
            res[i] = total - vis;
        }
        
        return res;
    }
};