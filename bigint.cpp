#include<iostream>
#include "bigint.h"
int main()
{
    bigint a,b;
    std::cin>>a;
    std::cin>>b;
    /*
    std::cout<<a;
    std::cout<<b;
    std::cout<<'\n';
    */
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
}
