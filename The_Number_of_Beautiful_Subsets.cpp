class Solution {
private:
    int solve(map<int,int>&mp,bool cond,vector<int>&v,int i){
        if(i==v.size()){
            return 1;
        }
        int ans=0;
        ans+=solve(mp,true,v,i+1);
        if(cond){
            ans+=(pow(2,mp[a[i]])-1)*solve(mp,false,v,i+1);
        }
        return ans;
    }
    
public:
    int beautifulSubsets(vector<int>& a, int k) {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<map<int,int>>ve(n);
        vector<vector<int>>vec;
        vector<int>dp(n,0);
        map<int,int>con;
        int m=0;
        for(int i=0;i<n;i++){
            if(mp.find(a[i]-k)!=mp.end() && mp.find(a[i])==mp.end()){
                mp[a[i]]=mp[a[i]-k];
                ve[mp[a[i]]][a[i]]++;
                vec[mp[a[i]]].push_back(a[i]);
            }else{
                if(mp.find(a[i])==mp.end()){
                    mp[a[i]]=m;
                    ve[mp[a[i]]][a[i]]++;
                    vec[mp[a[i]]].push_back(a[i]);
                    m++;
                }else{
                    ve[mp[a[i]]][a[i]]++;
                }
            }
        }
        int ans=1;
        for(int i=0;i<vec.size();i++){
            ans*=solve(ve[i],true,vec[i],0);
        }
        return ans;
    }
};