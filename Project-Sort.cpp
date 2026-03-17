#include <iostream>
#include <cstring>
#include <filesystem>
#include <string>
#include <stdexcept>
#include <vector>

int flag = 0;

#include "DataGenerator.hpp"
#include "SelectionSort.hpp"
#include "InsertionSort.hpp"
#include "BinaryInsertionSort.hpp"
#include "BubbleSort.hpp"
#include "ShakerSort.hpp"
#include "ShellSort.hpp"
#include "HeapSort.hpp"
#include "MergeSort.hpp"
//#include "QuickSort.hpp"
#include "CountingSort.hpp"
//#include "RadixSort.hpp"
#include "FlashSort.hpp"

using namespace std;

bool isInteger(const std::string& s) {
    try {
        std::size_t pos;
        std::stoi(s, &pos);
        return pos == s.length();
    }
    catch (const std::invalid_argument& e) {
        return false;
    }
    catch (const std::out_of_range& e) {
        return false;
    }
}

int main(int argc, char** argv)
{
    if (argc > 6) return 1;

    if (strcmp(argv[1], "-a") == 0)
    {
        string algo = argv[2];
        string input = argv[3];
        string order = "";
        string outParam = "";
        int range = 4;

        if (argc == 5)
        {
            outParam = argv[4];
        }
        else if (argc == 6)
        {
            range = 1;
            order = argv[4];
            outParam = argv[5];
        }

        if (outParam == "-time") flag = 1;
        if (outParam == "-comp") flag = 2;
        if (outParam == "-both") flag = 3;

        vector<vector<int>> arr(4);

        if (isInteger(input))
        {
            int n = stoi(input);
            for (int i = 0; i < 4; ++i)
            {
                arr[i].resize(n);
                GenerateData(arr[i].data(), n, i);
            }
        }
        else {
            arr.resize(1);
            vector<int>& a = arr[0];
            int n;
            range = 1;

            if (std::filesystem::exists(input))
            {
                fstream fs(input, ios::in);
                
                fs >> n;
                while (n--)
                {
                    int tmp;
                    fs >> tmp;
                    a.push_back(tmp);
                }
            }
            else {
                cout << "Invalid input file!\n";
                return 2;
            }
        }
        cout << "ALGORITHM MODE\nAlgorithm: ";
        string strorder[] = { "Randomize", "Sorted", "Reversed", "Nearly Sorted" };
        if (algo == "selection-sort") cout << "Selection Sort\n";
        if (algo == "insertion-sort") cout << "Insertion Sort\n";
        if (algo == "binary-insertion-sort") cout << "Binary Insertion Sort\n";
        if (algo == "bubble-sort") cout << "Bubble Sort\n";
        if (algo == "shaker-sort") cout << "Shaker Sort\n";
        if (algo == "shell-sort") cout << "Shell Sort\n";
        if (algo == "heap-sort") cout << "Heap Sort\n";
        if (algo == "merge-sort") cout << "Merge Sort\n";
        if (algo == "quick-sort") cout << "Quick Sort\n";
        if (algo == "counting-sort") cout << "Counting Sort\n";
        if (algo == "radix-sort") cout << "Radix Sort\n";
        if (algo == "flash-sort") cout << "Flash Sort\n";
        cout << "\n";
        for (int i = 0; i < range; ++i)
        {
            vector<int>& a = arr[i];
            int n = a.size();
            if (range != 1)
            {
                cout << "Input order: " << strorder[i] << "\n";
                cout << "-----------------------------------\n";
            }
            if (algo == "selection-sort") runSelectionSort(a);
            if (algo == "insertion-sort") InsertionSort(a.data(), n);
            if (algo == "binary-insertion-sort") binaryInsertionSort(a.data(), n);
            if (algo == "bubble-sort") BubbleSort(a.data(), n);
            if (algo == "shaker-sort") ShakerSort(a.data(), n);
            if (algo == "shell-sort") shellSort(a.data(), n);
            if (algo == "heap-sort") runHeapSort(a);
            if (algo == "merge-sort") mergeSort(a.data(), n);
            if (algo == "quick-sort") (a.data(), n);
            if (algo == "counting-sort") countingSort(a.data(), n);
            if (algo == "radix-sort") (a.data(), n);
            if (algo == "flash-sort") runFlashSort(a);
            cout << "\n";
        }
    }
    if (strcmp(argv[1], "-c") == 0)
    {

    }

    return 0;
}