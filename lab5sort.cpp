#include <iostream>
#define n 5

using namespace std;

class Array
{
private:
    double Arrayy[n];
public:
    friend void InputArray(Array array[]);
    friend void OutputArray(Array array[]);
    friend void BubleSortArray(Array array[]);
    friend void CalcArray(Array array[]);
};
void InputArray(Array  array[])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "[" << i + 1 << "][" << j + 1  << "] = ";
            cin >> array[i].Arrayy[j];
        }
}
void OutputArray(Array  array[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << array[j].Arrayy[i] << "\t";
        }
        cout << endl;
    }
}


void BubleSortArray(Array  array[])
{
    for (int i = 0; i < n; i++)
    {
        for (int BlockSizeIterator = 1; BlockSizeIterator < n; BlockSizeIterator *= 2)
        {
            for (int BlockIterator = 0; BlockIterator < n - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
            {
                int LeftBlockIterator = 0;
                int RightBlockIterator = 0;
                int LeftBorder = BlockIterator;
                int MidBorder = BlockIterator + BlockSizeIterator;
                int RightBorder = BlockIterator + 2 * BlockSizeIterator;
                RightBorder = (RightBorder < n) ? RightBorder : n;
                int* SortedBlock = new int[RightBorder - LeftBorder];
                
                while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
                {
                    if (arr[LeftBorder + LeftBlockIterator].dArr[i] > arr[MidBorder + RightBlockIterator].dArr[i])
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].dArr[i];
                        LeftBlockIterator++;
                    }
                    else
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].dArr[i];
                        RightBlockIterator++;
                    }
                }
                while (LeftBorder + LeftBlockIterator < MidBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].dArr[i];
                    LeftBlockIterator++;
                }
                while (MidBorder + RightBlockIterator < RightBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].dArr[i];
                    RightBlockIterator++;
                }
                
                for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
                {
                    arr[LeftBorder + MergeIterator].dArr[i] = SortedBlock[MergeIterator];
                }
                delete SortedBlock;
                
            }
            
        }
    }
}

