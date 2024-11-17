#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <random>

using namespace std;

void recordTestScores(string source, string destination);
bool isBalanced(int** A, int m, int n);
int** zeroArray(int m, int n);
int** randomArray(int m, int n, double lb, double ub);
void print(int** A, int m, int n);
int* columnSum(int** A, int m, int n);

int main(){
    
    int** A;
    int m = 3;
    int n = 2;
    
    A = randomArray(3, 2, -50, 50);
    print(A, 3, 2);
    cout << endl;
    isBalanced(A, 3, 2);
    cout << endl;
    columnSum(A, 3, 2);
    cout << endl;
    recordTestScores("input.txt", "output.txt");

    return 0;
}

void recordTestScores(string source, string destination) {
    class table // Value Definitions
    {
    public:
        void print();
        string name;
        double test1 = 0;
        double test2 = 0;
        double test3 = 0;
        double average = 0;
    };

    ifstream iFile; // I/O Objects
    ofstream oFile(destination);
    string line;
    table temp;
    vector <table> dV;


    iFile.open(source); // Opens file
    if (!iFile)
    {
        cout << "Error opening file ..." << endl;
        exit(1);
    }
    getline(iFile, line); // Writes First Line (Info Types)
    oFile << line << "\t" << "Average" << endl;

    while (true)
    {
        
        iFile >> temp.name >> temp.test1 >> temp.test2 >> temp.test3; // Getting Values from Source
        if (!iFile) // i.e., reading failed
            break; // Get out of the loop

        temp.average = (temp.test1 + temp.test2 + temp.test3) / 3; // Calculates Average

        dV.push_back(temp); //Insert temp into the vector

    }

    for (int k = 0; k < dV.size() - 1; k++) // Bubble Sorting Names Alphabetically
        for (int i = 0; i < dV.size() - 1 - k; i++)
            if (dV[i].name > dV[i + 1].name)
                swap(dV[i], dV[i + 1]);
    
    for (int i = 0; i < dV.size(); i++) {
        if (dV[i].name.size() < 5) {
            oFile << dV[i].name << "\t" << fixed << setprecision(0) << "     " << dV[i].test1 << "        " << dV[i].test2 
                << "        " << dV[i].test3 << "        " << fixed << setprecision(1) << dV[i].average << endl; 
            // Outputs code with correct spacing (adjustment for short names) to destination, also rounds averages to tenths place
        }
        else oFile << dV[i].name << "\t" << fixed << setprecision(0) << dV[i].test1 << "        " << dV[i].test2 << "        "
            << dV[i].test3 << "        " << fixed << setprecision(1) << dV[i].average << endl; // Normal output to destination
    }
    cout << "Scores Moved Successfully" << endl;
}

bool isBalanced(int** A, int m, int n)
{
    int pos = 0; // Testing Variables 
    int neg = 0;

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) { 
            if (A[row][col] > 0) { // Checks if each element of the 2D array is positive/negative (0s are not counted)
                pos++;
            }
            if (A[row][col] < 0) {
                neg++;
            }
        }
    }

    if (pos == neg) { // If the values are equal, then the amount of positive and negative occurances are equivalent
        cout << "Balanced" << endl;
        return true;
        
    }
    else cout << "Not Balanced" << endl; // Otherwise, occurances are not equivalent
    return false;
}

int* columnSum(int** A, int m, int n) {
    int B[20]; // Sets up an array for storage
    cout << "Sums of Columns: ";
    for (int col = 0; col < n; col++) { // Tests each column individually
        int total = 0;
        for (int row = 0; row < n+1; row++) { // Adds each cloumn's element to total
            total += A[row][col];
        }
        B[col] = total; // Stores column sum into array for output
        cout << B[col] << "\t";
    }
    cout << endl;
    return B;
}

int** zeroArray(int m, int n)
{
    int** A;
    A = new int* [m]; //allocate space for m pointers
    for (int row = 0; row < m; row++)
        A[row] = new int[n] {};//allocate space for each row and initialize to 0
    return A;
}

int** randomArray(int m, int n, double lb, double ub)
{
    int** A = zeroArray(m, n); //allocate memory and initialize the array to 0
    random_device rand_engine; // declare a random engine
    uniform_real_distribution<double> rand_real(lb, ub); //declare a variable of type random int, uniform between lb and ub

    for (int row = 0; row < m; row++)  //go through all the rows
        for (int col = 0; col < n; col++) //go through all the columns
            A[row][col] = rand_real(rand_engine);  //assign a random number to the element in (row, col) position
    return A;
}

void print(int** A, int m, int n)
{
    cout << fixed << setprecision(2); //two decimal digits displayed
    for (int row = 0; row < m; row++)  //go through all the rows
    {
        //print the row
        for (int col = 0; col < n; col++) //go through all the columns
            cout << setw(7) << A[row][col];  //print the element in (row, col) position
        cout << endl; //go to the new line to print the next row
    }
}