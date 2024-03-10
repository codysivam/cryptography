#include<iostream>
#include<algorithm>
using namespace std;
int value=0;

void decrypt(int one , int zero,string s,int& iterate,string a){
      if(value!=0)return;
      else if(one==0 && zero==0){
        iterate++;
        if(a==s)value=iterate;

      }
      else if(one==0){
            s.push_back('0');
            zero--;
            decrypt(one,zero,s,iterate,a);

      }
      else if(zero==0){
            s.push_back('1');
            one--;
            decrypt(one,zero,s,iterate,a);
            
      }
      else{
            decrypt(one-1,zero,s+"1",iterate,a);
            decrypt(one,zero-1,s+"0",iterate,a);


      }


}
int main(){
    string encrypted_data ;
    cout<<"enter the message you want to decrypt ";
    
    string decrypted_data;
    getline(cin,encrypted_data);
    reverse(encrypted_data.begin(),encrypted_data.end());
    int p = 0 ;
    int q = encrypted_data.size()-1;
    while(q>p){
        swap(encrypted_data[p],encrypted_data[q]);
        p+=2;
        q-=2;
    }
    for(int i = 0 ; i<encrypted_data.size(); i+=2){
        swap(encrypted_data[i],encrypted_data[i+1]);
    }
    for(int i = 0 ; i<encrypted_data.size() ; i+=10){
        string a = encrypted_data.substr(i,10);
        int iterate=0;
        decrypt(5,5,"",iterate,a);
        int b = value + 31;
        value=0;
        char ch =(char)b;
        
        decrypted_data.push_back(ch);

    }
    cout<<decrypted_data;


}