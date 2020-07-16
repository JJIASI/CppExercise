# include <iostream>
# include "Date.h"
# include <utility>

using namespace std;

int main(){
    Date test1, test2, test3;

    // asignment operator test
    test2 = test1;
    // SetActivity test
    test2.SetActivity("Good Day!");
    
    // move asignment operator test
    test3 = test2+10;
    cout << test3.ISOFormat() << endl;

    test3.SetActivity("Also a Good Day!");
    // GetActivity test
    cout << test3.GetActivity() << endl;

    // move constructor test
    Date test4(move(test3));
    cout << test4.ISOFormat() << endl;
    

}