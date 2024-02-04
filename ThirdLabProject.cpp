#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class MyHeap {
    vector<int> HeapVector;
    int numbersRead = 0;

public:
    void ReadHeapFile() 
    {
        ifstream inputFile("Heap.txt");
        if (inputFile.is_open()) {
            int current_number;
            while (inputFile >> current_number) 
            {
                HeapVector.push_back(current_number);
                numbersRead++;
            }
            inputFile.close();
            cout << "Read " << numbersRead << " numbers from the file Heap.txt" << endl;
        } else {
            cout << "Error in opening the file Heap.txt!" << endl;
        }

        DisplayHeap();
    }

    void HeapifyDown(int i, int n) 
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && HeapVector[left] < HeapVector[largest]) 
        {
            largest = left;
        }

        if (right < n && HeapVector[right] < HeapVector[largest]) 
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(HeapVector[i], HeapVector[largest]);
            cout << "Moved element: " << HeapVector[i] << " to position: " << i << endl;
            HeapifyDown(largest, n);
        }
    }

    void SortingDownHeap()
     {
        int n = HeapVector.size();

        if (HeapVector.empty()) 
        {
            cout << "The heap is empty." << endl;
            return;
        }

        swap(HeapVector[0], HeapVector[n - 1]);
        HeapVector.pop_back();

        HeapifyDown(0, n - 1);

        cout << "Final Heap after HeapifyDown rearrangement:" << endl;

        DisplayHeap();
    }

    void HeapifyUp(int i)
    {
        if (i <= 0) 
        {
            return;
        }

        int parent = (i - 1) / 2;

        if (HeapVector[i] < HeapVector[parent]) 
        {
            swap(HeapVector[i], HeapVector[parent]);
            cout << "Moved element: " << HeapVector[i] << " to position: " << i << endl;
            HeapifyUp(parent);
        }
    }

    void InsertNewElement()
    {
        int n = HeapVector.size();
       
        cout << "Please insert a new element to the Heap: ";
        int newElement;
        cin >> newElement;

        HeapVector.push_back(newElement);

        cout << "Heap after inserting new element:" << endl;
        DisplayHeap();
    }

    void SortingUpHeap()
    {
        int n = HeapVector.size();

        if (HeapVector.empty()) 
        {
            cout << "The heap is empty." << endl;
            return;
        }

        HeapifyUp(n - 1);

        cout << "Final Heap after HeapifyUP rearrangement:" << endl;
       
       DisplayHeap();
    }

    void DisplayHeap()
    {
        for (int k = 0; k < HeapVector.size(); k++) 
        {
            cout << HeapVector[k] << endl;
        }
    }
};

int main() 
{
    MyHeap Heap;

    Heap.ReadHeapFile();
    Heap.SortingDownHeap();
    Heap.InsertNewElement();
    Heap.SortingUpHeap();

    return 0;
}
