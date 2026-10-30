#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector <int> vector1 {};
    vector <int> vector2 {};
    vector <vector<int>> vector_2d {}; 
    
    vector1.push_back(10);
    vector1.push_back(20);
    
    cout << "Vector1 Elements: " <<vector1.at(0) <<"," << vector1.at(1) << endl;
    cout << "Vector1 size: " <<vector1.size() << endl;
    vector2.push_back(100);
    vector2.push_back(200);
  
    cout << "\nVector2 Elements: " <<vector2.at(0) <<"," << vector2.at(1) << endl;
    cout << "Vector2 size: " <<vector2.size() << endl;
    
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    cout << "Elements: " << vector_2d.at(0).at(0) <<"," << vector_2d.at(0).at(1) <<","<< vector_2d.at(1).at(0) <<","<< vector_2d.at(1).at(1) << endl;
    
    vector1.at(0)=1000;
    cout << "Elements: " << vector_2d.at(0).at(0) <<","<< vector_2d.at(0).at(1) <<","<< vector_2d.at(1).at(0) << "," << vector_2d.at(1).at(1) << endl;
    cout << "Vector1 Elements: " <<vector1.at(0) << "," << vector1.at(1) << endl;
    
    return 0;
    
    }
    
    
    
    
    
    
    
    
    
    

    