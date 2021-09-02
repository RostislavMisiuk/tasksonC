#include <iostream>
using namespace std;
template <typename T>
class List
{
private:
    class node
    {
    public:
        T data;

        node* next;
    public:
        node(node* _next)
            :next(_next)
        {}
    };

private:
    class node* head, * tail;

public:
    void push_front(const T& val)
    {
        if (empty())
        {
            head = new node(tail);
            head->data = val;
        }
        else
        {
            head = new node(head);
            head->data = val;
        }
    }

public:
    void push_back(const T& val)
    {
        if (empty())
        {
            head = new node(tail);
            head->data = val;
        }
        else
        {
            node* srh_node = head;
            for (; srh_node->next != tail; srh_node = srh_node->next)
                ;


            srh_node->next = new node(tail);
            srh_node->next->data = val;
        }
    }

public:
    T pop_front()
    {
        T val = head->data;
        node* to_del = head;
        head = head->next;

        delete to_del;
        return val;
    }

public:
    T pop_back()
    {
        node* srh_node = head;

        if (srh_node->next == tail)
        {
            head = tail;
            T val = srh_node->data;
            delete srh_node;

            return val;
        }
        else
        {
            for (; (srh_node->next->next != tail); srh_node = srh_node->next)
                ;

            T val = srh_node->next->data;
            node* to_del = srh_node->next;
            srh_node->next = srh_node->next->next;
            delete to_del;

            return val;
        }
    }

public:
    bool empty() const
    {
        return head == tail;
    }

public:
    virtual void clear()
    {
        node* dl_node;
        for (node* cr_node = head; cr_node != tail;)
        {
            dl_node = cr_node;
            cr_node = cr_node->next;

            delete dl_node;
        }

        head = tail;
    }

public:
    List()
    {
        head = tail = new node(0);
    }

public:
    List(const List& l)
    {
        clear();
        node* cur_node = head;

        for (node* srh_node = l.head;
            srh_node != l.tail; srh_node = shr_node->next)
        {
            cur_node->next = new node(tail);
            cur_node->data = srh_node->data;
        }

    }

public:
    virtual ~List()
    {
        clear();
    }
};

template <typename Ty>
class Queue : protected List<Ty>
{
public:
    Queue()
        :List()
    {}

public:
    Queue(const Queue& rhs)
        :List(rhs)
    {}

public:
    ~Queue()
    {}

public:
    inline void push(const Ty& value)
    {
        List<Ty>::push_back(value);
    }

public:
    inline Ty pop()
    {
        return List<Ty>::pop_front();
    }
};

template <typename Ty>
class Stack : protected List<Ty>
{
public:
    Stack()
        :List()
    {}

public:
    Stack(const Stack& rhs)
        :List(rhs)
    {}

public:
    ~Stack()
    {}

public:
    inline void push(const Ty& value)
    {
        List<Ty>::push_front(value);
    }

public:
    inline Ty pop()
    {
        return List<Ty>::pop_front();
    }
};

int main()
{
    Queue<int> qi;
    qi.push(1);    qi.push(2);    qi.push(3);

    cout << qi.pop() << endl;
    cout << qi.pop() << endl;
    cout << qi.pop() << endl;

    Stack<int> si;
    si.push(1);    si.push(2);    si.push(3);

    cout << si.pop() << endl;
    cout << si.pop() << endl;
    cout << si.pop() << endl;
    system("pause");
}