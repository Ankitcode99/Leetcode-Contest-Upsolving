// Shortest String That Contains Three Strings

class Solution {
private:
    vector<vector<string>> computePermutations(string a, string b, string c){
        return {{a,b,c}, {a,c,b}, {b,a,c}, {b,c,a}, {c,a,b}, {c,b,a}};
    }
    
    bool checkSubstring(string a, string b){
        if(a.size()<b.size())
            return false;
        else if(a.size()==b.size())
            return a==b;
        
        for(int i=0;i<=(a.size()-b.size());i++){
            if(a.substr(i,b.size())==b){
                return true;
            }
        }
        return false;
    }
public:
    string minimumString(string a, string b, string c) {
        vector<vector<string>> permutations = computePermutations(a,b,c);
        string ans="";
        for(int i=0;i<305;i++){
            ans +='z';
        }
        for(auto x: permutations){
            string currString="";
            for(string currWord: x){
                if(currString==""){
                    currString = currWord;
                }else{
                    if(!checkSubstring(currString, currWord)){
                       int len=min(currString.size(), currWord.size());
                        while(len>0){
                            if(currString.substr(currString.size()-len, len)==currWord.substr(0,len))
                                break;
                            else
                                len--;

                            // cout<<len<<"\n";
                        }
                        while(len<currWord.size()){
                            currString+=currWord[len++];
                        } 
                    }
                }
            }
            // cout<< currString<<"\n";
            if(ans.size()>currString.size()){
                ans = currString;
            }else if(ans.size()==currString.size()){
                ans = min(ans, currString);                            
            }
        }
        return ans;
    }
};