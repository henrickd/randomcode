#include <iostream> //preprocessor instruction to load input/output commands
#include <cmath> //preprocessor instruction to load algebraic and trigonometric functions
#include <conio.h> //preprocessor instruction to load command getchar
#define pi 3.14159265  //preprocessor instruction to define "pi" as the numerical value of pi
using namespace std; //set standard namespace for input/output

int main () //main function
{
    int nofvectors; //declaration of variable containing number of vectors
    cout << "This program adds bidimensional vectors and outputs the resulting vector's size and orientation."; //instructions
    start: //start of program for loop
    cout << "\n\nEnter the number of vectors you want to add together: "; //instructions
    cin >> nofvectors; //input of number of vectors
    double inputvectors[nofvectors]; //declaration of array containing sizes of vectors
    double inputvectoro_deg[nofvectors]; //declaration of array containing orientation of vectors (in degrees)
    double inputvectoro_rad[nofvectors]; //declaration of array containing orientation of vectors (in radians)
    
    for (int vectorn = 0; vectorn < nofvectors; vectorn++) //loop demanding size and orientation of the amount of vectors selected by user
    {
        cout << "\n\nEnter size of vector " << vectorn+1 << ": "; //instructions
        cin >> inputvectors[vectorn]; //input of vector sizes
        cout << "\nEnter orientation of vector " << vectorn+1 << ": "; //instructions
        cin >> inputvectoro_deg[vectorn]; //input of vector orientations in degrees
        inputvectoro_rad[vectorn] = (pi/180)*inputvectoro_deg[vectorn]; //conversion of vector orientations from degrees to radians
        }
        
    double xofvectors[nofvectors]; //declaration of array containing x-values of vectors
    double xofvectors_cosop[nofvectors]; //declaration of array containing x-values of vectors if vector size was 1
    for (int vectorxn = 0; vectorxn < nofvectors; vectorxn++) //loop calculating x-value for each vector
    {
        xofvectors_cosop[vectorxn]=cos(inputvectoro_rad[vectorxn]); //calculation of the cosine of the vectors
        xofvectors[vectorxn]=xofvectors_cosop[vectorxn]*inputvectors[vectorxn]; //calculation of the x-value of the vectors
        }
    
    double yofvectors[nofvectors]; //declaration of array containing y-values of vectors
    double yofvectors_sinop[nofvectors]; //declaration of array containing y-values of vectors if vector size was 1
    for (int vectoryn = 0; vectoryn < nofvectors; vectoryn++) //loop calculating y-value for each vector
    {
        yofvectors_sinop[vectoryn]=sin(inputvectoro_rad[vectoryn]); //calculation of the sine of the vectors
        yofvectors[vectoryn]=yofvectors_sinop[vectoryn]*inputvectors[vectoryn]; //calculation of the y-value of the vectors
        }
        
    double resultofx; //declaration of the variable containing the sum of all x-values of vectors
    for (int sumofx = 0; sumofx < nofvectors; sumofx++) //loop calculating the sum of all x-values of vectors
    {
        resultofx += xofvectors[sumofx]; //adding each vector's x-value to get the sum of all x-values
        }
    
    double resultofy; //declaration of the variable containing the sum of all y-values of vectors
    for (int sumofy = 0; sumofy < nofvectors; sumofy++) //loop calculating the sum of all y-values of vectors
    {
        resultofy += yofvectors[sumofy]; //adding each vector's y-value to get the sum of all y-values
        }
        
    double sizeofvector_sq = pow(resultofx,2) + pow(resultofy,2); //pythagorean theorem to calculate resulting vector's size (sum of squares of catheti)
    double sizeofvector = sqrt(sizeofvector_sq); //pythagorean theorem to calculate resulting vector's size (square root of sum of squares of catheti)
    double orientationofvector; //declaration of variable containing orientation of resulting vector
    double orientationofvector_deg; //convert value to degrees
    
    if (resultofx==0 && resultofy>0) //atan2 cannot compute result if x=0
       orientationofvector_deg = 90; //if vector points north, its orientation is 90
    else if (resultofx==0 && resultofy==0) //atan2 cannot compute result if x=0
         orientationofvector_deg = 0; //if vector doesn't exist, its orientation is 0
    else if (resultofx==0 && resultofy<0) //atan2 cannot compute result if x=0
         orientationofvector_deg = 270; //if vector points south, its orientation is 270
    else
    {
        orientationofvector = atan2 (resultofy,resultofx); //calculation of orientation using arc tangent (in radians)
        orientationofvector_deg = (180/pi)*orientationofvector; //conversion to degrees
        }
    cout << "\n\nThe size of the resulting vector is " << sizeofvector << ".";
    if (orientationofvector_deg  >= 0) //checks if degree value is negative
        cout <<"\nIts orientation is " << orientationofvector_deg << " degrees.\n"; //if not, standard output of size and orientation
       
    else if (orientationofvector_deg < 0) //checks if degree value is negative
       cout <<"\nIts orientation is " << orientationofvector_deg+360 << " degrees.\n"; //if so, add 360 to degree to make it positive
       
    cout << "Its x-component is " << resultofx << " and its y-component is " << resultofy << ".\n\n"; //output of x-component and y-component
    cout << "To perform another vector addition, press Enter.\nTo exit, press Esc.\n"; //instructions
    
    char restartorexit; //declaration of value to capture character (Enter or Esc)
    restartorexit = getch(); //capturing character
    if (restartorexit == 13) //if character is Enter
    {
                      cout << "________________________________________________________________________________"; //separator line
                      goto start; //go back to start of program
                      }
    else if (restartorexit == 27) //if character is Esc
         exit(1); //exit program
}
    
    
