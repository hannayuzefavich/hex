#include <iostream>
#include "ListCustomString.h"
using namespace std;

bool CustomGetline(ListCustomString& line)
{
    char c;
    CustomString part;
    int i = 0;
    int k = 0;
    int dash_counter = 0;
    bool half_done = false;
    do {
        cin.get(c);
    } while (c == ' ');
    do {
        if (c == '-') {
            dash_counter++;
        }
        else
        {
            if (c == '<' and dash_counter == 0)
            {
                half_done = true;
            }
            if (dash_counter != 3)
            {
                dash_counter = 0;
            }
           
        }
        if (c == '\n')
        {
            if (line.getSize() > 0 and dash_counter == 3)
            {
                return true;
            }
            
            i = 0;
            if (half_done)
            {
                i += k;
                k++;
            }
            else
            {
                CustomString tmp;
                line.addElement(tmp);
            }
        }
        if (c == '<')
        {
            cin.get(c);
            cin.get(c);               
            line.getByIndex(i).addCharacter(c);  
            i++;
        }
             
    } while (cin.get(c));
   
    return line.getSize();
}


int main() {

    ListCustomString l;
    if (CustomGetline(l)) {
        l.print();
    }
    

	return 0;
}
