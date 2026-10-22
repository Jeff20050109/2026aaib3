class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> a;
        for(string s:operations){
            if(s=="+"){
                int now = a[a.size()-1] + a[a.size()-2];
                a.push_back(now);
            }else if(s=="D"){
                int now = a[a.size()-1]*2;
                a.push_back(now);
            }else if(s=="C"){
                a.pop_back();
            }else{
                int now = stoi(s);
                a.push_back(now);
            }
        }
        int ans = 0;
        for(int now : a)ans += now;
        return ans;
    }
};