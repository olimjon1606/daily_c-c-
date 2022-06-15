#include <iomanip>
#include <string>
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cstdlib> // allows us to use the standard exceptions defined by C++
#include <cmath>

using namespace std;

class Stack
{
    int capacity;
    int *mem;

    int elements;

public:
    Stack() : capacity(10),
              mem(new int[capacity]),
              elements(0)
    {
    }

    void push(int x)
    {
        if (capacity == elements)
        {
            int *tmp = new int[capacity * 2];

            for (int i = 0; i < capacity; i++)
            {
                tmp[i] = mem[i];
            }

            delete[] mem;
            mem = tmp;
            capacity *= 2;
        }
        mem[elements] = x;
        elements++;
    }

    int top()
    {
        if (elements == 0)
        {
            throw std::runtime_error("top() called on an empty stack");
        }

        return mem[elements - 1];
    }

    void pop()
    {
        if (elements == 0)
        {
            throw std::runtime_error("pop() called on an empty stack");
        }

        elements--;
    }

    ~Stack()
    {
        delete[] mem;
    }
};

int evaluate(string str)
{
    Stack stack;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        if (isdigit(str[i]))
        {
            stack.push(str[i] - '0');
        }
        else
        {
            int result;
            if (str[i] == '+')
            {
                int n1 = stack.top();
                stack.pop();
                int n2 = stack.top();
                stack.pop();

                result = n1 + n2;
            }
            if (str[i] == '-')
            {
                int n1 = stack.top();
                stack.pop();
                int n2 = stack.top();
                stack.pop();

                result = n1 - n2;
            }
            if (str[i] == '*')
            {
                int n1 = stack.top();
                stack.pop();
                int n2 = stack.top();
                stack.pop();

                result = n1 * n2;
            }
            if (str[i] == 's')
            {
                int n1 = stack.top();
                stack.pop();

                result = sqrt(n1);
            }
            if (str[i] == 'e')
            {
                int n1 = stack.top();
                stack.pop();
                int n2 = stack.top();
                stack.pop();

                result = pow(n2, n1);
            }

            stack.push(result);
        }
    }
    return stack.top();
}

int main()
{

    std::cout << evaluate("5 5 +") << std::endl;
    std::cout << evaluate("5 4 *") << std::endl;
    std::cout << evaluate("5 2 3 + *") << std::endl;
    std::cout << evaluate("5 2 + 3 *") << std::endl;
    std::cout << evaluate("1 2 3 4 + + +") << std::endl;
    std::cout << evaluate("1 2 + 3 + 4 +") << std::endl;
    std::cout << evaluate("8 2 e") << std::endl;
    std::cout << evaluate("8 2 * s") << std::endl;
    std::cout << evaluate("7 8 + s") << std::endl;
    return 0;
}