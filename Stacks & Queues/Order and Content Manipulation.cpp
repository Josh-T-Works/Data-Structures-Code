#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void removeNonAlphaNum(stack<char>& s);

template <typename T>
void reverse(queue<T>& q);

bool balancedDelimiters(string s);

template <typename T>
void print(stack<T>);

template <typename T>
void print(queue<T> q);


int main() 
{

    stack<char> s1;
        char x = 'a';
        s1.push(x);
        x = 'b';
        s1.push(x);
        x = ')';
        s1.push(x);
        x = '3';
        s1.push(x);
        x = 'd';
        s1.push(x);
        x = '_';
        s1.push(x);
        x = ')';
        s1.push(x);
        x = '&';
        s1.push(x);
        x = 'd';
        s1.push(x);

        cout << "s1 : ";  print(s1); cout << endl;

        removeNonAlphaNum(s1);

        cout << "s1 : ";  print(s1); cout << endl << endl;


        queue<char> q1;
        x = 'd';
        q1.push(x);
        x = '8';
        q1.push(x);
        x = '&';
        q1.push(x);
        x = '4';
        q1.push(x);
        x = 'a';
        q1.push(x);
        x = 'b';
        q1.push(x);
        x = ')';
        q1.push(x);
        x = '9';
        q1.push(x);
        x = 'r';
        q1.push(x);

        cout << "q1 : "; print(q1); cout << endl;

        reverse(q1);

        cout << "q1 : "; print(q1); cout << endl << endl;

        string s = "(3.4 + 5)[(1.4(432 + 2))]32[]{(0_)    }";

        if (balancedDelimiters(s))
        {
            cout << "Balanced Delimiters? Yes!" << endl;
        }
        else cout << "Balanced Delimiters? No..." << endl;

	return 0;
}

template <typename T>
void print(stack<T> s)
{
    cout << "<->{";
    while (!s.empty()) //while elements are on top
    {
        cout << s.top() << ", ";
        s.pop(); //remove top element
    }
    cout << "}";
}

template <typename T>
void print(queue<T> q)
{
    cout << "<-{";
    while (!q.empty()) //while elements are in front
    {
        cout << q.front() << ", ";
        q.pop(); //remove front element
    }
    cout << "}<-";
}

void removeNonAlphaNum(stack<char>& s) 
{
    stack<char> temp;

    //copy over only the nonnegative elements of queue into temp
    while (!s.empty())
    {
        //insert the top element of s into temp if it is Alpha/Num
        if (isalpha(s.top()) || isdigit(s.top()))
            temp.push(s.top());
        //remove the front element of q so we can access the next element
        s.pop();
    }
    //at this point, s is empty
    
    //revert order of s
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }

}

template <typename T>
void reverse(queue<T>& q)
{
    stack<T> temp;

    //copy elements of queue into stack
    while (!q.empty())
    {
        temp.push(q.front());
        q.pop();
    }
    
    //reassign elements of queue from stack element order
    while (!temp.empty())
    {
        q.push(temp.top());
        temp.pop();
    }
}

bool balancedDelimiters(string s)
{
    stack<char> temp; //initializes stack & value to traverse the string
    int count = 0;

    while (s[count] != NULL) //traverses the string as an array until a nullptr shows up
    {
        if (s[count] == '(') //inserts opening deliminters into the stack when found
        {
            temp.push(s[count]); //inserts delimiter to the top of the stack
        }

        if (s[count] == '{')
        {
            temp.push(s[count]);
        }
        
        if (s[count] == '[')
        {
            temp.push(s[count]);
        }

        if (s[count] == ')') //tests to see if closing delimiters have appropriate conditions to be used. Inserts into the stack if so
        {
            if (temp.top() == '(') //if it matches the top delimiter in the stack
            {
                temp.pop(); //removes opening delimiter from stack
            }
            else return false; //if syntax is improper, delimiters are not balanced
        }

        if (s[count] == '}')
        {
            if (temp.top() == '{')
            {
                temp.pop();
            }
            else return false;
        }

        if (s[count] == ']')
        {
            if (temp.top() == '[')
            {
                temp.pop();
            }
            else return false;
        }
        count++; //raises value by one to test the next char in the string (loop ignores non-delimiters)
    }

    if (!temp.empty()) { //Tests if there are any unresolved open delimiters
        return false;
    }

    return true;
}