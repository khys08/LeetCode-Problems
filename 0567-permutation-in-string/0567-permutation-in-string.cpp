class Solution {
public:
    bool checkInclusion(string p, string s) {
        map<char,int> mpkey;
        map<char,int> mpstr;
        
        int k = p.size();

        for(int i=0;i<k;i++){
            mpkey[p[i]]++;
        }

        for(int i=0;i<k;i++){
            mpstr[s[i]]++;
        }
        if(mpkey == mpstr){
            return true;
        }

        for(int i=k;i<s.size();i++){
            mpstr[s[i]]++;
            mpstr[s[i-k]]--;
            if(mpstr[s[i-k]]==0){
                mpstr.erase(s[i-k]);
            }
            if(mpkey == mpstr){
                return true;
            }
        }
        return false;




    }
};