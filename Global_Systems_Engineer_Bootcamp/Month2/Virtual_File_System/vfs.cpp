#include <bits/stdc++.h>
using namespace std;

struct File { string name; string content; };

class VFS {
    vector<File> files;
public:
    void create(const string& name, const string& content) {
        files.push_back({name, content});
    }
    string read(const string& name) {
        for (auto &f : files) if (f.name==name) return f.content;
        return "";
    }
    void list() {
        for (auto &f : files) cout << f.name << "\n";
    }
    bool remove(const string& name) {
        auto it = remove_if(files.begin(), files.end(), [&](const File& f){ return f.name==name; });
        if (it==files.end()) return false;
        files.erase(it, files.end());
        return true;
    }
};

int main(){
    VFS v;
    v.create("hello.txt","Hello from VFS");
    cout << "VFS contents:\n"; v.list();
    cout << "Read hello.txt: " << v.read("hello.txt") << "\n";
    v.remove("hello.txt");
    cout << "After remove, contents:\n"; v.list();
    return 0;
}
