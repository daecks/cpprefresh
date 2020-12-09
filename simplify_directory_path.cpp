#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

// Takes a path and returns a simplified version of it
// backing up a directory when ".." is seen and remaining
// in current when "." is seen.

string simplify(string path){
    stringstream ss(path);
    string dir_name;
    stack<string> stack;

    while(getline(ss, dir_name, '/')){
        if(!stack.empty() && dir_name == ".."){
            // Move up a directory, if we can
            stack.pop();
        }else if(dir_name.size() > 0 && dir_name != "."){
            // Add to the directory name stack if name is actually something
            // and is not a "current directory" shortcut, i.e. "."
            stack.push(dir_name);
        }
    }

    string simplified_path;
    while(!stack.empty()){
        simplified_path = "/" + stack.top() + simplified_path;
        stack.pop();
    }
    return simplified_path;
}

int main(){
    string path = "/home/vagrant/./../vagrant/bin/icecc";
    cout << "Input: " + path << endl;
    cout << "Output: " + simplify(path) << endl;
}