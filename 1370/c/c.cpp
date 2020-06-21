#include<iostream>
int f(int p){for(int i=2;i*i<=p;i++)if(p%i==0)return 0;return p!=1;}
int main(){
  int t,n;std::cin>>t;
  while (t--){
    std::cin>>n,puts((((n&(-n))==n&&n!=2)||(n%2==0&&f(n/2)))?"FastestFinger":"Ashishgup");
  }
}