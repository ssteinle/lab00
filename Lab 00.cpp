#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;

void linSearch(int arrPass[], int sNum, int size)
{
    int i = 0;
    int gate = 0;

    cout << "Search Num: " << sNum << endl;

    while((i < size) && (gate != 1))
    {
        if(arrPass[i] == sNum)
        {
            gate = 1;
        }
        else
            i++;

        cout << "Current Num: " << i << endl;
    }

    if(gate == 1)
        cout << "Found at element: " << i;
    else
        cout << "Not Found";
}

void simSort(int arrPass[], int size)
{
    int i;
    int j;
    int tmp;

    cout << endl;

    for(i=0; i < 10; i++)
        cout << arrPass[i] << " ";

    cout << endl;

    for(i = 0; i < size; i++)
    {
        j = i;

        for(j = 0; j < size; j++)
        {
            //cout << "Comparing: " << arrPass[j] << " and: " << arrPass[j+1] << " at element: " << j << endl;
            if(arrPass[j] > arrPass[j+1])
            {
                tmp = arrPass[j+1];
                arrPass[j+1] = arrPass[j];
                arrPass[j] = tmp;
            }
        }
    }
    cout << endl;
}

void binSearch(int arrPass[], int sNum, int size)
{
    int gate = 0;
    int gate2 = 0;
    int minE = 0;
    int maxE = size-1;
    int i = (maxE + minE)/2;
    int tmp;
    int checkElement;

    while((minE != maxE) && (gate != 1) && (gate2 != 1))
    {
        cout << "Comparing: " << sNum << " and: " << arrPass[i] << " at element: " << i << endl;

        if(checkElement == i)
            gate2 = 1;

        checkElement = i;

        if(sNum == arrPass[i])
            gate = 1;
        else if(sNum < arrPass[i])
        {
            maxE = i;
            i = (minE + maxE) / 2;
        }
        else
        {
            minE = i;
            i = (minE + maxE) / 2;
        }
    }

    if(gate == 1)
        cout << "Found at element: " << i;
    else
        cout << "Not Found";
}

//*********************************************************************************************************
int partition (int arr[], int min, int max) 
{ 
    int pivot = arr[max];
    int tmp;
    int i = (min - 1);
  
    for (int j = min; j <= max - 1; j++) 
        if (arr[j] < pivot) 
        { 
            i++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        } 

    tmp = arr[i+1];
    arr[i+1] = arr[max];
    arr[max] = tmp;

    return (i + 1); 
} 

void quickSort(int arr[], int min, int max) 
{ 
    if (min < max) 
    { 
        int pi = partition(arr, min, max); 
        quickSort(arr, min, pi - 1); 
        quickSort(arr, pi + 1, max); 
    } 
} 

//*****************************************************************************************

void printArray(int arrPass[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arrPass[i] << " "; 
    cout << endl; 
} 

int main()
{
    int testOption;
    int h = 16;
    int size = h;
    int i;
    int j = h;
    static int arrVals[32];
    srand (time(NULL));
    int searchNum = rand() % j + 1;

    for(i=0; i<h; i++)
    {
        arrVals[i] = i;
        //arrVals[i] = rand() % j + 1;
        //std::this_thread::sleep_for(std::chrono::nanoseconds(10));
    }
    cout << "Enter a test option: 1) Linear Search 2) Binary Search 3) Simple Sort 4) Efficient Sort......";

    cin >> testOption;

    cout << endl;

    i = 0;

    switch (testOption)
    {
        case 1:     // Linear Search
        {
            printArray(arrVals, h);
            auto start = chrono::steady_clock::now();
            linSearch(arrVals, size-1, size);
            auto end = chrono::steady_clock::now();

            cout << endl << "Total Time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds";
            break;
        }
        case 2:     // Binary Search
        {
            //quickSort(arrVals, 0, h);
            printArray(arrVals, h);
            cout << endl;
            auto start = chrono::steady_clock::now();
            binSearch(arrVals, -1, size);
            auto end = chrono::steady_clock::now();

            cout << endl << "Total Time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds";
            break;
        }
        case 3:     // Simple Sort
        {
            auto start = chrono::steady_clock::now();
            simSort(arrVals, size);
            auto end = chrono::steady_clock::now();

            printArray(arrVals, h);
            cout << endl << "Total Time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds";
            break;
        }
        case 4:     // Efficient Sort
        {
            auto start = chrono::steady_clock::now();
            quickSort(arrVals, 0, h);
            auto end = chrono::steady_clock::now();
            printArray(arrVals, h);

            cout << endl << "Total Time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds";
            break;
        }
        default:
            cout << "Invalid Search Type";
            break;
    }

  return 0;
}