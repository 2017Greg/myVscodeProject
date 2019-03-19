#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream inFile("test.txt", ios::in);
    if(inFile)
        inFile.close();
    else
        cout << "test.txt doesn't exist" << endl;
    ofstream oFile("test1.txt", ios::out);
    if (!oFile)
        cout << "error 1";
    else
        oFile.close();
    fstream oFile2("test2.txt", ios::out | ios::in);
    if (!oFile2)
        cout << "error 2";
    else
        oFile.close();
    return 0;
}