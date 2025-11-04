#include <bits/stdc++.h>
using namespace std;
#include <chrono>

template<typename F, typename... Args>
long long time_fn(F f, Args&&... args) {
    auto t1 = chrono::high_resolution_clock::now();
    f(forward<Args>(args)...);
    auto t2 = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
}

void work_small() { for (volatile int i=0;i<100000;i++); }
void work_big()   { for (volatile int i=0;i<2000000;i++); }

int main(){
    cout << "work_small: " << time_fn(work_small) << " us\n";
    cout << "work_big:   " << time_fn(work_big) << " us\n";
    return 0;
}
