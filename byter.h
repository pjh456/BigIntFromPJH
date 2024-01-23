#include<bitset>
#include<assert.h>
using std::bitset;
class byte{
private:
    bitset<4> data;
    byte __Add(const byte &_x,const byte &_y,bitset<1> &checker){
        byte x=_x,y=_y,ans;
        bitset<1> stayValue("0");
        for(short i=0;i<4;++i){
            ans.data[i]=x.data[i]^y.data[i]^stayValue[0];
            stayValue[0]=(x.data[i]&stayValue[0])|(y.data[i]&stayValue[0])|(x.data[i]&y.data[i]);
        }
        checker=stayValue;
        return ans;
    }
    bool IsBiggerThan(byte &x,byte &y){
        for(short i=3;i>=0;--i){
            if(x.data[i]!=y.data[i]){
                return x.data[i];
            }
        }
        return false;
    }
    byte self(){
        byte selfs;
        selfs.data=data;
        return selfs;
    }
public:
    //Constructor
    byte():data("0000"){}
    byte(const short x){
        assert(x>=0||x<10);
        for(short i=0;i<4;++i){
            data[i]=(bool)((1<<i)&x);
        }
    }
    //Value
    //Comparision
    bool operator<(bigint &x){
        return IsBiggerThan(x,self());
    }
    bool operator>=(bigint &x){
        return !IsBiggerThan(x,self());
    }
    bool operator==(bigint &x){
        return !(IsBiggerThan(self(),x)||IsBiggerThan(x,self()));
    }
    bool operator!=(bigint &x){
        return IsBiggerThan(self(),x)||IsBiggerThan(x,self());
    }
    bool operator>(bigint &x){
        return IsBiggerThan(self(),x);
    }
    bool operator<=(bigint &x){
        return !IsBiggerThan(self(),x);
    }
    //Operation
    //IO


};
