#include <bits/stdc++.h>
using namespace std;
//-------------------------- Decimal to other type conversion. 
int string_to_int(string s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}

string dec_to_hex(string s){
    stack<char> st;
    string ans;
    int temp = string_to_int(s);
    
    while(temp){
        if(temp%16>=10)
            st.push((temp%16)%10+'A');
        else 
            st.push(temp%16+'0');
        temp/=16;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

string dec_to_oct(string s){
    stack<char> st;
    int temp=string_to_int(s);
    string ans;
    while(temp){
        st.push(temp%8+'0');
        temp/=8;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

string dec_to_bin(string s){
    stack<char> st;
    int temp=string_to_int(s);
    string ans;
    while(temp){
        st.push(temp%2+'0');
        temp/=2;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
//---------------------------------------- Other type to decimal conversion. 

int bin_to_dec(string s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        ans+=(s[i]-'0')*pow(2,s.length()-i-1);
    }
    return ans;
}

int hex_to_dec(string s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='F'){
            ans+=(s[i]-'A'+10)*pow(16,s.length()-1-i);
        }
        else
        ans+=(s[i]-'0')*pow(16,s.length()-1-i);
    }
    return ans;
}

int oct_to_dec(string s){
    int ans =0;
    for(int i=0;i<s.length();i++){
        ans+=(s[i]-'0')*pow(8,s.length()-i-1);
    }
    return ans;
}

int main() {
    string d2b = dec_to_bin("1000000");
    string d2h = dec_to_hex("35359");
    string d2o = dec_to_oct("23444");
    int b2d = bin_to_dec("11110100001001000000");
    int h2d = hex_to_dec("8A1F");
    int o2d = oct_to_dec("55624");
    
    
    
    /*to convert any no to other form first convert it to dec then convert to other form. 
    Or to conver bin to octal convert in group of 3 bits from right. 
    to convert bin to her convert in group of 4 bits from right. 
    */
    
    for(int i=0;i<d2b.length();i++)
    cout<<d2b[i];
    cout<<endl;
    for(int i=0;i<d2h.length();i++)
    cout<<d2h[i];
    cout<<endl;
    for(int i=0;i<d2o.length();i++)
    cout<<d2o[i];
    cout<<endl;
    cout<<b2d<<endl;
    cout<<h2d<<endl;
    cout<<o2d<<endl;
}