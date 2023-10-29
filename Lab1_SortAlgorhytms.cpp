#include <iostream>
using namespace std;

const int N = 200;

void comps_and_swaps_out(int comps, int swaps)
{
    cout << "Сравнения: " << comps << endl;
    cout << "Перестановки: " << swaps << "\n\n";
}

// ---------------------------------------------------

void SelectionSort(int a[])
{
    int ind, arr[N], comps = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = a[i];

    for (int i = 0; i < N - 1; i++)
    {
        ind = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[ind])
                ind = j;
            comps++;
        }
        swap(arr[i], arr[ind]);
        swaps++;
    }

    comps_and_swaps_out(comps, swaps);
}

// ---------------------------------------------------

void BubbleSort(int a[])
{
    int arr[N], comps = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = a[i];

    for (int i = 0; i < N - 1; i++)
        for (int j = N - 1; j > i; j--) 
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                swaps++;
            }
            comps++;
        }

    comps_and_swaps_out(comps, swaps);
}

// ---------------------------------------------------

void InsertionSort(int a[])
{
    int buff, j, arr[N], comps = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = a[i];

    for (int i = 1; i < N; i++)
    {
        j = i;
        buff = arr[i];
        while (j > 0 && buff < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
            swaps++;
            comps++;
        }
        arr[j] = buff;
        swaps++;
    }

    comps_and_swaps_out(comps, swaps);
}

// ---------------------------------------------------

void BinaryInputSort(int a[])
{
    int left, right, m, x, arr[N], comps = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = a[i];

    for (int i = 1; i < N; i++)
    {
        x = arr[i];
        left = 0;
        right = i - 1;
        while (left <= right)
        {
            m = (left + right) / 2;
            (x < arr[m]) ? right = m - 1 : left = m + 1;
            comps++;
        }
        for (int j = i - 1; j >= left; j--)
        {
            arr[j + 1] = arr[j];
            swaps++;
        }
        arr[left] = x;
        swaps++;
    }

    comps_and_swaps_out(comps, swaps);
}

// ---------------------------------------------------

void ShakerSort(int a[])
{
    int left = 1, right = N - 1, k = N - 1, arr[N], comps = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = a[i];

    while (left <= right)
    {
        for (int j = right; j >= left; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
                swaps++;
            }
            comps++;
        }
        left = k + 1;
        for (int j = 1; j <= right; j++) 
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
                swaps++;
            }
            comps++;
        }
        right = k - 1;
        comps++;
    }

    comps_and_swaps_out(comps, swaps);
}

// ---------------------------------------------------

void ShellSort(int a[])
{
    int arr[N], comps = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = a[i];

    for (int gap = N / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; ++i) {
            int buff = arr[i], j;

            for (j = i; j >= gap && arr[j - gap] > buff; j -= gap)
            {
                arr[j] = arr[j - gap];
                swaps++;
            }
            comps++;
            arr[j] = buff;
            swaps++;
        }
    }

    comps_and_swaps_out(comps, swaps);
}

// ---------------------------------------------------

int Partition(int arr[], int low, int high, int& comps, int& swaps)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[j], arr[i]);
            i++;
            swaps++;
        }
        comps++;
    }

    swap(arr[i], arr[high]);
    swaps++;
    return i;
}

void QS(int arr[], int low, int high, int& comps, int& swaps)
{
    if (low >= high)
        return;

    QS(arr, low, Partition(arr, low, high, comps, swaps) - 1, comps, swaps);
    QS(arr, Partition(arr, low, high, comps, swaps) + 1, high, comps, swaps);
}

void QuickSort(int a[]) 
{
    int arr[N], comps = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = a[i];
    QS(arr, 0, N - 1, comps, swaps);

    comps_and_swaps_out(comps, swaps);
}

// ---------------------------------------------------

void Heapify(int arr[], int n, int i, int& comps, int& swaps) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    comps++;

    if (right < n && arr[right] > arr[largest])
        largest = right;
    comps++;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        swaps++;
        Heapify(arr, n, largest, comps, swaps);
    }
}

void HeapSort(int a[]) 
{
    int arr[N], comps = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = a[i];

    for (int i = N / 2 - 1; i >= 0; --i)
        Heapify(arr, N, i, comps, swaps);

    for (int i = N - 1; i >= 0; --i) 
    {
        swap(arr[0], arr[i]);
        swaps++;
        Heapify(arr, i, 0, comps, swaps);
    }

    comps_and_swaps_out(comps, swaps);
}

// ---------------------------------------------------

int main()
{
    setlocale(LC_ALL, "ru");
    int rand_arr[N], down_arr[N], up_arr[N];

    for (int i = 0; i < N; i++)
        rand_arr[i] = rand() % 200;

    for (int i = N - 1; i >= 0; i--)
        down_arr[i] = N - i;

    for (int i = 0; i < N; i++)
        up_arr[i] = i + 1;

    cout << "Сортировка простым выбором" << endl;
    cout << "Случайный массив:" << endl;
    SelectionSort(rand_arr);
    cout << "Убывающий массив:" << endl;
    SelectionSort(down_arr);
    cout << "Возрастающий массив:" << endl;
    SelectionSort(up_arr);

    cout << "------------------------------\nСортировка простым обменом" << endl;
    cout << "Случайный массив:" << endl;
    BubbleSort(rand_arr);
    cout << "Убывающий массив:" << endl;
    BubbleSort(down_arr);
    cout << "Возрастающий массив:" << endl;
    BubbleSort(up_arr);

    cout << "------------------------------\nСортировка простой вставки" << endl;
    cout << "Случайный массив:" << endl;
    InsertionSort(rand_arr);
    cout << "Убывающий массив:" << endl;
    InsertionSort(down_arr);
    cout << "Возрастающий массив:" << endl;
    InsertionSort(up_arr);

    cout << "------------------------------\nСортировка бинарной вставки" << endl;
    cout << "Случайный массив:" << endl;
    BinaryInputSort(rand_arr);
    cout << "Убывающий массив:" << endl;
    BinaryInputSort(down_arr);
    cout << "Возрастающий массив:" << endl;
    BinaryInputSort(up_arr);

    cout << "------------------------------\nШейкер-сортировка" << endl;
    cout << "Случайный массив:" << endl;
    ShakerSort(rand_arr);
    cout << "Убывающий массив:" << endl;
    ShakerSort(down_arr);
    cout << "Возрастающий массив:" << endl;
    ShakerSort(up_arr);

    cout << "------------------------------\nСортировка Шелла" << endl;
    cout << "Случайный массив:" << endl;
    ShellSort(rand_arr);
    cout << "Убывающий массив:" << endl;
    ShellSort(down_arr);
    cout << "Возрастающий массив:" << endl;
    ShellSort(up_arr);

    cout << "------------------------------\nБыстрая сортировка" << endl;
    cout << "Случайный массив:" << endl;
    QuickSort(rand_arr);
    cout << "Убывающий массив:" << endl;
    QuickSort(down_arr);
    cout << "Возрастающий массив:" << endl;
    QuickSort(up_arr);

    cout << "------------------------------\nСортировка куч" << endl;
    cout << "Случайный массив:" << endl;
    HeapSort(rand_arr);
    cout << "Убывающий массив:" << endl;
    HeapSort(down_arr);
    cout << "Возрастающий массив:" << endl;
    HeapSort(up_arr);
}