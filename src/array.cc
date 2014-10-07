#include "array.h"
using namespace std;

void printArray(const vector<double>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i];
        if(i != arr.size() - 1) cout<<", ";
    }
    cout<<endl;
}


int partition(vector<double> &input, int head, int tail){
    int left = 0;
    int right = tail - head;
    double pivot = input[tail];
    vector<double> tmpvec(right + 1, 0.0);
    for(int i = head; i <= tail - 1; i ++){
        if(input[i] <= pivot){
            tmpvec[left++] = input[i];
        }else{
            tmpvec[right--] = input[i];
        }
    }
    tmpvec[left] = pivot;
    for(int i = 0; i < tmpvec.size(); i++){
        input[head + i] = tmpvec[i];
    }
    tmpvec.clear();
    return left + head;
}



void quickSort(vector<double> &input, int head, int tail){
    if(head < tail){
        int mid = partition(input, head, tail);   
        quickSort(input, head, mid - 1);
        quickSort(input, mid + 1, tail);
    }
}


void merge(vector<double> &input, int head, int mid, int tail){

    vector<double> l;
    for(int i = head; i <= mid; i++){
        l.push_back(input[i]);
    }
    vector<double> r;
    for(int i = mid + 1; i <= tail; i++){
        r.push_back(input[i]);
    }
    int left = 0;
    int right = 0;
    for(int i = head; i <= tail; i++){
        if(left < l.size() && right < r.size()){
            if(l[left] <= r[right]){
                input[i] = l[left++];
            }else{
                input[i] = r[right++];
            }
        }elif(left < l.size()){
            input[i] = l[left++];
        }elif(right < r.size()){
            input[i] = r[right++];
        }
    }
}

void mergeSort(vector<double> &input, int head, int tail){
    if(head < tail){
        int mid = head + (tail - head) / 2;
        mergeSort(input, head, mid);
        mergeSort(input, mid + 1, tail);
        merge(input, head, mid, tail);
    }   
}













