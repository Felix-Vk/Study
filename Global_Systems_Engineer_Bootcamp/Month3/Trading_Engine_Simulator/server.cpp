#include <bits/stdc++.h>
#include <mutex>
#include <thread>
using namespace std;

struct Order { int id; string side; int qty; double price; };
vector<Order> book;
mutex m;

void process_order(const Order& o) {
    lock_guard<mutex> lk(m);
    book.push_back(o);
    cout << "Processed order " << o.id << " side=" << o.side << " price=" << o.price << "\n";
}

int main(){
    // spawn some worker threads that simulate order processing
    vector<thread> workers;
    for (int t=0;t<4;t++){
        workers.emplace_back([t](){
            for (int i=0;i<25;i++){
                Order o{ t*100 + i, (i%2==0)?"BUY":"SELL", 1, 100.0 + i };
                process_order(o);
                this_thread::sleep_for(chrono::milliseconds(5));
            }
        });
    }
    for (auto &w: workers) w.join();
    cout << "Total orders: " << book.size() << "\n";
    return 0;
}
