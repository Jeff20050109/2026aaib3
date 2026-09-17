//week02-4.cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int U[26] = {};
        for (char c : s){
            U[c -'a'] ++;
        }
        for(char c : t){
            U[c-'a'] --;
            if(U[c-'a']<0)return c;
        }
        return 0;
    }
};
