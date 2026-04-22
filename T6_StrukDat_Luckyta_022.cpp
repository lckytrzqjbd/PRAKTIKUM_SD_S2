#include <iostream>
#include <queue>
#include <stack>
#define maks 20;
using namespace std;

int main() {
    string input;
    cout << "Input\n";
    cin >> input;

        queue <char> q;
        stack <char> s;
        
        for (char c : input) {
            q.push(c);
            s.push(c);
        }
        
        bool isPalindrome = true;
        
        while (!q.empty()) {
            if (q.front() != s.top()) {
                
                isPalindrome = false;
                break;
            }
            q.pop();
            s.pop();
        }             
    cout << "output\n";
    if (isPalindrome) {
        cout << "queue palindrom";
    } else {
        cout << "queue tidak palindrom";
    }
    
    
    return 0;
}