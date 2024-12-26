class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> mpkey;
        map<char,int> mpstr;
        vector<int> res;
        int k = p.size();

        for(int i=0;i<k;i++){
            mpkey[p[i]]++;
        }

        for(int i=0;i<k;i++){
            mpstr[s[i]]++;
        }
        if(mpkey == mpstr){
            res.push_back(0);
        }

        for(int i=k;i<s.size();i++){
            mpstr[s[i]]++;
            mpstr[s[i-k]]--;
            if(mpstr[s[i-k]]==0){
                mpstr.erase(s[i-k]);
            }
            if(mpkey == mpstr){
                res.push_back(i-k+1);
            }
        }
        return res;



    }
};