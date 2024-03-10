#include<iostream>
#include<algorithm>
using namespace std ;
string encrypted;
void encrypt(int one , int zero,string s,int& iterate){
      if(iterate==0)return;
      else if(one==0 && zero==0){
        iterate--;
        if(iterate==0)encrypted=s;
        
      }
      else if(one==0){
            s.push_back('0');
            zero--;
            encrypt(one,zero,s,iterate);
            

      }
      else if(zero==0){
            s.push_back('1');
            one--;
            encrypt(one,zero,s,iterate);
      

      }
      else{
            encrypt(one-1,zero,s+"1",iterate);
            encrypt(one,zero-1,s+"0",iterate);

      }


}

int main(){
    string s ;
    cout<<"Enter your message you want to encrypt ";
    
    getline(cin,s);               

    string encrypted_data;
    for(int i = 0 ; i<s.size() ; i++){
        int x = (int)s[i];
        int iterate=x-31;
        encrypt(5,5,"",iterate);
        encrypted_data+=encrypted;

        
    }
    for(int i = 0 ; i<encrypted_data.size(); i+=2){
        swap(encrypted_data[i],encrypted_data[i+1]);
    }
    int p = 0 ;
    int q = encrypted_data.size()-1;
    while(q>p){
        swap(encrypted_data[p],encrypted_data[q]);
        p+=2;
        q-=2;
    }
    reverse(encrypted_data.begin(),encrypted_data.end());



    cout<<encrypted_data;
}