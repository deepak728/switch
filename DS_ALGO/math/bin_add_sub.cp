#include <bits/stdc++.h>
using namespace std;

void take_1_compl(string &s,int l){
    for(int i=s.length();i<l;i++)
        s+='0';
    
    for(int i=0;i<s.length();i++)
    s[i]= (((s[i]-'0'+1)%2)+'0');
    return; 
}

string add_bin(string s1,string s2, bool flag){
    string ans="";
    int carry=0,sum;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int l= max(s1.length(),s2.length());
    if(flag)
      take_1_compl(s2,l);
   
    
    int i=0 ,a1,a2;
    while(i<l){
        a1= i<s1.length() ? s1[i]-'0': 0;
        a2= i<s2.length() ? s2[i]-'0': 0;
        
        ans+=(((a1+a2+carry)%2)+'0');
        carry= (a1+a2+carry)/2;
        i++;
    }
    
    reverse(ans.begin(),ans.end());
    if(carry==1){
        if(!flag)
           ans=to_string(carry)+ans;
        else 
          ans=add_bin(ans,"1",0);  // add 1 to final result.
    }else {
        if(flag){
            take_1_compl(ans,ans.size());
            ans="-"+ ans;
        }
    }
    
    return ans;
}

int main() {
    
    // Binary addition 
      string sum= add_bin("10101010", "11001100", 0);
      cout<<" bin addition :";
      for(int i=0;i<sum.length();i++)
      cout<<sum[i];
      cout<<endl;
      
     /* binary subtraction using 1's complement.
     1. Take 1's compliment of no to be subtracted means take not. 
     2. add both no 
     3. if in last carry is 1 then add 1 to the no 
     4. if carry is 0 at the end then no is negative so take 1's complemnt of ans 
     and put negative sign" */
     
     string diff= add_bin("11101010","11001100",1); 
     cout<<" bin subtraction :";
     for(int i=0;i<diff.length();i++)
      cout<<diff[i];
      cout<<endl;

     
     
}