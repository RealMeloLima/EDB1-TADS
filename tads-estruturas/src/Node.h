#ifndef __Sequence__Node__
#define __Sequence__Node__

template <typename T>
class Node
{
private:
    T value;
    Node* next;
    
public:
    Node();
    
    Node( T );
    
    Node( T, Node* );
    
    T getValue();
    
    void setValue(T val);
    
    Node* getNext();
    
    void setNext(Node*);
    
};

template<typename T>
Node<T>::Node(void):
next(NULL) {}

template<typename T>
Node<T>::Node(T val):
value(val), next(NULL) {}

template<typename T>
Node<T>::Node(T val, Node* n):
value(val), next(n) {}

template<typename T>
T Node<T>::getValue(void)
{
    return this->value;
}

template<typename T>
void Node<T>::setValue(T t)
{
    this->value = t;
}

template<typename T>
Node<T>* Node<T>::getNext(void)
{
    return this->next;
}

template<typename T>
void Node<T>::setNext(Node<T>* n)
{
    this->next = n;
}
#endif /* defined(__Sequence__Node__) */
