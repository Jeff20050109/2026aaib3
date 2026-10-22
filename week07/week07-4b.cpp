class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int a[3][3] = {0};
        string result[3] = {"Draw","A","B"};
        int who =1;
        for(vector<int> move : moves){
            int i = move[0],j = move[1];
            a[i][j] = who;
            if(a[i][0]==who && a[i][1]==who && a[i][2]==who) return result[who];

            if(a[0][j]==who && a[1][j]==who && a[2][j]==who) return result[who];

            if(a[0][0]==who && a[1][1]==who && a[2][2]==who) return result[who];
            if(a[2][0]==who && a[1][1]==who && a[0][2]==who) return result[who];

            if(who==1) who=2;
            else who=1;
        }
        if(moves.size()==9)return "Draw";
        else return "Pending";
    }
};