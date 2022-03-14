#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in("input.txt");
ofstream out("output.csv");

vector<long long> generateNumbers(int &n, long long &maxim) {
    in >> n >> maxim;
    random_device rd;
    mt19937_64 eng(rd());
    uniform_int_distribution<unsigned long long> distr;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        v[i] = distr(eng) % maxim;
    return v;

}


void countSort(vector<long long> &v, vector<long long> &output, int n, long long exp) {
    int count[10] = {};
    for (int i = 0; i < n; i++)
        count[v[i] / exp % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
        output[count[v[i] / exp % 10]-- - 1] = v[i];
    for (int i = 0; i < n; i++)
        v[i] = output[i];
}


void radixSort(vector<long long> &v, int n, long long maxim) {
    vector <long long> output(n);
    for (int exp = 1; maxim / exp > 0; exp *= 10)
        countSort(v, output, n, exp);

}

bool verificare(vector<long long>&sortat, vector<long long> &v, int n)
{
    for(int i=0;i<n;i++)
        if(sortat[i]!=v[i])
            return 0;
    return 1;
}

auto timeRadixSort(vector<long long>&verif,vector<long long>&v,int n,long long maxim)
{
    vector<long long>copie=v;
    auto start = chrono::high_resolution_clock::now();
    radixSort(copie,n,maxim);
    auto stop = chrono::high_resolution_clock::now();
    if(verificare(verif,copie,n)==0)
    {
        cout<<"eroare";
        exit(1);
    }
    auto duration = chrono::duration_cast<chrono::microseconds >(stop-start);
    return duration.count();

}

void countSortB2(vector<long long> &v, vector<long long> &output, int n, long long exp, long long base) {
    int len = 1<<base;
    vector<int> count(len);
    long long mask = (1<<base)-1;
    for (int i = 0; i < n; i++)
        count[(v[i] >> exp) & mask]++;
    for (int i = 1; i < len; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
        output[count[(v[i] >> exp) & mask]-- - 1] = v[i];
    for (int i = 0; i < n; i++)
        v[i] = output[i];
}



void radixSortB2(vector<long long> &v, int n, long long maxim, long long base) {
    vector <long long> output(n);
    for (long long exp = 0; (1<<exp)<maxim && exp<64; exp += base)
        countSortB2(v, output, n, exp, base);

}
auto timeRadixSortB2(vector<long long>&verif,vector<long long>&v,int n,long long maxim,long long base)
{
    vector<long long>copie=v;
    auto start = chrono::high_resolution_clock::now();
    radixSortB2(copie,n,maxim,base);
    auto stop = chrono::high_resolution_clock::now();
    if(verificare(verif,copie,n)==0)
    {
        cout<<"eroare";
        exit(1);
    }
    auto duration = chrono::duration_cast<chrono::microseconds >(stop-start);
    return duration.count();

}


void merge(vector<long long>&v, vector<long long> &aux1, int start1, int stop1, vector<long long> &aux2, int start2, int stop2  )
{
    for(int k=start1;k<=stop2;k++)
    {
        if(start1>stop1)
        {
            v[k]=aux2[start2++];
            continue;
        }
        if(start2>stop2)
        {
            v[k]=aux1[start1++];
            continue;
        }
        v[k]=aux1[start1]<aux2[start2] ? aux1[start1++] : aux2[start2++];
    }
}


void mergeSort(vector<long long> &v, vector<long long > &aux, int left, int right ) {
    if(left>=right)
        return ;
    int mid=left+((right-left)>>1);
    mergeSort(aux,v,left,mid);
    mergeSort(aux, v, mid+1, right);
    merge(v, aux, left, mid, aux, mid+1, right);

}


auto timeMergeSort(vector<long long>&verif,vector<long long>&v,int n,long long maxim)
{
    vector<long long>copie=v;
    vector<long long>aux(copie);
    auto start = chrono::high_resolution_clock::now();
    mergeSort(copie,aux,0,n-1);
    auto stop = chrono::high_resolution_clock::now();
    if(verificare(verif,copie,n)==0)
    {
        cout<<"eroare";
        exit(1);
    }
    auto duration = chrono::duration_cast<chrono::microseconds >(stop-start);
    return duration.count();

}

vector<long long> gaps = {  89766, 40803, 18315,8124,3611,1605,701, 301, 132, 57, 23, 10, 4, 1};


void shellSortCustom(vector<long long> &v, int n )
{
    int i,j,offset,temp;
    for(long long gap:gaps)
        for( offset=0;offset<gap;offset++)
            for( i=offset;i<n;i+=gap)
            {
                temp=v[i];
                for( j=i;j>=gap && v[j-gap]>temp;j-=gap)
                    v[j]=v[j-gap];
                v[j]=temp;
            }


}

void shellSort(vector<long long>&v, int n)
{
    for(int gap = n>>1;gap>0;gap>>=1)
    {
        for(int i=gap;i<n;i++)
        {
            int temp=v[i];
            int j;
            for( j=i;j>=gap && v[j-gap]>temp;j-=gap)
                v[j]=v[j-gap];
            v[j]=temp;
        }
    }
}

auto timeShellSort(vector<long long>&verif,vector<long long>&v,int n,long long maxim)
{
    vector<long long>copie=v;
    vector<long long>aux(copie);
    auto start = chrono::high_resolution_clock::now();
    shellSort(copie,n);
    auto stop = chrono::high_resolution_clock::now();
    if(verificare(verif,copie,n)==0)
    {
        cout<<"eroare";
        exit(1);
    }
    auto duration = chrono::duration_cast<chrono::microseconds >(stop-start);
    return duration.count();

}

auto timeShellSortCustom(vector<long long>&verif,vector<long long>&v,int n,long long maxim)
{
    vector<long long>copie=v;
    auto start = chrono::high_resolution_clock::now();
    shellSortCustom(copie,n);
    auto stop = chrono::high_resolution_clock::now();
    if(verificare(verif,copie,n)==0)
    {
        cout<<"eroare";
        exit(1);
    }
    auto duration = chrono::duration_cast<chrono::microseconds >(stop-start);
    return duration.count();

}

inline void Swap(long long &a, long long &b)
{
    a^=b;
    b=a^b;
    a=a^b;
}

long long median3(vector<long long>&v, int st,int dr)
{
    int mid=(st+dr)/2;
    if(v[mid]<v[st])
        Swap(v[mid],v[st]);
    if(v[dr]<v[st])
        Swap(v[dr],v[st]);
    if(v[mid]<v[dr])
        Swap(v[mid],v[dr]);
    return v[dr];

}

int partition(vector<long long>&v, int st, int dr)
{
    long long pivot=median3(v,st,dr);
    int i=st-1;
    int j=dr+1;
    while(1)
    {
        do{j--;}while(v[j]>pivot);
        do{i++;}while(v[i]<pivot);
        if(i<j)Swap(v[i],v[j]);
        else return j+1;
    }
}

void qSort(vector<long long> &v, int st,int dr) {
    if(st>=dr)
        return ;
    int p=partition(v,st,dr);
    qSort(v,st,p-1);
    qSort(v,p,dr);
}

auto timeQSort(vector<long long>&verif,vector<long long>&v,int n,long long maxim)
{
    vector<long long>copie=v;
    auto start = chrono::high_resolution_clock::now();
    qSort(copie,0,n-1);
    auto stop = chrono::high_resolution_clock::now();
    if(verificare(verif,copie,n)==0)
    {
        cout<<"eroare";
        exit(1);
    }
    auto duration = chrono::duration_cast<chrono::microseconds >(stop-start);
    return duration.count();

}



void heapify(vector<long long> &v, long long n, long long i){
    long long largest = i, left = (i << 1) + 1, right = (i << 1) + 2;

    if (left < n && v[left] > v[largest])
        largest = left;

    if (right < n && v[right] > v[largest])
        largest = right;

    if (largest != i) {
        Swap( v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void heapSort(vector<long long> &v, long long n){
    long long i;
    for (i = (n >> 1) - 1; i >= 0; i--)
        heapify(v, n, i);

    for (i = n - 1; i > 0; i--) {
        Swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}
auto timeHeapSort(vector<long long>&verif,vector<long long>&v,int n,long long maxim)
{
    vector<long long>copie=v;
    auto start = chrono::high_resolution_clock::now();
    heapSort(copie,n);
    auto stop = chrono::high_resolution_clock::now();
    if(verificare(verif,copie,n)==0)
    {
        cout<<"eroare";
        exit(1);
    }
    auto duration = chrono::duration_cast<chrono::microseconds >(stop-start);
    return duration.count();

}

int main() {
    int start,final,pas;
    long long maxim;
    in>>start>>final>>pas>>maxim;
    out<<",StlSort"<<",RadixSortB10"<<",RadixSortB8"<<",RadixSortB16"<<",MergeSort"<<",ShellSort"<<",ShellSortCustom"<<",QuickSort"<<",HeapSort"<<'\n';
    for (int i=start; i<=final; i+=pas) {
        out<<i<<",";
        vector<long long> v = generateNumbers(i,maxim);
        vector<long long> copie=v;
        auto start = chrono::high_resolution_clock::now();
        sort(copie.begin(),copie.end());
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds >(stop-start);
        out<<duration.count();
        out<<","<<timeRadixSort(copie,v,i,maxim); out<<","<<timeRadixSortB2(copie,v,i,maxim,8);
        out<<","<<timeRadixSortB2(copie,v,i,maxim,16);
        out<<","<<timeMergeSort(copie,v,i,maxim);
        out<<","<<timeShellSort(copie,v,i,maxim);
        out<<","<<timeShellSortCustom(copie,v,i,maxim);
        out<<","<<timeQSort(copie,v,i,maxim);
        out<<","<<timeHeapSort(copie,v,i,maxim);
        out<<'\n';

    }
    return 0;
}
