#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP
template<typename T>
class UniquePtr{
    T* p;
public:
    explicit UniquePtr(T* ptr=nullptr):p(ptr){}
    ~UniquePtr(){ delete p; }
    UniquePtr(const UniquePtr&)=delete;
    UniquePtr& operator=(const UniquePtr&)=delete;
    UniquePtr(UniquePtr&& o) noexcept: p(o.p){ o.p=nullptr; }
    UniquePtr& operator=(UniquePtr&& o) noexcept { if(this!=&o){ delete p; p=o.p; o.p=nullptr;} return *this;}
    T& operator*()const{return *p;}
    T* get()const{return p;}
};
#endif
