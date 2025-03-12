#include <time.h> 
#include  <math.h> 
#include  <chrono>
#include <vector>

using namespace std;

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

/****************************************************************************** 
*  Generate  a  vector  of  random  integers  in  a  given  range.  The  ends * 
*  of  this  range  are  inclusive. * 
*  size  -  int  -  the  number  of  integers  in  the  resulting  vector * 
*  low,  high  - int  - the  range  from  which  to draw  random  integers  (inclusive) * 
*  return  -  vector<int>  -  a  vector  of  random  integers * 
******************************************************************************/ 
vector<int>  randomVector(int  size,  int  low,  int  high){ 
    vector<int>  v(size,  0); 
    for  (int  i =  0;  i <  size;  i++){ 
    v[i]  =  rand()  %  (high  -  low  +1)  +  low; 
    } 
    return v;
}

/****************************************************************** 
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
    
    return true;
}

/******************************************************************
 * fixed vector length algorithm testing
 * creates 10 random vectors of length 100
 * runs each sorting algorithm on each of the vectors
 * collects the run times for each and verfies whether the vectors are sorted
 * prints the min, mean, standard dev., and max run time
******************************************************************/
void multiAlgoFixedVectorSort() {

}

/******************************************************************
 * varying length vector algorithm testing
 * worst, average, and best-case run time testing
 * rec. sizes are 10, 100, 1000, 5000, 10000
 * he says different "types" of vectors, but I'm not sure what he means by that
 * ok, I'm assuming that by "types" he means how sorted each is already
 * For each vector size, there should be 50 generated
******************************************************************/
void multiAlgoMultiVectorSort() {

}


int main() {

}