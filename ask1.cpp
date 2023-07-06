//This program takes a sum of numbers and the mode of calculation.
//it prints the calculations needed to calculate the result  


//#include "std_lib_facilities.h"

#include <iostream>
#include<vector>
//#include <cmath> // Include the <cmath> header for math functions
using namespace std; // Add the std namespace



// error() simply disguises throws:
inline void error(const string& s)
{
    throw runtime_error(s);
}


//reads the vector
vector<double> read_vector(){
    int n, i;
    double temp;
    vector<double> num;
    cout << "How many items do you want to calculate?\n>";
    try{        //check if mode is valid
        cin >> n;
        if (n < 0 || cin.fail()) throw(n);

    }catch(int n){
        cerr << "Invalid input (negative number or char)\nyou gave " << n;
        error("Invalid input (negative number or char)");
    }

    for (i = 0; i < n; i++){ //for every item read the num
        cout << "Plese give the item number " << i + 1 << "\n>";
        try{          //check the num
            cin >> temp;
            if (cin.fail()) throw temp;
            num.push_back(temp);
        }catch(char temp){
            cerr << "Invalid input you gave " << temp; 
        }
    }
    return num;   //return the vector
}


//reads the mode
short int read_mode(){
    short int mode;
    cout << "Finaly select a mode\n1 for addition\n2 for multiptlication\n3 for subtraction\n>";
    try{// check if the mode is valid
        cin >> mode;
        if ( !(mode >= 1 && mode <= 3) || cin.fail() ) throw mode;
    }catch(short int mode){
        cerr << "invalid impute (incorect mode or char) you gave " << mode;
        error("invalid impute (incorect mode or char)");
    }
    return mode; //return the mode
}



//takes a mode and a a vextor of doubles and prints the calulations needed using recartion
void rec_calc(short int mode, vector<double> num){
    double res;
    int size = num.size();
    if (num.capacity() == 0){ //if 0 num were given
        string ans;
        cout << "\nCan not calculate with no numbers\nDo you want to try again? [yes, no]\n>"; //see if he wants to try again
        while ( ( !(cin >> ans) || ( (ans != "yes") && (ans != "no"))) ){
            cin.ignore();
            cout << "invalid input\ninput must be yes or no. Try again\n>";
        }
        if (ans == "no"){  // if not abort
            cerr << "ABORD BY USER\n";
            exit(0);
        }
        cout << "\nThe number will be accepted if it's greater than zero\n\n\n"; //if yes read agoin by calling the function untill not 0 items
        while (num.capacity() == 0){
            num = read_vector();
        }
        size = num.size();   //take the size of the new vector
    }
    
    if ( num.size() == 1 ) return; //return case

    //accorting to the mode calulate the next result
    if ( mode == 1){ res = num[size - 1] + num[size - 2];  cout << num[size - 1] << " + " << num[size - 2] << " = " << res << endl; }
    if ( mode == 2){ res = num[size - 1] * num[size - 2];  cout << num[size - 1] << " * " << num[size - 2] << " = " << res << endl; }
    if ( mode == 3){ res = num[size - 1] - num[size - 2];  cout << num[size - 1] << " - " << num[size - 2] << " = " << res << endl; }

    //we want to calculate bewin the last two numbers of the vector so we delete the privius two and adding the res as the last
    num.pop_back();
    num.pop_back();
    num.push_back(res);
    
    rec_calc(mode, num);  // call the function again to make it recersive
}   


//main cals the function to calulate using two other functions to read the values
int main(){
    rec_calc( read_mode(), read_vector() ); //cals the functions

    //system("pause");
    return 0;
}
