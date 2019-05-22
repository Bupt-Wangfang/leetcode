#include <iostream>
#include<cmath>
using namespace std;

class Solution{
	public:
		bool isMatch(string s, string p) {
			return isMatchCore(s.c_str(),p.c_str());
		}
		bool isMatchCore(const char* s, const char* p){
			if(*p == 0) return *s == 0;
			if(*(p+1)=='*'){
				if(*p==*s || (*p=='.'&&*s!='\0')){
					return isMatchCore(s,p+2) || isMatchCore(s+1,p) || isMatchCore(s+1,p+2);
				}else{
					return isMatchCore(s,p+2);
				}
			}
			else if(*p==*s || (*p=='.'&&*s!='\0')){
				return isMatchCore(s+1,p+1);
			}
			return false;
		}
};

int main()
{
	Solution s1;
	string s = "aa";
	string p = "a*";
    bool result=s1.isMatch(s,p);
	return 0;
}