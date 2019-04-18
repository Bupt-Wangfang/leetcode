class Solution {
public:
    string longestPalindrome(string s) {
        string res=preProcess(s);
        int length=res.length();
        int *Len=new int[length];
        int cur=0,right=0;
        int centerIndex=0,maxLen=0;
        for(int i=1;i<length-1;i++){
            Len[i]=(right>i)?min(right-i,Len[2*cur-i]):0;
            while(res[i+Len[i]+1]==res[i-Len[i]-1]){
                Len[i]++;
            }
            if(i+Len[i]>right){
                cur=i;
                right=i+Len[i];
            }
            if(Len[i]>maxLen){
                maxLen=Len[i];
                centerIndex=i;
            }
        }
        return s.substr((centerIndex-maxLen-1)/2,maxLen);
    }
    string preProcess(string s){
        int n=s.length();
        if(n==0){return "^$";}
        string res="^";
        for(int i=0;i<n;i++){
            res+="#"+s.substr(i,1);
        }
        res+="#$";
        return res;
    }
};