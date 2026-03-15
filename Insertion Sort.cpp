#include <iostream>
#include <chrono>
#include <vector>

void InsertionSort(int a[], int n)
{
    int compare = 0;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0)
        {
            compare++;

            if (a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }
            else
                break;
        }

        a[j + 1] = key;
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::milliseconds duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Running Time (if required): " << duration << " ms\n";
    std::cout << "Comparisons (if required): " << compare << "\n";
}

int main()
{
    return 0;
}