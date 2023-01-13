/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h1_p2
*/

#include<iostream>
#include "stack.h"

using namespace std;

int main(int argc, char** argv)
{
	Stack<int> intstack;  			// stack with the default size
	Stack<float> floatstack(30);        // stack with specified size
	
	int i;
    int out;
    float j=2.35;

    //pushing values to stack
	for (i = 0; i < 12; i++)
	{
        if(intstack.push(i))
        {
            cout<< "Push Success" << endl;
        }
        else
        {
            cout << "Push failed" << endl;
        }
    }

	for (i = 0; i < 12; i++)
    {
        if(intstack.pop(out))
		    cout << out << endl;    //printing popped element
    }

    for(i=0; i<10; i++)
    {
        floatstack.push(j++);
    }

    cout << floatstack.back() << endl;
    return 0;
}