#include<iostream>
#include "bigint.h"
int main()
{
    //freopen("P1932_2.in","r",stdin);
    bigint a,c;
    int b,d;
    std::cin>>a;
    std::cin>>b;
    //c=a.pow(b);
    c=a/b;
    std::cout<<c;
    /*
    d=-a;
    std::cout<<d;
    std::cout<<'\n';
    std::cout<<b;
    //std::cout<<(a>b);
    //std::cout<<'\n';2
    //bigint c=a%b;
    //std::cout<<c;
    bigint c=a+b;
    std::cout<<c<<'\n';
    c=a-b;
    std::cout<<c<<'\n';
    c=a*b;
    std::cout<<c<<'\n';
    c=a/b;
    std::cout<<c<<'\n';
    c=a%b;
    std::cout<<c<<'\n';
    */
}
