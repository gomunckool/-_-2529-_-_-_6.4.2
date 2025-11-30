#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void FillArrayRec(double arr[], int n, int i = 0) {
    if (i == n) return;
    cout << "arr[" << i << "] = ";
    cin >> arr[i];
    FillArrayRec(arr, n, i + 1);
}

void PrintArrayRec(const double arr[], int n, int i = 0) {
    if (i == n) {
        cout << endl;
        return;
    }
    cout << setw(8) << arr[i];
    PrintArrayRec(arr, n, i + 1);
}

int FirstNegativeRec(const double arr[], int n, int i = 0) {
    if (i == n) return -1;
    if (arr[i] < 0) return i;
    return FirstNegativeRec(arr, n, i + 1);
}

int LastNegativeRec(const double arr[], int n, int i = 0, int last = -1) {
    if (i == n) return last;
    if (arr[i] < 0) last = i;
    return LastNegativeRec(arr, n, i + 1, last);
}

double SumOddIndexRec(const double arr[], int n, int i = 1) {
    if (i >= n) return 0;
    return arr[i] + SumOddIndexRec(arr, n, i + 2);
}

double SumBetweenNegRec(const double arr[], int n, int first, int last, int i = 0) {
    if (first == -1 || last == -1 || first == last) return 0;
    if (i == n) return 0;
    if (i <= first || i >= last) return SumBetweenNegRec(arr, n, first, last, i + 1);
    return arr[i] + SumBetweenNegRec(arr, n, first, last, i + 1);
}

void CompressArrayRec(double arr[], int n, int i = 0, int pos = 0) {
    if (i == n) {
        for (int k = pos; k < n; k++) arr[k] = 0;
        return;
    }
    if (fabs(arr[i]) > 1) {
        arr[pos] = arr[i];
        CompressArrayRec(arr, n, i + 1, pos + 1);
    } else {
        CompressArrayRec(arr, n, i + 1, pos);
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    double* arr = new double[n];

    FillArrayRec(arr, n);

    cout << "\nArray:\n";
    PrintArrayRec(arr, n);

    cout << "\nSum of elements with odd indexes: "
         << SumOddIndexRec(arr, n) << endl;

    int first = FirstNegativeRec(arr, n);
    int last  = LastNegativeRec(arr, n);

    cout << "Sum between first and last negative: "
         << SumBetweenNegRec(arr, n, first, last) << endl;

    CompressArrayRec(arr, n);

    cout << "\nCompressed array:\n";
    PrintArrayRec(arr, n);

    delete[] arr;
    return 0;
}
