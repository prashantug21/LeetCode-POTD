class Solution {
public:
    int solve(unordered_map<char,int>&ch,vector<unordered_map<char,int>>&mp,vector<int>&sce,int i){
        if(i==mp.size()){
            return 0;
        }
        bool cf=1;
        for(auto &it:mp[i]){
            if(ch.find(it.first)==ch.end() || ch[it.first]<it.second){
                cf=0;
                break;
            }
        }
        int notTaken=solve(ch,mp,sce,i+1);
        int taken=0;
        if(cf){
            for(auto &it:mp[i]){
                ch[it.first]-=it.second;
            }
            taken=sce[i]+solve(ch,mp,sce,i+1);
            for(auto &it:mp[i]){
                ch[it.first]+=it.second;
            }
        }
        return max(notTaken,taken);
    }
    int maxScoreWords(vector<string>& wd, vector<char>& lt, vector<int>& sc){
        unordered_map<char,int>ch;
        for(auto &c:lt){
            ch[c]++;
        }
        vector<unordered_map<char,int>>mp;
        unordered_map<char,int>temp;
        vector<int>sce;
        for(int i=0;i<wd.size();i++){

            temp.clear();
            int score=0;
            for(char &c:wd[i]){
                temp[c]++;
                score+=sc[c-'a'];
            }
            mp.push_back(temp);
            sce.push_back(score);
        }
        return solve(ch,mp,sce,0);
    }
};