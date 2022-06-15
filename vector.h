#ifndef Vector_H
#define Vector_H
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
template <typename T>
struct Vector
{
private:
    T *data = nullptr;
    int capacity = 1;
    int counter = 0;

public:
    Vector();

    Vector(const Vector &);

    ~Vector();

    void push_back(T);

    void pop_back();
    void closest_smaller( vector<int> n);

    T front() const;

    T back() const;

    void clear();

    int size() const;

    Vector &operator=(const Vector &);

    bool operator==(const Vector &) const;

    T &operator[](int) const;
};

void closest_smaller( vector<int> n)
{

    // Vector<T>::Stack s;
    push_back("None, ");
    for (int i = 1; i < 10; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (n[i] > n[j])
            {
                push_back(n[j]);
                break;
            }
        }
    }
    for (int i = 1; i < elements; i++)
    {
        cout << s.mem[i];
    }
}

template <typename T>
Vector<T>::Vector()
{
    data = new T[capacity];
}
template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}
template <typename T>
void Vector<T>::push_back(T value)
{
    if (counter == capacity)
    {
        capacity *= 2;
        int *tmp = new T[capacity];
        for (int i = 0; i < counter; i++)
            tmp[i] = data[i];
        delete[] data;
        data = tmp;
    }
    data[counter] = value;
    counter++;
}
template <typename T>
void Vector<T>::pop_back()
{
    if (counter == 0)
        throw logic_error("Vector is empty");
    counter--;
}
template <typename T>
T Vector<T>::front() const
{
    if (counter == 0)
        throw logic_error("Vector is empty");
    return data[0];
}
template <typename T>
T Vector<T>::back() const
{
    if (counter == 0)
        throw logic_error("Vector is empty");
    return data[counter - 1];
}
template <typename T>
int Vector<T>::size() const
{
    return counter;
}
template <typename T>
T &Vector<T>::operator[](int index) const
{
    if (index < 0 || index >= counter)
        throw out_of_range("Out of vector range");
    return data[index];
}
#endif