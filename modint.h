 #include<stdlib.h>
#include<iostream>
#include<assert.h>
#include "bigint.h"
class ostream;
class modint:public bigint{
private:
    bigint modvalue;
public:
    //Constructor
    modint(){}
    modint(bigint x){
        __locate=x.value();
        negative=x.neg();
    }
    modint(bigint x,bigint modd){
        x=x%modd;
        __locate=x.value();
        negative=x.neg();
        modvalue=modd;
    }
    //Value
    bigint& modnum(){
        return modvalue;
    }
    void setmod(bigint &modd){
        modvalue=modd;
    }
    //Operation
    modint operator+(modint &x){
        assert(modvalue==x.modvalue);
        bigint ans=__Add(self(),__pair(x.__locate,x.negative));
        if(!modvalue.empty()){
            ans=ans%modvalue;
        }
        return modint(ans,modvalue);
    }
    modint operator-(modint &x){
        assert(modvalue==x.modvalue);
        bigint ans=__Deq(self(),__pair(x.__locate,x.negative));
        if(!modvalue.empty()){
            ans=ans%modvalue;
        }
        return modint(ans,modvalue);
    }
    modint operator*(modint &x){
        bigint ans=__Mul(self(),__pair(x.__locate,x.negative));
        if(!modvalue.empty()){
            ans=ans%modvalue;
        }
        return modint(ans,modvalue);
    }
    modint operator/(modint &x){
        bigint ans=__Div(self(),__pair(x.__locate,x.negative));
        if(!modvalue.empty()){
            ans=ans%modvalue;
        }
        return modint(ans,modvalue);
    }
    modint operator%(modint &x){
        bigint ans=__Mod(self(),__pair(x.__locate,x.negative));
        if(!modvalue.empty()){
            ans=ans%modvalue;
        }
        return modint(ans,modvalue);
    }
    //IO
    friend std::ostream& operator<<(std::ostream& out,modint& x){
        if(x.negative){
            out<<'-';
        }
        for(short* it=x.__locate.end()-1;it!=x.__locate.begin()-1;--it){
            out<<(*it);
        }
        out<<"(mod ";
        bigint emp=bigint();
        if(x.modvalue!=emp){
            out<<x.modvalue;
        }
        else{
            out<<"None";
        }
        out<<")";
        return out;
    }
};
