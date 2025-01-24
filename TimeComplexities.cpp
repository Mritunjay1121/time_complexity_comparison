#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void o_of_n() {
    auto start = high_resolution_clock::now();
    int count = 1e8;
    vector<int> numbers;
    for (int v = 1; v <= count; ++v) {
        numbers.push_back(v);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken to count " << count << " is: " << duration.count() / 1e6 << " seconds" << endl;
}

void o_of_n_squared() {
    int count = 10000;
    vector<int> numbers(count);
    for (int v = 1; v <= count; ++v) {
        numbers[v - 1] = v;
    }
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            int multiply = numbers[i] * numbers[j];
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken for an n_squared operation on " << count << " is: " << duration.count() / 1e6 << " seconds" << endl;
}

void o_of_n_logn() {
    int count_nlogn = 1e8;
    vector<int> numbers_nlogn(count_nlogn);
    for (int v = 1; v <= count_nlogn; ++v) {
        numbers_nlogn[v - 1] = v;
    }
    auto start = high_resolution_clock::now();
    sort(numbers_nlogn.begin(), numbers_nlogn.end());
    
    // Counting occurrences
    int current_count = 1;
    for (int i = 1; i < count_nlogn; ++i) {
        if (numbers_nlogn[i] == numbers_nlogn[i - 1]) {
            current_count++;
        } else {
            current_count = 1;
        }
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken for an n_logn operation on " << count_nlogn << " is: " << duration.count() / 1e6 << " seconds" << endl;
}

void o_of_logn() {
    int count_logn = 1e7;
    vector<int> numbers_logn(count_logn);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1e7);

    for (int i = 0; i < count_logn; ++i) {
        numbers_logn[i] = dis(gen);
    }
    sort(numbers_logn.begin(), numbers_logn.end());
    int search_for = numbers_logn[dis(gen) % count_logn];

    auto start = high_resolution_clock::now();
    int low = 0, high = count_logn - 1;
    bool found = false;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (numbers_logn[mid] == search_for) {
            found = true;
            break;
        }
        if (numbers_logn[mid] < search_for) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken for a logn operation on " << count_logn << " is: " << duration.count() / 1e6 << " seconds" << endl;
}

long long power(long long a, unsigned long long n) {
    long long result = 1;
    for (unsigned long long i = 0; i < n; ++i) {
        result *= a;
    }
    return result;
}

void a_to_n() {
    long long a = 2;  // Base
    unsigned long long n = 100000;  // Exponent

    auto start = high_resolution_clock::now();
    long long result = power(a, n);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken for a^n operation on a = " << a << " and n = "<< " n is : " << duration.count() / 1e6 << " seconds" << endl;
    
}
void n_factorial() {
    int n = 20;  // Example n, keep it small to avoid overflow
    auto start = high_resolution_clock::now();
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken for n-factorial operation on n = "<< n << " is : " << duration.count() / 1e6 << " seconds" << endl;

    
   
}


int main() {
    cout << "STARTING FOR CPP ................" << endl;
    o_of_n();
    o_of_n_squared();
    o_of_n_logn();
    o_of_logn();
    a_to_n();
    n_factorial();
    cout << "ENDING FOR CPP ................" << endl;
    return 0;
}