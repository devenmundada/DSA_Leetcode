#include <iostream>

using namespace std;

class Nstack
{
    int *a, *top, *next;
    int n;   //No. of stack
    int size;  // size of min array
    int freeSpot; //tells about the frespace in main array

    public:
    // Ctor
    Nstack(int _n,int _s) : n(_n), size(_s)
    {
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for(int i = 0;i < n;i++){
            top[i] = -1;
        }
        
        for(int i = 0;i < size;i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
    }
    // push X into mth stack..
    bool push(int X,int m)
    {
        if(freeSpot == -1){
            return false;  //stack overflow
        }

        // 1.find index
        int index = freeSpot;

        // 2.update freeSpot
        freeSpot = next[index];

        // 3.insert the element int the main array
        a[index] = X;

        // 4.update next
        next[index] = top[m-1];

        // 5.Update top  
        top[m-1] = index;

        return true;  //Push Success
    }

    // pop from mth stack
    int pop(int m)
    {
        if(top[m-1] == -1)
        {
            return -1; //stack Underflow
        }

        int index = top[m-1];
        top[m-1] = next[index];
        int poppedElement = a[index];
        next[index] = freeSpot;
        freeSpot = index;
        return poppedElement;
    }

    ~Nstack(){
        delete[] a;
        delete[] top;
        delete[] next;
    }
};

int main()
{
    Nstack s(3,6);
    cout << s.push(10,1) << endl;
    cout << s.push(12,2) << endl;
    cout << s.push(13,2) << endl;
    cout << s.push(14,3) << endl;
    cout << s.push(15,3) << endl;
    cout << s.pop(2) << endl;

    return 0;
}
