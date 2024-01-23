#include<iostream>
#include "modint.h"
int main(){
    bigint a,b,modd;
    std::cin>>a;
    std::cin>>b;
    std::cin>>modd;
    modint _a=modint(a,modd),_b=modint(b,modd);

    bigint c=a+b;
    modint _c=_a+_b;
    std::cout<<c;
    std::cout<<"->";

    std::cout<<_c<<'\n';
    c=a-b;
    _c=_a-_b;
    std::cout<<c<<"->"<<_c<<'\n';
    c=a*b;
    _c=_a*_b;
    std::cout<<c<<"->"<<_c<<'\n';
    c=a/b;
    _c=_a/_b;
    std::cout<<c<<"->"<<_c<<'\n';
    c=a%b;
    _c=_a%_b;
    std::cout<<c<<"->"<<_c<<'\n';

}
