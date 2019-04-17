class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int n=target-nums[i];
            if(m.find(n)!=m.end()){
                res.push_back(m[n]);
                res.push_back(i);
                return res;
            }
            m[nums[i]]=i;
        }
        return res;
    }
};