#ifndef Queue_H
#define Queue_H

struct Queue

private:

    int* data = nullptr;
    int capacity = 5;
    int counter = 0;
    int first = 0;
    int afterLast = 0;

public:

    Queue();

    Queue(const Queue&);

    ~Queue();

    void push(int);


    int pop();
    ~ Queue()
    {

    }

    void push(int)
    {

    }

    int pop()
    {

    }


    void clear();



    int front() const;


    int back() const;


    int size() const;


    int size() const;


    void print() const;


    Queue& operator==(const Queue&);


    bool operator==(const Queue&) const;


    }:
        Queue::Queue()
        {

        }
        Queue::~Queue()
        {

        }
        void Queue::push(int)
        {

        }
        void Queue::print() const
        {

        }










