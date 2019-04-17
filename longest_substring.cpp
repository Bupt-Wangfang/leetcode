class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256]={0};
        int start=0,end=-1;
        int res=0;
        while(start<s.size()){
            if(end+1<s.size() && freq[s[end+1]]==0){
                end++;
                freq[s[end]]++;
            }else{
                freq[s[start]]--;
                start++;
            }
            if(res<(end-start+1)){
                res=end-start+1;
            }
        }
        return res;
    }
};