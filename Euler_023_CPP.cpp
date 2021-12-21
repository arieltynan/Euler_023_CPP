// Euler_023_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n = 28123; //upperbound 28123

    //Create list of abundant numbers
    vector<int> v;
    for (int i = 1; i < n + 1; i++)
    {
        int factSum = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0) //if j is a factor of i
                factSum = factSum + j; //add j to total sum of factors
        }
        if (factSum > i) //number is abundant if sum of factors is greater than the number "i"
        {
            v.push_back(i);
            //cout << i << endl; //testing abundant numbers
        }
    } //end for loop
    
    //Create a full vector to remove abundant num sums from
    vector<int> full(n);
    iota(begin(full), end(full), 1);

    for (int i = 0; i < v.size(); i++) //iterate through vector of abundant numbers
    {
        for (int j = 0; j < i + 1; j++)
        {
            if(v[i] + v[j] < n + 1) //if two abundant numbers are less than the threshold
                full[v[i] + v[j] - 1] = 0; //set the index in vector full that matches the sum equal to 0
        }
    }

    //for (int i = 0; i < full.size(); i++)
      //  cout << full[i] << endl;
    int sum = accumulate(full.begin(), full.end(), 0); //sum remaining values
    cout << sum << endl;
}

