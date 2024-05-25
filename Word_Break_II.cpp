class Solution {
public:
    void solve(int i,set<string>&se,string &s,string temp,string made,vector<string>&res){
        if(i==s.size()){
            if(se.find(temp)!=se.end()){
                if(made.size()!=0){
                made+=" "+temp;}
                else{
                    made+=temp;
                }
                res.push_back(made);
            }
            return;
        }
        string t2=temp;
        temp+=s[i];
        solve(i+1,se,s,temp,made,res);
        if(se.find(t2)!=se.end()){
            if(made.size()!=0){
                made+=" "+t2;}
            else{
                made+=t2;
            }
            temp="";
            temp+=s[i];
            solve(i+1,se,s,temp,made,res);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wd) {
        set<string>se;
        for(string word:wd){
            se.insert(word);
        }
        vector<string>res;
        string made="";
        string temp="";
        solve(0,se,s,temp,made,res);
        return res;
    }
};