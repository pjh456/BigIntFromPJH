#include<stdlib.h>
#include<iostream>
#include<ostream>
#include<istream>
#include<assert.h>
#include "vector.h"
class istream;
class ostream;

class bigint{
protected:
//public:
    vector<short> __locate;
    bool negative;
    bigint __Build(const bigint &_x){
        bigint x=_x;
        if(x.__locate.size()){
            while(!x.__locate.back()){
                x.__locate.pop_back();
            }
        }
        if(x.__locate.empty()){
            x.__locate.push_back(0);
            x.negative=false;
        }
        return x;
    }
    bigint __Add(const bigint &_x,const bigint &_y){
        bigint x=_x,y=_y,ans;
        if(x.negative==y.negative){
            size_t _size=x.__locate.size()>y.__locate.size()?x.__locate.size():y.__locate.size();
            int stayValue=0;
            for(size_t i=0;i<_size;++i){
                if(i<x.__locate.size()){
                    stayValue+=x.__locate[i];
                }
                if(i<y.__locate.size()){
                    stayValue+=y.__locate[i];
                }
                ans.push_back(stayValue%10);
                stayValue/=10;
            }
            while(stayValue){
                ans.push_back(stayValue%10);
                stayValue/=10;
            }
            ans.negative=x.negative;
        }
        else{
            y.negative^=1;
            ans=__Deq(x,y);
        }
        return ans;
    }
    bigint __Deq(const bigint &_x,const bigint &_y){
        bigint x=_x,y=_y,ans;
        if(x.negative==y.negative){
            bool swapped=false;
            int stayValue=0;
            if((x<y)^(x.negative)){
                x=_y,y=_x;
                swapped=true;
            }
            size_t _size=x.__locate.size()>y.__locate.size()?x.__locate.size():y.__locate.size();
            for(size_t i=0;i<_size;++i){
                if(i<x.__locate.size()){
                    stayValue+=x.__locate[i];
                }
                if(i<y.__locate.size()){
                    stayValue-=y.__locate[i];
                }
                while(stayValue<0){
                    stayValue+=10;
                    x.__locate[i+1]-=1;
                }
                ans.push_back(stayValue%10);
                stayValue/=10;
            }
            while(stayValue){
                ans.push_back(stayValue%10);
                stayValue/=10;
            }
            ans=__Build(ans);
            ans.negative=x.negative^swapped;
            return ans;
        }
        else{
            y.negative^=1;
            //std::cout<<y;
            ans=__Add(x,y);
            //std::cout<<ans;
            //ans.negative=x.negative;
            return ans;
        }
    }
    bigint __Mul(const bigint &_x,const bigint &_y){
        bigint x=_x,y=_y,ans;
        for(size_t i=0;i<x.__locate.size();++i){
            bigint memory;
            size_t stayValue=0;
            for(size_t j=0;j<i;++j){
                memory.push_back(0);
            }
            for(size_t j=0;j<y.__locate.size();++j){
                stayValue+=x.__locate[i]*y.__locate[j];
                memory.push_back(stayValue%10);
                stayValue/=10;
            }
            while(stayValue){
                memory.push_back(stayValue%10);
                stayValue/=10;
            }
            ans=ans+memory;
        }
        return ans;
    }
    bigint __Div(const bigint &_x,const bigint &_y){
        bigint x=_x,y=_y,ans,stayValue;
        bool swapped=x.negative^y.negative;
        x.negative=y.negative=false;
        while(!x.__locate.empty()){
            stayValue.push_back(x.__locate.back());
            x.__locate.pop_back();
            stayValue.__locate.reverse();
            stayValue=__Build(stayValue);
            bigint memory;
            memory.push_back(0);
            size_t i=0;
            if(stayValue==memory){
                ans.push_back(0);
            }
            else{
                for(;i<=10;++i){
                    if(memory>stayValue){
                        memory=memory-y;
                        ans.push_back(i-1);
                        break;
                    }
                    memory=memory+y;
                }
                stayValue=stayValue-memory;
            }
            stayValue.__locate.reverse();
            stayValue=__Build(stayValue);
        }
        ans.__locate.reverse();
        ans.negative=swapped;
        ans=__Build(ans);
        return ans;
    }
    bigint __Mod(const bigint &_x,const bigint &_y){
        bigint x=_x,y=_y,stayValue;
        bool ModIsNeg=x.negative^y.negative;
        x.negative=y.negative=false;
        while(!x.__locate.empty()){
            stayValue.push_back(x.__locate.back());
            x.__locate.pop_back();
            stayValue.__locate.reverse();
            stayValue=__Build(stayValue);
            bigint memory;
            memory.push_back(0);
            size_t i=0;
            if(stayValue!=memory){
                for(;i<=10;++i){
                    if(memory>stayValue){
                        memory=memory-y;
                        break;
                    }
                    memory=memory+y;
                }
                stayValue=stayValue-memory;
            }
            stayValue.__locate.reverse();
        }
        stayValue.negative=ModIsNeg;
        stayValue.__locate.reverse();
        stayValue=__Build(stayValue);
        while(stayValue.neg()){
            stayValue+=y;
        }
        return stayValue;
    }
    bool IsBiggerThan(const bigint& _x,const bigint& _y){
        bigint x=_x,y=_y;
        if(x.negative!=y.negative){
            return y.negative;
        }
        if(x.__locate.size()!=y.__locate.size()){
            return (x.__locate.size()>y.__locate.size())^x.negative;
        }
        size_t _size=x.__locate.size();
        if(_size==0){
            return false;
        }
        for(size_t i=_size-1;i>=0;--i){
            if(x.__locate[i]!=y.__locate[i]){
                return (x.__locate[i]>y.__locate[i])^x.negative;
            }
            if(i==0){
                break;
            }
        }
        return false;
    }
    bigint self(){
        bigint selfs;
        selfs.__locate=this->__locate;
        selfs.negative=this->negative;
        return selfs;
    }
    void selfIs(bigint x){
        this->__locate=x.__locate;
        this->negative=x.negative;
    }
    bigint __pair(const vector<short> &__locate_n,const bool &negative_n){
        bigint selfs;
        selfs.__locate=__locate_n;
        selfs.negative=negative_n;
        return selfs;
    }
public:
    //Constructor
    bigint():__locate(vector<short>()),negative(false){
    }
    bigint(const std::string &_inputs):__locate(vector<short>()),negative(false){
        std::string inputs=_inputs;
        //std::cout<<inputs;
        if(inputs.front()=='-'){
            negative=true;
            inputs.erase(0);
        }
        while(!inputs.empty()){
            __locate.push_back((short)(inputs.back()-'0'));
            inputs.pop_back();
        }
    }
    //Value
    void push_back(const short &x){
        __locate.push_back(x);
    }
    void push_front(const short &x){
        __locate.insert(__locate.begin(),x);
    }
    vector<short> value(){
        return __locate;
    }
    bool neg(){
        return negative;
    }
    size_t size(){
        return __locate.size();
    }
    bool empty(){
        return __locate.empty();
    }
    //equation
    void memorize(const std::string &_inputs){
        __locate.clear();
        std::string inputs=_inputs;
        if(inputs.front()=='-'){
            negative=true;
            inputs.erase(0);
        }
        while(!inputs.empty()){
            __locate.push_back((short)(inputs.back()-'0'));
            inputs.pop_back();
        }
    }
    void operator=(const bigint &x){
        __locate=x.__locate;
        negative=x.negative;
    }
    //Dimical comparision
    bool operator<(bigint &x){
        return IsBiggerThan(x,__pair(__locate,negative));
    }
    bool operator>=(bigint &x){
        return !IsBiggerThan(x,__pair(__locate,negative));
    }
    bool operator==(bigint &x){
        return !(IsBiggerThan(__pair(__locate,negative),x)||IsBiggerThan(x,__pair(__locate,negative)));
    }
    bool operator!=(bigint &x){
        return IsBiggerThan(__pair(__locate,negative),x)||IsBiggerThan(x,__pair(__locate,negative));
    }
    bool operator>(bigint &x){
        return IsBiggerThan(__pair(__locate,negative),x);
    }
    bool operator<=(bigint &x){
        return !IsBiggerThan(__pair(__locate,negative),x);
    }
    //Dimaric operation
    bigint operator+(const bigint &x){
        return __Add(self(),x);
    }
    void operator+=(const bigint &x){
        selfIs(__Add(self(),x));
    }
    bigint operator-(const bigint &x){
        return __Deq(self(),x);
    }
    void operator-=(const bigint &x){
        selfIs(__Deq(self(),x));
    }
    bigint operator*(const bigint &x){
        return __Mul(self(),x);
    }
    void operator*=(const bigint &x){
        selfIs(__Mul(self(),x));
    }
    bigint operator/(const bigint &x){
        return __Div(self(),x);
    }
    void operator/=(const bigint &x){
        selfIs(__Div(self(),x));
    }
    bigint operator%(const bigint &x){
        return __Mod(self(),x);
    }
    //IO
    friend std::istream& operator>>(std::istream& in,bigint& x){
        x.__locate.clear();
        std::string inputs;
        in>>inputs;
        if(inputs.front()=='-'){
            x.negative=true;
            inputs.erase(0,1);
        }
        while(!inputs.empty()){
            x.__locate.push_back((short)(inputs.back()^48));
            inputs.pop_back();
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out,bigint& x){
        x=x.__Build(x);
        if(x.negative){
            out<<'-';
        }
        for(short* it=x.__locate.end()-1;it!=x.__locate.begin()-1;--it){
        //for(vector<short>::iterator it=x.__locate.begin();it!=x.__locate.end();++it){
            out<<(*it);
        }
        return out;
    }
};
