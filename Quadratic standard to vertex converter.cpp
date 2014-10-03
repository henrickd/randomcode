#include <iostream> //preprocessor instruction to load input/output commands
#include <conio.h> //preprocessor instruction to load command getchar
using namespace std; //set standard namespace for input/output

int main () //main function
{
    double a, b, c, h, k; //declaration of variables a, b, c, h, k as double floating point numbers
    int s2v_v2s; //value to decide conversion (standard to vertex or vertex to standard)
    cout << "This program converts quadratic equations from standard form (forme generale)\nto vertex form (forme canonique) and vice versa.\n\n"; //instructions
    start: //start of program for loop
    cout << "Press 1 to convert from standard to vertex for or 2 for vertex to standard form."; //instructions
    cin >> s2v_v2s; //input for deciding which conversion standard
    
    if (s2v_v2s == 1) //operations to perform if user selects conversion from standard to vertex form
    {
         cout << "\na: "; //request input for a
         cin >> a; //input for a
         cout << "\nb: "; //request input for b
         cin >> b; //input for b
         cout << "\nc: "; //request input for c
         cin >> c; //input for c
         
         h = -b/(2*a); //formula to find h using a, b
         k = (4*a*c-(b*b))/(4*a); //formula to find k using a, b, c
         
         if (h == 0 && k == 0)
              cout << "\nThe equation in vertex form is: " << a << "x^2"; //to make output look better
               
         else if (h == 0 && k > 0)
              cout << "\nThe equation in vertex form is: " << a << "x^2+" << k; //to make output look better
              
         else if  (h == 0 && k < 0)
              cout << "\nThe equation in vertex form is: " << a << "x^2" << k; //to make output look better
         
         else if (h > 0 && k == 0)
              cout << "\nThe equation in vertex form is: " << a << "(x-" << h << ")^2"; //to make output look better
              
         else if (h > 0 && k > 0)
              cout << "\nThe equation in vertex form is: " << a << "(x-" << h << ")^2+" << k; //to make output look better
              
         else if (h > 0 && k < 0)
              cout << "\nThe equation in vertex form is: " << a << "(x-" << h << ")^2" << k; //to make output look better
         
         else if (h < 0 && k == 0)
              cout << "\nThe equation in vertex form is: " << a << "(x+" << -h << ")^2"; //to make output look better
         
         else if (h < 0 && k > 0)
              cout << "\nThe equation in vertex form is: " << a << "(x+" << -h << ")^2+" << k; //to make output look better
              
         else if (h < 0 && k < 0)
              cout << "\nThe equation in vertex form is: " << a << "(x+" << -h << ")^2" << k; //to make output look better
              
         else
              cout << "\nInvalid quadratic function."; //if there's calculation error somewhere due to invalid parameters
             
    }
    
    else if (s2v_v2s == 2) //operations to perform if user selects conversion from vertex to standard form
    {
         cout << "\na: "; //request input for a
         cin >> a; //input for a
         cout << "\nh: "; //request input for h
         cin >> h; //input for b
         cout << "\nk: "; //request input for k
         cin >> k; //input for c
         
         b = -2*a*h; //formula to find b using a, h
         c = a*(h*h)+k; //formula to find c using a, h, k 
         
         if (b == 0 && c == 0)
                cout << "\nThe equation in standard form is: " << a << "x^2"; //to make output look better
            
          else if (b == 0 && c > 0)
                cout << "\nThe equation in standard form is: " << a << "x^2+" << c; //to make output look better
          
          else if (b == 0 && c < 0)
                cout << "\nThe equation in standard form is: " << a << "x^2" << c; //to make output look better
          
          else if (b > 0 && c == 0)
                cout << "\nThe equation in standard form is: " << a << "x^2+" << b << "x"; //to make output look better
                
          else if (b > 0 && c > 0)
                cout << "\nThe equation in standard form is: " << a << "x^2+" << b << "x+" << c; //to make output look better
                
          else if (b > 0 && c < 0)
                cout << "\nThe equation in standard form is: " << a << "x^2+" << b << "x" << c; //to make output look better
          
          else if (b < 0 && c == 0)
                cout << "\nThe equation in standard form is: " << a << "x^2" << b << "x"; //to make output look better
                
          else if (b < 0 && c > 0)
                cout << "\nThe equation in standard form is: " << a << "x^2" << b << "x+" << c; //to make output look better
                
          else if (b < 0 && c < 0)
                cout << "\nThe equation in standard form is: " << a << "x^2" << b << "x" << c; //to make output look better
                
          else
                cout << "\nInvalid quadratic function."; //if there's calculation error somewhere due to invalid parameters
    }
    
    else
        cout << "\nInvalid value entered, exiting program."; //if user is a troll and inputs something other than 1 or 2 for conversion choice
        
    cout << "\n\n"; //double space to make program look better
    cout << "To convert another equation, press Enter.\nTo exit, press Esc.\n"; //instructions
    
    char restartorexit; //declaration of value to capture character (Enter or Esc)
    restartorexit = getch(); //capturing character
    if (restartorexit == 13) //if character is Enter
    {
                      cout << "________________________________________________________________________________\n"; //separator line
                      goto start; //go back to start of program
                      }
    else if (restartorexit == 27) //if character is Esc
         exit(1); //exit program
}
    
    
