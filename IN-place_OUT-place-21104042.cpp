/*  Q1. Difference between IN-PLACE and OUT-PLACE sorting algorithm
ANS- IN-PLACE
     1. In place algorithm may require a small amount of extra memory for its operation.however ,the amount of memory required must not be dependent on input size and should be constant 
     2. In-place algorithms are usually used in an embedded system that runs in limited memory.they reduce the space requirements to a great extent , the algorithm time complexity increases in some cases
     3. for example  bubble sort , heap sort, insertion sort ,quick sort ,selection sort

     OUT-PLACE
     1.An algorithm that not in -place is called out -place . unlike an in-place algorithm,the extra space used by out-of-place algorithm depends on the input size
     2.The merging can be done in-place , but it increases the time complexity of the sorting routine, the standard merge sort algorithm is an example of out of place algorithm as it requires o(n) extra space for merging
     3. for example  radix sort and merge sort
*/

/* Q2. Implement Insertion sort in both (in-place and out-place) manner.*/

#include <iostream>
using namespace std;
void insertion_sort(int arr[],int n){
    int i=0,j=i+1;
    while(j<=n-1){
        int temp=arr[j];
        while(i>=0){
            if(arr[i]>temp){
                arr[i+1]=arr[i];
                i--;
            }
            if(i==-1){arr[0]=temp;break;}
            if(arr[i]<=temp){arr[i+1]=temp;break;}
        }
        j++;
        i=j-1;
    }
    return;
}
    //start=starting index
    //end=  ending index
void insertion_sort(int arr[],int start,int end){
    
    if(start==end){return;}
    int j=start+1;
    int temp=arr[j];
    while(start>=0){
        if(arr[start]>temp){
            arr[start+1]=arr[start];
            start--;
        }
        if(start==-1){arr[0]=temp;break;}
        if(arr[start]<=temp){arr[start+1]=temp;break;}
    }
    insertion_sort(arr,start+1,end);
}

void fun(int arr[],int n){
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
}
int main(){
    int n;
    
    cout<<"Enter the number of elements in array: ";
    cin>>n;
    int arr[n],arr2[n];
    cout<<"Enter elements of array seperated by space: ";
    for(int i=0;i<n;i++){cin>>arr[i];}
    
    for(int i=0;i<n;i++){arr2[i]=arr[i];}
    cout<<endl;
    
    insertion_sort(arr,n);
    cout<<endl;
    cout<<"Array after sorting using in-place algorithm : ";
    
    fun(arr,n);
    cout<<endl;
    
    insertion_sort(arr2,0,n-1);
    cout<<"Array after sorting using out-place algorithm : ";
    
    fun(arr,n);
    cout<<endl;

}

//  Q3.Suggest some practical examples of using in-place and out-place techniques.
/*  ANS 3. For IN-PLACE:
    1.For exapmle if we want to reverse an array then its in-place algorithm will be swaping the first and last element of array until we reach the 
    middle of array
    2.In many cases, the space requirements of an algorithm can be drastically cut by using a randomized algorithm.
    3. For example, say we wish to know if two vertices in a graph of n vertices are in the same connected component of the graph. There is no known simple, deterministic, in-place algorithm to determine this, but if we simply start at one vertex and perform a random walk of about 20n3 steps, the chance that we will stumble across the other vertex provided that it is in the same component is very high 

    For Out-PLACE:
    1.If we want to solve the same problem using out-place algorithm we have to create one extra array of same size and copy elements of original array from back to the front of new array,this 
    algorithm increases the space complexity to O(n) as we have creaed an extra array.
    2.merge sort is an example of out of place.
    3.we assume a person sing in a choir and when there’s free time I sort of pathologically sort the music. The choir members are assigned numbers so as to keep track of our personal performance “notes”, reminderts of the conductor’s nuances. I sort the music for a while, but soon it becomes a nuisance to hold the stack of books or thumb through to the right spot into which I then have to slip in the new entry. Thus I start a new stack, 
  and then…you guessed it. I merge sort the three or four piles into one group.  */


     