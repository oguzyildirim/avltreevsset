using namespace std; 
#include <iostream>
#include <string>
#include <fstream>
#include <chrono> 
#include <bits/stdc++.h> 
#include <set>
using namespace std::chrono; 

int main() 
{ 
    
    set<string> s; 

    string line;
    ifstream myfile ("names2.txt");
    
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            s.insert(line.c_str());
        }
        myfile.close();
    }
    
    const bool is_in = s.find("Ali") != s.end();

    if (is_in == 1) 
        {
            std::cout << "found";
        }



    using namespace std::chrono;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

        s.find("Ali");
        

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;
    
} 