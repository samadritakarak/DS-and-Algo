# Stacks

### Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).

![Stacks](https://miro.medium.com/max/1088/1*5kJdbFLjHufBfHlI5b84PA.png)

### The functions associated with stack are:

empty() – Returns whether the stack is empty – Time Complexity : O(1)  
size() – Returns the size of the stack – Time Complexity : O(1)  
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)  
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)  
pop() – Deletes the top most element of the stack – Time Complexity : O(1)

```
// CPP program to demonstrate working of STL stack
#include <bits/stdc++.h>
using namespace std;

void showstack(stack <int> s)
{
	while (!s.empty())
	{
		cout << '\t' << s.top();
		s.pop();
	}
	cout << '\n';
}

int main ()
{
	stack <int> s;
	s.push(10);
	s.push(30);
	s.push(20);
	s.push(5);
	s.push(1);

	cout << "The stack is : ";
	showstack(s);

	cout << "\ns.size() : " << s.size();
	cout << "\ns.top() : " << s.top();


	cout << "\ns.pop() : ";
	s.pop();
	showstack(s);

	return 0;
}
```

#### Output:

```
The stack is :     1    5    20    30    10

s.size() : 5
s.top() : 1
s.pop() :     5    20    30    10
```

### Standard Problems based on Stack :

1. [Infix to Postfix Conversion using Stack](https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/)
2. [Prefix to Infix Conversion](https://www.geeksforgeeks.org/prefix-infix-conversion/)
3. [Prefix to Postfix Conversion](https://www.geeksforgeeks.org/prefix-postfix-conversion/)
4. [Postfix to Prefix Conversion](https://www.geeksforgeeks.org/postfix-prefix-conversion/)
5. [Postfix to Infix](https://www.geeksforgeeks.org/postfix-to-infix/)
6. [Convert Infix To Prefix Notation](https://www.geeksforgeeks.org/convert-infix-prefix-notation/)
7. [The Stock Span Problem](https://www.geeksforgeeks.org/the-stock-span-problem/)
8. [Check for balanced parentheses in an expression](https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/)
9. [Next Greater Element](https://www.geeksforgeeks.org/next-greater-element/)
10. [Next Greater Frequency Element](https://www.geeksforgeeks.org/next-greater-frequency-element/)
