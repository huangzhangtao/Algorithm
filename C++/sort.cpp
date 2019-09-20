#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void bubble_sort(vector<int>& test)
{ 
    int len = test.size();
    for(int i = len - 1; i > 0; --i)
    {
        bool flag = false;  //冒泡排序优化
        for(int j = 0; j < i; ++j)
            if(test[j] > test[j+1])
            {
                flag = true;
                swap(test[j], test[j+1]);
            }
        if(!flag) break;
    }
}

void selection_sort(vector<int>& test)
{
    int min, len = test.size();
    for(int i = 0; i < len - 1; ++i)
    {
        min = i;
        for(int j = i + 1; j < len; ++j)
            if(test[j] < test[min])
                min = j;
        if(min != i)
            swap(test[min], test[i]);
    }
}


void insertion_sort(vector<int>& test)
{
    int len = test.size();
    for(int i = 1; i < len; ++i)
        for(int j = i; j > 0 && test[j] < test[j-1]; --j)
            swap(test[j], test[j-1]);
}


void shell_sort(vector<int>& test)
{
    int len = test.size(), h = 1;
    while(h < len/3)  h = 3*h + 1;
    
    while(h >= 1)
    {
    for(int i = h; i < len; i++)
        for(int j = i; j >= h && test[j] < test[j-h]; j-=h)
            swap(test[j], test[j-h]);
    h /= 3;
    }
}

void merge(vector<int>& test, int lo, int mid, int hi)
{
     int i = lo, j = mid + 1;
     vector<int> temp(test.size());
     for(int p = lo; p <= hi; ++p)
         temp[p] = test[p];

     for(int q = lo; q <= hi; ++q)
     {
         if(i > mid) test[q] = temp[j++];
         else if(j > hi) test[q] = temp[i++];
         else if(temp[i] > temp[j]) test[q] = temp[j++];
         else test[q] = temp[i++];
     }
}

void merge_sort(vector<int>& test, int lo, int hi) //自顶向下
{
    if(lo >= hi) return;
    int mid = (hi + lo)/2;
    merge_sort(test, lo, mid);
    merge_sort(test, mid + 1, hi);
    merge(test, lo, mid, hi);
}

int partition(vector<int>& test, int lo, int hi)
{
   int i = lo, j = hi, v = test[lo];

   while (true)
   {
       while (test[++i] < v) if (i == hi) break;
       while (test[--j] > v) continue;
       if (i >= j) break;
       swap(test[i], test[j]);
   }
   swap(test[lo], test[j]);
   return j;
}

void quick_sort(vector<int>& test, int lo, int hi)
{
    if(lo >= hi) return;
    int j = partition(test, lo, hi);
    quick_sort(test, lo, j-1);
    quick_sort(test, j+1, hi);
}

void quick3_sort(vector<int>& test, int lo, int hi)  //三向切分快排
{
    int v = test[lo], lt = lo, i = lo + 1, gt = hi;
    
    if (lo >= hi) return;
    
    while(i <= gt)
    {
        if (test[i] < v) swap(test[lt++], test[i++]);
        else if (test[i] > v) swap(test[gt--], test[i++]);
        else ++i;
    }

    quick3_sort(test, lo, lt-1);
    quick3_sort(test, gt+1, hi);
}



int main()
{
    int n;
    vector<int> test;

    cin >> n;

    for(int i = n; i > 0; --i)
        test.push_back(i);

    //sort(test);

    for(auto x : test)
        cout << x << " ";

    return 0;
}
