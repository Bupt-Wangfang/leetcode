class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1){
            return s;
        }
        string res="";
        int gap=2*numRows-2;
        for(int i=0;i<numRows;i++){
            for(int j=i;j<s.size();j+=gap){
                res+=s[j];
                int oGap=j+gap-2*i;
                if(i!=0 && i!=numRows-1 && oGap<s.size()){
                    res+=s[oGap];
                }
            }
        }
        return res;
    }
};