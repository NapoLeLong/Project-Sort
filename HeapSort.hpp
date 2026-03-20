#include <iostream>
#include <vector>
#include <chrono>
#include <random>

void heapify(std::vector<int> &a, int n, int i, unsigned long long &compCount)
{
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n)
    {
        compCount++; 
        if (a[left] > a[largest])
        {
            largest = left;
        }
    }

    if (right < n)
    {
        compCount++; 
        if (a[right] > a[largest])
        {
            largest = right;
        }
    }
    if (largest != i)
    {
        std::swap(a[i], a[largest]);

        heapify(a, n, largest, compCount);
    }
}

void heapSort(std::vector<int> &a, unsigned long long &compCount)
{
    int n = a.size();
    compCount = 0;

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i, compCount);
    }

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(a[0], a[i]);
        heapify(a, i, 0, compCount);
    }
}

std::pair<long long, double> runHeapSort(std::vector<int> data)
{
    unsigned long long comparisons = 0;

    auto start = std::chrono::high_resolution_clock::now();

    heapSort(data, comparisons);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_ms = end - start;

    return { comparisons, duration_ms.count() };
}
