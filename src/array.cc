#include "array.h"
using namespace std;

void printArray(const vector<double>& arr){
    if(arr.empty()) cout<<"Empty Array"<<endl;
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

// select the nth largest element in the array.
// If it does not exist, return INT_MIN
double quickSelect(vector<double>& input, int head, int tail, int nth){
    cout<<"head = "<<head<<", tail = "<<tail<<", nth = "<<nth<<endl;
    printArray(input);
    if(input.empty()) return (double)INT_MIN;
    if(nth < 0) return (double)INT_MIN;
    if(nth > input.size()) return (double)INT_MIN;
    if(head < tail){
        int pivot = partition(input, head, tail);
        if(pivot == nth) return input[pivot];
        elif(pivot > nth) return quickSelect(input, head, pivot - 1, nth);
        else return quickSelect(input, pivot + 1, tail, nth);
    }
    return (double)INT_MIN;
}

void rightRotate(vector<double>& input, int offset){
    if(offset == 0) return;
    vector<double> output;
    output.insert(output.begin(), input.begin(), input.begin() + input.size() - offset);
    output.insert(output.begin(), input.begin() + input.size() - offset, input.end());
    swap(input, output);
    output.clear();
}

void leftRotate(vector<double>& input, int offset){
    if(offset == 0) return;
    vector<double> output;
    output.insert(output.begin(), input.begin(), input.begin() + offset);
    output.insert(output.begin(), input.begin() + offset, input.end());
    swap(input, output);
    output.clear();
}

// simple binary search, returns the address, or -1 (if not exist)
int binarySearch(vector<double>& input, int head, int tail, double val){
    int res = -1;
    if(input.empty()) return res;
    if(head > tail) return res;
    int mid = head + (tail - head) / 2;
    if(input[mid] == val) return mid;
    elif(input[mid] < val) return binarySearch(input, mid + 1, tail, val);
    else return binarySearch(input, head, mid - 1, val);
}

// General version of binary search, 
// Rotated vectors are supported.
// returns address, or -1 (if not exist)
int generalBinarySearch(vector<double>& input, int head, int tail, double val){
    int res = -1;
    if(input.empty()) return res;
    if(head > tail) return res;
    int mid = head + (tail - head) / 2;
    if(input[mid] == val) return mid;
    elif(input[mid] < val){
        if(input[mid] < input[tail]){
            // right hand side is regular array
            res = binarySearch(input, mid + 1, tail, val);
            if(res > 0) return res;
            else return generalBinarySearch(input, head, mid - 1, val);
        }else{
            // right hand side is rotated
            return generalBinarySearch(input, mid + 1, tail, val);
        }
    }else{
        if(input[mid] < input[tail]){
            // right hand side is regular array
            return generalBinarySearch(input, head, mid - 1, val);
        }else{
            // right hand side is rotated
            res = binarySearch(input, head, mid - 1, val);
            if(res > 0) return res;
            else return generalBinarySearch(input, mid + 1, tail, val);
        }
    }
}





















