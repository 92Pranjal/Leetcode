class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int s=A.size();
        int charmap[26];
        for(int i=0;i<26;i++){
            charmap[i] = -9999;
        }
        
        //for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].length();j++){
                //cout << A[i][j] <<" "<<charmap[A[i][j]-'a']<<"\n";
                charmap[A[0][j]-'a']=j+1;
            }
       // }
        
        
        
        for(int i=1;i<A.size();i++){
            for(int j=0;j<A[i].length();j++){
                //cout << A[i][j] <<" "<<charmap[A[i][j]-'a']<<"\n";
                if(charmap[A[i][j]-'a'] != -9999){
                    charmap[A[i][j]-'a']=i+1;
                }
                
            }
        }
        vector<int> comparision;
        for(int i=0;i<26;i++){
            if(charmap[i] == s){
                comparision.push_back(i);
            }
        }
        vector<string> ans;
        for(int i=0;i<comparision.size();i++){
            char m=comparision[i]+'a';
            string sy(1,m);
         //   cout << m << " " <<comparision[i] <<"\n";
            int minval=INT_MAX,count=0;
            
             
                          
                for(int k=0;k<A[0].length();k++){
                    if(A[0][k] == m ){
                        count++;//cout << minval <<" "<< m <<"\n";
                       // minval=min(minval,count);
                    }
                }
            
            minval=min(minval,count);
            for(int j=1;j<s;j++){
                count=0;
               for(int k=0;k<A[j].length();k++){
                    if(A[j][k] == m ){
                        count++;
                       // cout << count <<" "<<minval <<" "<< m <<"\n";
                       
                    }
                }
                 minval=min(minval,count);
            }
            
            for(int i=0;i<minval;i++){
                ans.push_back(sy);
            }
            
            
        }
       // vector<string> sp;
        return ans;
    }
};

//////////////////// BETTER Soluton ////////////////////////
///link : https://leetcode.com/problems/find-common-characters/discuss/247573/C%2B%2B-O(n)-or-O(1)-two-vectors
vector<string> commonChars(vector<string>& A) {
  vector<int> cnt(26, INT_MAX);
  vector<string> res;
  for (auto s : A) {
    vector<int> cnt1(26, 0);
    for (auto c : s) ++cnt1[c - 'a'];
    for (auto i = 0; i < 26; ++i) cnt[i] = min(cnt[i], cnt1[i]);
  }
  for (auto i = 0; i < 26; ++i)
    for (auto j = 0; j < cnt[i]; ++j) res.push_back(string(1, i + 'a'));
  return res;
}