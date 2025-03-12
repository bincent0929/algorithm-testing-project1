#include <time.h> 
#include <math.h> 
#include <chrono>
#include <vector>
#include <iostream>

using namespace std;

/*
* I need to change these. Apparently we do want to not change the vectors
* we want to reuse them instead of generate new ones
*/

/****************************************************************************** 
 * sorts a vector using bubble sort algorithm
******************************************************************************/ 
vector<int> bubbleSort(vector<int> v) {
    bool sorted = false;
    while (sorted == false) {
        sorted = true;
        for (int i = 1; i <= v.size()-1; i++) {
            if (v[i-1] > v[i]) {
                int temp = v[i-1];
                v[i-1] = v[i];
                v[i] = temp;
                sorted = false;
            }
        }
    }
    return v;
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
vector<int>  randomVector(int  size,  int  low,  int  high){ 
    vector<int>  v(size,  0);
    
    for  (int  i =  0; i < size;  i++){ 
        v[i]  =  rand()  %  (high  -  low  +1)  +  low; 
    }

    return v;
}

/******************************************************************
 * creates a sorted vector
******************************************************************/
vector<int> sortedVector(int  size) {
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
vector<int> reverseVector(int  size) {
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
vector<int> worstCaseSelectionVector(int  size,  int  low,  int  high) {
    vector<int>  v(size,  0);

    for (int i = 0; i < v.size(); i++) {
        
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
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point  end;
    
    cout << "Bubble Sort on 10, 100 Length Vectors" << endl;
    for (int i = 10; i <= 0; i--) {
        int min = 0;
        int max = 0;
        start  =  chrono::high_resolution_clock::now();
        vector<int> v = randomVector(100, 0, 100);
        bubbleSort(v);
        end = chrono::high_resolution_clock::now();
        double bubbleElapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        if (min == 0 && max == 0) {
            min = bubbleElapsed;
            max = bubbleElapsed;
        }
        else {
            if (min > bubbleElapsed) {
                min = bubbleElapsed;
            }
            else if (max < bubbleElapsed) {
                max = bubbleElapsed;
            }
        }
    }
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
******************************************************************/
void multiAlgoMultiSizeTypeVectorSort() {

}

/**
 * Each of the types of vectors should be called 250 times in total
 * With each vector length having 50 vectors each
 */
int main() {
    srand(time(NULL));
    
    for (int i = 0; i < 250; i++) {
        for (int j = 0; j < 5; j++) {
            
        }
    }

}