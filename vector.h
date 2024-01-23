#include<stdlib.h>
template<class T>class vector{
private:
    size_t __size;
    size_t __capacity;
    T* buffer;
public:
    vector():__size(0),__capacity(0),buffer(nullptr){}
    vector(const vector& x){
        __size=x.__size;
        __capacity=x.__capacity;
        buffer=new T[__capacity];
        for(size_t i=0;i<__size;++i){
            buffer[i]=x.buffer[i];
        }
    }
    ~vector(){
        delete[] buffer;
        __size=0;
        __capacity=0;
    }
    void clear(){
        delete[] buffer;
        buffer=new T[1];
        __size=0;
        __capacity=0;
    }
    T* begin(){
        return buffer;
    }
    T* end(){
        return buffer+__size;
    }
    T& front(){
        //if(__size==0)abort();
        return *buffer;
    }
    T& back(){
        //if(__size==0)abort();
        return *(buffer+__size-1);
    }
    vector& operator=(const vector& x){
        if(this==&x)return *this;
        T* temp=new T[x.__capacity];
        for(size_t i=0;i<x.__size;++i){
            temp[i]=x.buffer[i];
        }
        __size=x.__size;
        __capacity=x.__capacity;
        delete[] buffer;
        buffer=temp;
        /*
        __size=0;
        __capacity=0;
        */
        return *this;
    }
    /*
    T& operator[](size_t idx){
        return buffer[idx];
    }*/
    T& operator[](size_t idx){
        return *(buffer+idx);
    }
    bool operator==(const vector& x){
        if(__size!=x.__size)return false;
        for(int i=0;i<__size;++i){
            if(buffer[i]!=x.buffer[i])return false;
        }
        return true;
    }
    bool operator!=(const vector& x){
        if(__size!=x.__size)return true;
        for(int i=0;i<__size;++i){
            if(buffer[i]!=x.buffer[i])return true;
        }
        return false;
    }
    T& at(size_t idx){
        if(idx>=__size)abort();
        return buffer[idx];
    }
    bool empty()const{
        return __size==0?true:false;
    }
    size_t size()const{
        return __size;
    }
    size_t capacity()const{
        return __capacity;
    }
    void push_back(T x){
        if(__size==__capacity)
        {
            __capacity=__capacity?2*__capacity:1;
            T* temp=new T[__capacity];
            for(size_t i=0;i<__size;++i){
                temp[i]=buffer[i];
            }
            delete[] buffer;
            buffer=temp;
        }
        buffer[__size]=x;
        //*(buffer+__size)=x;
        __size++;
    }
    void insert(T* it,const T& x){
        size_t idx=it-buffer;
        if(__size==__capacity){
            __capacity=__capacity?2*__capacity:1;
            T* temp=new T[__capacity];
            for(size_t i=0;i<idx;++i){
                temp[i]=buffer[i];
            }
            temp[idx]=x;
            for(size_t i=idx+1;i<__size;++i){
                temp[i]=buffer[i-1];
            }
            delete[] buffer;
            buffer=temp;
        }
        else{
            for(size_t i=idx+1;i<__size;++i){
                buffer[i]=buffer[i-1];
            }
            buffer[idx]=x;
        }
        __size++;
    }
    void pop_back(){
        if(__size>0)__size--;
    }
    void erase(T* it){
        int idx=it-buffer;
        for(int i=idx+1;i<__size;++i){
            buffer[i-1]=buffer[i];
        }
        __size--;
    }
    void reverse(){
        for(size_t i=0,j=__size-1;i<j;++i,--j){
            T temp=buffer[i];
            buffer[i]=buffer[j];
            buffer[j]=temp;
        }
    }
};
