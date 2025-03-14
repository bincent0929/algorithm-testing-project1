#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx; // Mutex for synchronizing file writes

// Sorting algorithms
vector<int> bubbleSort(vector<int> v) {
    size_t n = v.size();
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (size_t i = 0; i < n - 1; ++i) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                sorted = false;
            }
        }
        n--;
    }
    return v;
}

vector<int> insertionSort(vector<int> v) {
    for (size_t i = 1; i < v.size(); i++) {
        int key = v[i];
        size_t j = i;
        while (j > 0 && v[j - 1] > key) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = key;
    }
    return v;
}

vector<int> selectionSort(vector<int> v) {
    for (size_t i = 0; i < v.size() - 1; i++) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < v.size(); j++) {
            if (v[j] < v[minIdx]) minIdx = j;
        }
        swap(v[i], v[minIdx]);
    }
    return v;
}

vector<int> quickSort(vector<int> v) {
    if (v.size() <= 1) return v;
    int pivot = v[0];
    vector<int> left, right;
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < pivot) left.push_back(v[i]);
        else right.push_back(v[i]);
    }
    left = quickSort(left);
    right = quickSort(right);
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

// Generates a random vector
vector<int> randomVector(int size, int low, int high) {
    vector<int> v(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(low, high);
    for (int &val : v) val = dis(gen);
    return v;
}

// Measures sorting time and logs results
void benchmarkSort(const string &sortName, vector<int> v, vector<int> (*sortFunc)(vector<int>), ofstream &file) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(v);
    auto end = chrono::high_resolution_clock::now();
    double elapsed = chrono::duration<double>(end - start).count();
    lock_guard<mutex> lock(mtx);
    file << sortName << "," << v.size() << "," << elapsed << "\n";
    cout << sortName << " sorted vector of size " << v.size() << " in " << elapsed << " sec\n";
}

// Runs multi-threaded sorting tests
void multiThreadedSorting(int vectorSize, ofstream &bubbleFile, ofstream &insertionFile, ofstream &selectionFile, ofstream &quickFile) {
    vector<int> v = randomVector(vectorSize, 0, 10000);
    thread t1(benchmarkSort, "bubble", v, bubbleSort, ref(bubbleFile));
    thread t2(benchmarkSort, "insertion", v, insertionSort, ref(insertionFile));
    thread t3(benchmarkSort, "selection", v, selectionSort, ref(selectionFile));
    thread t4(benchmarkSort, "quick", v, quickSort, ref(quickFile));
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

int main() {
    srand(time(NULL));
    ofstream bubbleFile("bubble_times.csv");
    ofstream insertionFile("insertion_times.csv");
    ofstream selectionFile("selection_times.csv");
    ofstream quickFile("quick_times.csv");
    
    bubbleFile << "Algorithm,Size,Time\n";
    insertionFile << "Algorithm,Size,Time\n";
    selectionFile << "Algorithm,Size,Time\n";
    quickFile << "Algorithm,Size,Time\n";
    
    vector<int> sizes = {100, 1000, 5000, 10000};
    for (int size : sizes) {
        cout << "\nSorting vectors of size " << size << "...\n";
        multiThreadedSorting(size, bubbleFile, insertionFile, selectionFile, quickFile);
    }
    
    bubbleFile.close();
    insertionFile.close();
    selectionFile.close();
    quickFile.close();
    
    cout << "\nSorting complete. Results saved to individual sorting files.\n";
    return 0;
}
