#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void change(vector<int>& data)
{
    data = vector<int>{1, 2, 3, 4};
}

void fileTest()
{
    fstream iofile("test.txt");
    vector<string> strs(20);
    int i = 0;
    if (!iofile)
    {
        cerr << "open file failed" << endl;
    }
    else
    {
        while (iofile >> strs[i++])
            ;
    }
    for (int j = 0; j < i - 1; j++)
    {
        cout << strs[j] << endl;
    }
    //    cout<<endl;
    cout << "after sort" << endl;
    cout << *(strs.begin()) << endl;
    sort(strs.begin(), strs.begin() + i - 1);
    cout << "i:" << i << " " << strs[1] << endl;
    for (int j = 0; j < i; j++)
    {
        cout << strs[j] << " ";
    }
    cout << endl;
}


void vectorInsert(){
    vector<int> vec1{1,2,3};
    vector<int> vec2{5,6,7};
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    for(int i=0; i<vec1.size(); ++i)
        cout << vec1[i] << "\t";
}
int main(void)
{
    // vector<int> data{1, 2, 2, 2};
    // for (int i = 0; i < data.size(); ++i)
    //     cout << "data previous: " << data[i] << endl;
    // change(data);
    // for (int i = 0; i < data.size(); ++i)
    //     cout << "data changed: " << data[i] << endl;
    vectorInsert();

    char* cha = "123";
    float num = std::stof(std::string(cha));
    cout << cha << "=" << num << endl; 
    return 0;
}