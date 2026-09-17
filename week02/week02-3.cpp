///week02-3.cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int N1 = word1.length(),N2 = word2.length();
        for (int i=0; i<max(N1,N2); i++){
            if (i<N1) ans += word1[i];
            if (i<N2) ans += word2[i];
        }
        return ans;
    }
};
