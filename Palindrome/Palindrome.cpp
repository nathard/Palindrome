//
//  palindrome.cpp
//  Created by Nathan Harding on 11/08/11.
//


#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

//Prototype
bool Palindrome(const string &phrase);

int main()
{
    // Record input
	string temp;
    string pal;
    
	cout << "Enter a word or phrase to check for Palindrome: " << endl;
    getline(cin, temp);
    
    // Ignore any capitilisation, spacing and punctuation
    for(int i = 0; i < temp.length(); ++i) {
        temp[i] = tolower(temp[i]);
        
        if (isalpha(temp[i])) {
            pal += temp[i];
        }
    }
    
    // Check if string is a Palindrome
    if (Palindrome(pal)) {
        
        cout << "\n" << temp << " is a Palindrome\n";
        
    }
    else 
        cout << "\n" << temp << " is not a Palindrome\n";
    
	return 0;
}

// Function Description: Compare the characters of a string by reversing them with a stack
// Pre-conditions: Push string onto stack, pop chars off stack to build reverse string
// Post-conditions: Compare the 2 strings and return true if they match

bool Palindrome(const string &phrase)
{	
	stack<char> Stack;
    string revString;
	
	for (int i = 0; i < phrase.size(); ++i)
		Stack.push(phrase[i]); // Push characters onto stack
    
	while (!Stack.empty())
	{
		revString += Stack.top(); // Assign top element of stack to string
		Stack.pop(); // Remove top element of stack
	}
    
	return revString == phrase; // Compare the strings
}