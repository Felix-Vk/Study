#!/usr/bin/env bash
set -e
ROOT="Global_Systems_Engineer_Bootcamp"
mkdir -p "$ROOT"/{Month1/Smart_Pointer,Month1/Multithreaded_Logger,Month1/Mini_Shell,Month1/CPU_Scheduler_Simulation,Month2/Bootloader_Assembly,Month2/Kernel_Simulation,Month2/Virtual_File_System,Month3/Function_Profiler,Month3/TCP_Echo_Server,Month3/Trading_Engine_Simulator,Resources}

echo "Global Systems Engineer Bootcamp - 3 Month Pack" > "$ROOT/0_README.txt"
echo "# Global Systems Engineer Bootcamp — Starter Guide" > "$ROOT/Bootcamp_Guide.md"

cat > "$ROOT/Month1/Smart_Pointer/main.cpp" <<'CPP'
#include <iostream>
#include "unique_ptr.hpp"
int main(){
    std::cout << "Smart pointer project placeholder.\n";
    return 0;
}
CPP

cat > "$ROOT/Month1/Smart_Pointer/unique_ptr.hpp" <<'CPP'
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
CPP

echo "LearnCpp: https://www.learncpp.com/" > "$ROOT/Resources/links.txt"

zip -r "${ROOT}.zip" "$ROOT" >/dev/null || true

git add "$ROOT" "$ROOT.zip"
git commit -m "Add 3-month bootcamp starter files"
git push -u origin bootcamp/add-3month-bootcamp
