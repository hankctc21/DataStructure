#include <iostream>
#include <list>
#include <string>
#include <ctime>
using namespace std;
int main()
{
    list<string> mystrings;
    int n = 40000; // The number of inserts
    clock_t oldtime, newtime;
    double seconds;
    oldtime = clock(); 
    for(int i = 0; i < n; i++) {
        mystrings.insert(mystrings.begin(),"Hello");
    }
    newtime = clock();
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "list inserts begin took "<<seconds<<endl;
    mystrings.clear();
    oldtime = clock(); 
    for(int i = 0; i < n; i++) {
        mystrings.insert(mystrings.end(),"Hello");
    }
    newtime = clock();
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "list inserts begin took "<<seconds<<endl;
    
    // Now grab elements from the middle
    oldtime = clock();
    string value;
    for(int i = 0; i < n; i++) {
        list<string>::iterator middle = mystrings.begin();
        advance(middle,n/2);
        value = *middle;
    }
    newtime = clock();
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "list inserts begin took "<<seconds<<endl;
    
}
