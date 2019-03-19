#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include "effolkronium/random.hpp"
using Random = effolkronium::random_static;
#define PI 3.141592653

using std::vector;
using std::string;
using std::cout;
using std::endl;

enum SORT_TYPE{INSERT, MERGE, QUICK};

void InsertSort(vector<int>& data){
    for(int i=1;i<data.size(); ++i){
        for(int j=i;j>0; -- j){
            if(data[j] < data[j-1]){
                int temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
            }
        }
    }
}

vector<int> Merge(vector<int> data_pre, vector<int> data_post){
    if(data_pre[data_pre.size()-1] <= data_post[0]){
        data_pre.insert(data_pre.end(), data_post.begin(), data_post.end());
        return data_pre;
    }    
    vector<int> data;    
    int i=0,j=0;
    while(i < data_pre.size() || j < data_post.size()){
        if(i == data_pre.size()){
            for(; j < data_post.size(); ++ j){
                data.push_back(data_post[j]);
            }            
        }
        if(j == data_post.size()){
            for(; i < data_pre.size(); ++ i){
                data.push_back(data_pre[i]);
            }
        }
        if(data_pre[i] <= data_post[j]){
            data.push_back(data_pre[i]);
            ++ i;
        }
        if(data_pre[i] > data_post[j]){
            data.push_back(data_post[j]);
            ++ j;
        }
    }
    return data;
}

void MergeSort(vector<int>& data){
    int medium = data.size()/2;
    vector<int> data_pre, data_post;
    for(int i=0, j=medium; i<medium, j<data.size(); ++ i, ++ j){
        data_pre.push_back(data[i]);
        data_post.push_back(data[j]);
    }
    if(data_pre.size() != 1)
        MergeSort(data_pre);
    if(data_post.size() != 1)
        MergeSort(data_post);
    data = Merge(data_pre, data_post);
}

void QuickSort(vector<int>& data){

}

void TimeConsumingOfSort(vector<int>& data, void(*function)(vector<int>& ), SORT_TYPE type){
    clock_t start, finish;
    double  duration;   
    start = clock();    
    function(data);   
    finish = clock();    
    duration = (double)(finish - start) / CLOCKS_PER_SEC; 
    if(type == INSERT)
        cout << "Time Consuming Of InsertSort: " << duration << "seconds." <<endl; 
    else if(type == MERGE)
        cout << "Time Consuming Of MergeSort: " << duration << "seconds." <<endl; 
    else if(type == QUICK)
        cout << "Time Consuming Of QuickSort: " << duration << "seconds." <<endl; 
    else
        cout << "请指定排序算法类型！" << endl;    
}

/* 自动生成一组数：全部逆序，数量为100万
*/ 
void test1(){
    vector<int> data;
    for(int i=0; i< pow(10,5); ++i)
        data.push_back(i);
    TimeConsumingOfSort(data, InsertSort, INSERT);
}

/* 自动生成一组数： 随机生成，数量为100万
*/
int myRandom(){
    return (int)Random::get<uint32_t>(-1, 1);
}
void test2(){
    vector<int> data;
    for(int i=0; i< 100; ++ i)
        data.push_back(myRandom());
    //TimeConsumingOfSort(data, InsertSort, INSERT);
    TimeConsumingOfSort(data, MergeSort, MERGE);
    for(int i=0; i<100; ++ i)
        cout << data[i] << endl;
}

void test3(){
    vector<int> data{9,6,8,7,2,4,1,5};
    TimeConsumingOfSort(data, MergeSort, MERGE);
    for(int i=0; i<data.size(); ++ i)
        cout << data[i] << endl;
}

int main(){
    test2();
    return 0;
}