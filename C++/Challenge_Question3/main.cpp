/*
 Playing With Vectors
  */
  




#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector <int> vector_1 {};
    vector <int> vector_2 {};
    vector <vector<int>> vector_2D {};
    
    
    vector_1.push_back(10);
    vector_1.push_back(20);
    cout << "\nVector 1 elements: " <<vector_1.at(0) << "," << vector_1.at(1) << endl;
    cout << "Size of Vector 1: " << vector_1.size() ;
    vector_2.push_back(100);
    vector_2.push_back(200);
    cout << "\nVector 2 elements: " << vector_2.at(0) << "," << vector_2.at(1) << endl;
    cout << "Size of Vector 2: " <<vector_2.size();
    
    
    cout << "\n2D Vector";
    vector_2D.push_back(vector_1);
    vector_2D.push_back(vector_2);
    
    cout << " " << vector_2D.at(0).at(0) << " " << vector_2D.at(0).at(1) << endl;
    cout << vector_2D.at(1).at(0) << " " << vector_2D.at(1).at(1) << endl;
    
    
    cout << "\nUpdated Vector:  " << endl;
    vector_1.at(0) = 1000;
    vector_2D.push_back(vector_1);
    vector_2D.push_back(vector_2);
    
    cout << " " << vector_2D.at(0).at(0) << " " << vector_2D.at(0).at(1) << endl;
    cout << vector_2D.at(1).at(0) << " " << vector_2D.at(1).at(1) << endl;
    
    cout <<"\n Updated Vector 1: " << endl;
    cout << vector_1.at(0) << endl << vector_1.at(1)<< endl;
    
    
    
    
    return 0;
    
    
    

    
    
    
    
    
}