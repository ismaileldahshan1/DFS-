/*
 Course: Fundamentals of Computing II
 Student Name: Ismail ElDahshan
 Student ID: 900221719
 Professor: Dr. Amr Goneid
 Section: 3
 */
#include <iostream>
#include <fstream>
#include "Stack.h"
#include "implementation.cpp"
using namespace std;
int getN() {
    string lineinfile;
    int N = 0;
    ifstream infile("Cities15.txt");//reading the txt file through infile
    if(infile.fail()) {
        cout << "Error"<< endl;
        return 0;
    }//validation that if the file fails to open then close the prgram and output error
   
    while (!infile.eof()) {
        getline(infile,lineinfile);//read the lines of the txt and put them in the string
        N++;// counter N that will get the size of the number of lines in the txt file
    }
    infile.close();// close the file after usage

    return N;// return the number of lines that will be the size of the array
}
void cities(int ** arr,int N) {
    ifstream infile("Cities15.txt");//reading the txt file through infile

    if(infile.fail()) {
        cout << "Error";
        return;
    }//validation that if the file fails to open then close the prgram and output error


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N;j++) {
            infile >> arr[i][j];
        }
    }//loop through the entire txt fileand reading each value in it and filling it in the 2d array
    infile.close();
    // close the file after usage
}

void DFS(int ** arr,int N,int k) {
    bool unseen=false , hold=true;
    int order = 0;//Set order = 0;
    int * v = new int[N];
    for(int i = 0; i < N; i++) {
        v[i] = unseen;
    }//Initialize V array to all unseen;
    Stackt<int> S;//Create an Empty stack S;
    S.push(k);//Push (k) on the stack (S);
    int sum = 0;
    cout<<"The current source i is  "<<endl;
    while(!S.stackIsEmpty()) {
        int i;
        S.pop(i);//Pop stack (S) to get current source (i);
        cout<< i <<endl;
        order++;//Increment (order)
        v[i] = order;//save it in V[i];
        for(int j = N-1; j >=0 ; j--) {
            //Scan row (i) in adjacency matrix from right to left (j = N downto 1)
            if(arr[i][j] != 0 && v[j] == unseen)  {
          // if (city (j) is connected to city (i)) and if (V[j] is unseen)
                sum = sum + arr[i][j];// sum to calculate the total distance transversed
                S.push(j);
                v[j] = hold;
                // Push (j) on (S) and Set V[j] to be hold
            }
        }
    }
    cout<<"The order is "<<endl;

    for(int i = 0; i < N ;i++) {
        cout <<  v[i] << endl;
    }

    cout << " Traversed distance is " << sum << endl;
}

int main() {
    int k=0;
    int N = getN();//initializing N to be the size of the array that we will get from the function getN
    int ** arr = new int*[N];
    for(int i = 0; i < N; i++) {
        arr[i] = new int[N];

        for(int j = 0; j < N;j++) {
            arr[i][j] = 0;
        }
    }// initializing a 2d dynamic array with 0s
    cities(arr,N);// calling the function that fills the 2d array with the values of the cities
    DFS(arr,N,k);// calling the dfs algorthim system that gets and outputs the tranversed distance

    for(int i = 0; i < N; i++)
    delete [] arr[i];
    delete []arr;
    //delete the array after usage
    return 0;
    
}
