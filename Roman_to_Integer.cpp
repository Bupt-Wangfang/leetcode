#include <iostream>
#include<cmath>
#include<vector>
#include<map>
#include <string>
using namespace std;

class Solution{
	public:
		int romanToInt(string s) {
			int i=0,len=s.size();
			int res=0;
			map<char,int> Map;  
			Map.insert(pair<char,int>('I',1));  
			Map.insert(pair<char,int>('V',5));   
			Map.insert(pair<char,int>('X',10));   
			Map.insert(pair<char,int>('L',50));   
			Map.insert(pair<char,int>('C',100));   
			Map.insert(pair<char,int>('D',500));   
			Map.insert(pair<char,int>('M',1000));   
			while(i<len){
				if(s[i]=='I'&& (s[i+1]=='V'||s[i+1]=='X') || s[i]=='X'&& (s[i+1]=='L'||s[i+1]=='C') || s[i]=='C'&& (s[i+1]=='D'||s[i+1]=='M')){
					auto it1 = Map.find(s[i+1]);
					auto it2 = Map.find(s[i]);
					res+=((*it1).second-(*it2).second);
					i+=2;
				}else{
					auto it = Map.find(s[i]);
					res+=(*it).second;
					i+=1;
				}
			}
			return res;
		}
};

int main()
{
	Solution s1;
	string s="MCMXCIV";
    int result=s1.romanToInt(s);
	return 0;
}