class Solution {
public:
    int specialArray(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        int j=0;
        for(int i=0;i<=n;i++){
            while(j<n && a[j]<i){
                j++;
            }
            if(n-j==i){
                return i;
            }
        }
        return -1;
    }
};