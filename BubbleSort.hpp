#include <iostream>
#include <chrono>
#include <vector>

std::pair<long long, double> BubbleSort(int a[], int n)
{
    int compare = 0;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            compare++;

            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    return { compare, duration.count() };
}