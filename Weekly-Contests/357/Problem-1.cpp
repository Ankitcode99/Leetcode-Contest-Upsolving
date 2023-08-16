// Faulty keyboard


class Solution {
public:
    string finalString(string s) {
        string ans="";
        for(char x:s){
            if(x=='i'){
                reverse(ans.begin(), ans.end());
            }else{
                ans +=x;
            }
        }
        return ans;
    }
};