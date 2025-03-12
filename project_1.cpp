#include <time.h> 
#include <math.h> 
#include <chrono>
#include <vector>
#include <iostream>
#include <algorithm> // for swap

using namespace std;

template <typename T>
vector<T> bubbleSort(std::vector<T> v) {
    bool sorted = false;
    size_t n = v.size();
    // note for myself:
    // Using size_t because negative values aren't necessary here
    while (!sorted) {
        sorted = true;
        for (size_t i = 0; i < n - 1; ++i) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                sorted = false;
            }
        }
        --n;
    }
    return v
}

/****************************************************************************** 
 * sorts a vector using insertion sort algorithm
******************************************************************************/ 
vector<int> insertionSort(vector<int> v) {
    int i = 1;
    while (i < v.size()) {
        int j = i;
        while (j > 0 && v[j] < v[j-1]) {
            int temp = v[j-1];
            v[j-1] = v[j];
            v[j] = temp;
            j = j-1;
            i = i+1;
        }
    }
    return v;
}

/****************************************************************************** 
 * sorts a vector using selection sort algorithm
******************************************************************************/ 
vector<int> selectionSort(vector<int> v) {
    for (int i = 0; i <= v.size() - 2; i++) {
        int uMin = i;
        for (int j = i+1; j <= v.size() - 1; i++) {
            if (v[j] < v[uMin]) {
                uMin = j;
            }
        }
        int temp = v[i];
        v[i] = v[uMin];
        v[uMin] = temp;
    }
    return v;
}

/****************************************************************************** 
 * sorts a vector using quick sort algorithm
 * the pseudocode has one paramter. not sure if
 * I should use more and use in place partitioning
 * https://chatgpt.com/c/67c21ce7-16c0-800a-ac2a-2c53d5df4686
******************************************************************************/ 
vector<int> quickSort(vector<int> v) {
    if (v.size() <= 1) {
        return v;
    }
    int pivot = v[0];
    vector<int> A, B;
    for (int e = 1; e <= v.size() - 1; e++) {
    // for e in rest(v)
    // not sure if the for loop is correctly
    // this is correctly implemented I think
        if (v[e] <= pivot) {
            A.push_back(v[e]);
            // moves lower than pivot to A
        }
        else {
            B.push_back(v[e]);
            // moves higher than pivot to B
        }
    }
    vector<int> sortedA = quickSort(A);
    vector<int> sortedB = quickSort(B);
    // sorts A and B

    sortedA.push_back(pivot);
    sortedA.insert(sortedA.end(), sortedB.begin(), sortedB.end());
    // adds the pivot to A and then adds B to A
    // leaves as A as the final vector to be returned

    return sortedA;
}

/******************************************************************************
 * Generate  a  vector  of  random  integers  in  a  given  range.  The  ends
 * of  this  range  are  inclusive.
 * size  -  int  -  the  number  of  integers  in  the  resulting  vector
 * low,  high  - int  - the  range  from  which  to draw  random  integers  (inclusive)
 * return  -  vector<int>  -  a  vector  of  random  integers
******************************************************************************/ 
vector<int>  randomVector(const int  size,  int  low,  int  high){ 
    vector<int>  v(size, 0);
    
    for  (int  i =  0; i < size;  i++){ 
        v[i] = rand() % (high - low + 1) + low; 
    }

    return v;
}

/******************************************************************
 * creates a sorted vector
******************************************************************/
vector<int> sortedVector(const int  size) {
    vector<int>  v(size,  0);
    
    for  (int  i =  0; i < size;  i++) { 
        v[i]  =  i + 1;
        // makes the index number and it's value equal
    }

    return v;
}

/******************************************************************
 * creates a reversely sorted vector
******************************************************************/
vector<int> reverseVector(const int  size) {
    vector<int>  v(size,  0);

    for  (int  i = 0; i < size;  i++) {
        v[i]  =  size - i;
        // puts the value of the size of the vector at 
        // the first index and goes down from there as
        // the index position increases
    }

    return v;
}

//****************************************************************************************
// ChatGPT's BS for the lower two functions: https://chatgpt.com/share/67c7733d-51cc-800a-8424-41e646e837a3
// ok, so apparently a high and low input is fine for the function. So I will defintely need
// to work on this.
/**
 * This is a helper function to allow for just size to be input into the
 * function below. I don't think these are correct yet. I need to put more
 * time into figuring this out. I just wanted something roughly here.
 */
void fillIdealQuickVector(vector<int>& v, int start, int end, int& current) {
    if (start > end) return; // base case
    int mid = (start + end) / 2;
    v[mid] = current++;
    fillIdealQuickVector(v, start, mid - 1, current);
    // left subarray
    fillIdealQuickVector(v, mid + 1, end, current);
    // right subarray
}

/******************************************************************
 * creates a vector that have the median value of the vector
 * at the beginning of the vector and each subvector as the vector
 * gets divided. I don't think that this implementation works.
 * The vector ChatGPT says it produces isn't what I'm finding it
 * produces in my head. the initial current value just is too high.
******************************************************************/
vector<int> bestCaseQuickVector(int size) {
    vector<int> v(size);
    int current = 1;
    fillIdealQuickVector(v, 0, size - 1, current);
    return v;
}
//****************************************************************************************

/******************************************************************
 * Creates a worst case vector for the selection sort algorithm
 * needs to create a vector like: {2,4,6,8,9,7,5,3,1}
 * ascending even numbers followed by descending odd numbers
 * my idea is to fill it with evens by added 2 each time and
 * then once the value hits the value of the size of the array
 * to have it determine if the array value is even or odd,
 * then subtract one if it is or continue if it isn't and start subtracting 2 from it
 * until the array is filled
******************************************************************/
vector<int> worstCaseSelectionVector(const int  size,  int  low,  int  high) {
    vector<int> v(size);
    int mid = size / 2;
    int value = low;

    // fills the first half of the vector with ascending values
    for (int i = 0; i <= mid; i++) {
        v[i] = value;
        value += (high-low) / size;
    }

    // fills the second half of the vector with descending values
    for (int i = mid + 1; i < size; i++) {
        value -= (high - low) / size;
        v[i] = value;
    }

    return v;
}

/****************************************************************** 
 * THIS MIGHT NEED TO BE CHANGED
*  Calculate  the  sample  standard  deviation  of  a  vector  of  doubles  * 
*  v  - const  vector<double>  - a  vector  of  doubles * 
*  return  - double  - the  sample  standard  deviation  of  v * 
******************************************************************/ 
double sampleSD(const vector<double> v){ 
    double  mean  =  0; 
    for  (int  i =  0;  i <  v.size();  i++){ 
    mean += v[i]; 
    } 
    mean  =  mean  /  v.size(); 
    double sd = 0; 
    for  (int  i =  0;  i <  v.size();  i++){ 
    sd  +=  (v[i]-mean)*(v[i]-mean); 
    } 
    sd = sd / (v.size()-1); 
    return  sqrt(sd);
}

/******************************************************************
 * Checks whether the vector is sorted or not
 * returns true or false
******************************************************************/
bool vectorSortCheck(const vector<int> v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] <= v[i+1]) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;

    // this is just a note for me
    // 0 1 | 1 2 | 2 3
    // for vector size 4 it goes through 3 comparisons
}

/* Possible function timing solution
chrono::high_resolution_clock::time_point start; 
chrono::high_resolution_clock::time_point  end; 
cout  <<  "Sieve  of  Erathosthenes  on  primes  below  100,000"  <<  endl; 
start  =  chrono::high_resolution_clock::now(); 
int  sum   =   sieveOfErathosthenes(100000); 
end    =    chrono::high_resolution_clock::now(); 
double elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count(); 
cout  <<  "Sum:  "  <<  sum  <<  ";  Elapsed  time:  "  <<  elapsed  <<  endl; 
*/

/******************************************************************
 * fixed random value vector length algorithm testing
 * creates 10 random vectors of length 100
 * runs each sorting algorithm on each of the vectors
 * collects the run times for each and verfies whether the vectors are sorted
 * prints the min, mean, standard dev., and max run time
******************************************************************/
void multiAlgoRandomFixedVectorSort() {
    chrono::high_resolution_clock::time_point start; // shared
    chrono::high_resolution_clock::time_point  end; // shared
    double elapsed; // shared
    vector<double> bubbleTimes;
    vector<double> insertTimes;
    vector<double> selectTimes;
    vector<double> quickTimes;
    double mean; // shared
    double standardD; // shared
    
    cout << "Sorting Algorithm on 10, 100 Length Vectors" << endl;
    for (int i = 0; i < 10; i++) {
        vector<int> v = randomVector(100, 0, 100); // shared
        vector<int> sortedV; // shared

        start  =  chrono::high_resolution_clock::now();
        sortedV = bubbleSort(v);
        end = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        bubbleTimes[i] = elapsed;
        if (vectorSortCheck(sortedV)) {
            cout << "Current Bubble sort succeeded" << endl;
        }
        else {
            cout << "The current Bubble sort failed" << endl;
            return;
        }
        
        start  =  chrono::high_resolution_clock::now();
        sortedV = insertionSort(v);
        end = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        insertTimes[i] = elapsed;
        if (vectorSortCheck(sortedV)) {
            cout << "Current Insertion sort succeeded" << endl;
        }
        else {
            cout << "The current Insertion sort failed" << endl;
            return;
        }

        start  =  chrono::high_resolution_clock::now();
        sortedV = selectionSort(v);
        end = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        selectTimes[i] = elapsed;
        if (vectorSortCheck(sortedV)) {
            cout << "Current Selection sort succeeded" << endl;
        }
        else {
            cout << "The current Selection sort failed" << endl;
            return;
        }

        start  =  chrono::high_resolution_clock::now();
        sortedV = quickSort(v);
        end = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        quickTimes[i] = elapsed;
        if (vectorSortCheck(sortedV)) {
            cout << "Current Quick sort succeeded" << endl;
        }
        else {
            cout << "The current Quick sort failed" << endl;
            return;
        }
    }

    // processing the time data and outputting
    bubbleTimes = bubbleSort(bubbleTimes);
    mean  =  0;
    for (int i = 0;  i < 10; i++){
        mean += bubbleTimes[i];
    }
    mean = mean / 10; 
    standardD = sampleSD(bubbleTimes);

    cout << "Bubble sort on 10 vectors of length 100" << endl;
    cout << "All sorting was successful for Bubble sort" << endl;
    cout << "Minimum: " << bubbleTimes[0] << " sec; Mean:" << mean << "sec; Standard Deviation: "
    << standardD << " sec; Maximum: " << bubbleTimes[9] << " sec" << endl;

    insertTimes = bubbleSort(insertTimes);
    mean  =  0;
    for (int i = 0;  i < 10; i++){
        mean += insertTimes[i];
    }
    mean = mean / 10;
    standardD = sampleSD(insertTimes);

    cout << "Insertion sort on 10 vectors of length 100" << endl;
    cout << "All sorting was successful for Insertion sort" << endl;
    cout << "Minimum: " << insertTimes[0] << " sec; Mean:" << mean << "sec; Standard Deviation: "
    << standardD << " sec; Maximum: " << insertTimes[9] << " sec" << endl;

    selectTimes = bubbleSort(selectTimes);
    mean  =  0;
    for (int i = 0;  i < 10; i++){
        mean += selectTimes[i];
    }
    mean = mean / 10; 
    standardD = sampleSD(selectTimes);

    cout << "Selection sort on 10 vectors of length 100" << endl;
    cout << "All sorting was successful for Selection sort" << endl;
    cout << "Minimum: " << selectTimes[0] << " sec; Mean:" << mean << "sec; Standard Deviation: "
    << standardD << " sec; Maximum: " << selectTimes[9] << " sec" << endl;

    quickTimes = bubbleSort(quickTimes);
    mean  =  0;
    for (int i = 0;  i < 10; i++){
        mean += quickTimes[i];
    }
    mean = mean / 10; 
    standardD = sampleSD(quickTimes);

    cout << "Quick sort on 10 vectors of length 100" << endl;
    cout << "All sorting was successful for Quick sort" << endl;
    cout << "Minimum: " << quickTimes[0] << " sec; Mean:" << mean << "sec; Standard Deviation: "
    << standardD << " sec; Maximum: " << quickTimes[9] << " sec" << endl;
}

/******************************************************************
 * varying length vector algorithm testing
 * worst, average, and best-case run time testing
 * rec. sizes are 10, 100, 1000, 5000, 10000
 * vector types
    * The average vector type is always random for each algorithm
    * bubble: 
        * best|sorted 
        * worst|reversely
    * insertion: 
        * best|sorted 
        * worst|reversely
    * selection: 
        * best|sorted 
        * worst|"special" ex. [2, 4, 5, 3, 1]
    * quick: 
        * best|"when pivot equally cuts the array ~equally" 
        * worst|"when one subarray is size one and the other is n-1 (has all the other values)"
 * For each vector size and each type, there should be 50 generated vectors
 * 250 random
 * 250 sorted
 * 250 reversely sorted
 * 250 best quick
 * 250 worst selection
******************************************************************/
void multiAlgoMultiSizeTypeVectorSort() {
    // I think I might want to split this into a couple more function
    // a worst, average, and best one??
    vector<size_t> vector_sizes = {10, 100, 1000, 5000, 10000};
    vector<int> v1, v2, v3, v4, v5;
    size_t i = 0; // shared

    // random: provides average for all the sorting methods
    
    while (i < 50) {
        v1 = randomVector(vector_sizes[0], 0, vector_sizes[0]);
        v2 = randomVector(vector_sizes[1], 0, vector_sizes[1]);
        v3 = randomVector(vector_sizes[2], 0, vector_sizes[2]);
        v4 = randomVector(vector_sizes[3], 0, vector_sizes[3]);
        v5 = randomVector(vector_sizes[4], 0, vector_sizes[4]);

        i++;
    }
    i = 0;
    // sorted: provides best case for insertion, selection, and bubble sort
    while (i < 50) {
        v1 = sortedVector(vector_sizes[0]);
        v2 = sortedVector(vector_sizes[1]);
        v3 = sortedVector(vector_sizes[2]);
        v4 = sortedVector(vector_sizes[3]);
        v5 = sortedVector(vector_sizes[4]);

        i++;
    }
    i = 0;
    // reversely sorted: provides worst case for insertion and bubble sort
    while (i < 50) { 
        v1 = reverseVector(vector_sizes[0]);
        v2 = reverseVector(vector_sizes[1]);
        v3 = reverseVector(vector_sizes[2]);
        v4 = reverseVector(vector_sizes[3]);
        v5 = reverseVector(vector_sizes[4]);

        i++;
    }
    i = 0;

    // quicksort's special: provides the best case for quick sort
    while (i < 50) {
        v1 = bestCaseQuickVector(vector_sizes[0]);
        v2 = bestCaseQuickVector(vector_sizes[1]);
        v3 = bestCaseQuickVector(vector_sizes[2]);
        v4 = bestCaseQuickVector(vector_sizes[3]);
        v5 = bestCaseQuickVector(vector_sizes[4]);

        i++;
    }
    i = 0;

    // selection's special: provides the worst case for selection sort
    while (i < 50) { 
        v1 = worstCaseSelectionVector(vector_sizes[0], 0, vector_sizes[0]);
        v2 = worstCaseSelectionVector(vector_sizes[1], 0, vector_sizes[1]);
        v3 = worstCaseSelectionVector(vector_sizes[2], 0, vector_sizes[2]);
        v4 = worstCaseSelectionVector(vector_sizes[3], 0, vector_sizes[3]);
        v5 = worstCaseSelectionVector(vector_sizes[4], 0, vector_sizes[4]);

        i++;
    }
    i = 0;
}

/**
 * Each of the types of vectors should be called 250 times in total
 * With each vector length having 50 vectors each
 */
int main() {
    srand(time(NULL));
    
    multiAlgoMultiSizeTypeVectorSort();

}