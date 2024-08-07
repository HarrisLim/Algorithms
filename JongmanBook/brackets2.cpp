#include <iostream>
#include <stack>

using namespace std;

// test case
int c=3;

bool solveBrackets(string& str)
{
    stack<char> st;
    bool ret;
    for(int i=0; i+1<str.size(); i++)
    {
        st.push(str[i]);
        if( st.top() == '(' && str[i+1] == ')' ||
            st.top() == '{' && str[i+1] == '}' ||
            st.top() == '[' && str[i+1] == ']' ) 
            ret=true;
        else ret=false;
    }
    return ret;
}

bool wellMatched(const string& formula)
{
    const string opening("({["), closing(")}]");
    
    stack<char> openStack;
    for(int i=0; i<formula.size(); i++)
    {
        if(opening.find(formula[i]) != -1)
        {
            openStack.push(formula[i]);
        }
        else
        {
            if(openStack.empty())
                return false;
            if(opening.find(openStack.top()) != closing.find(formula[i]))
                return false;
            openStack.pop();
        }
    }
    return openStack.empty();
}

int main()
{
    string str = "()()";
    cout << "ret_1: " << solveBrackets(str);
    cout << "ret_2: " << solveBrackets(str);
    return 0;
}