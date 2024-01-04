#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:

    LinkedList() : head(nullptr) {}

    LinkedList(const LinkedList& other) {
      
    }


    ~LinkedList() {

    }

    LinkedList& operator=(const LinkedList& other) {

        return *this;
    }

 
    bool operator==(const LinkedList& other) const {
        
        return false; 
    }

    template <typename U>
    friend ostream& operator<<(ostream& os, const LinkedList<T>& list);

 
    template <typename U>
    friend istream& operator>>(istream& is, LinkedList<U>& list);

    void insert(const T& value) {
        
    }

    
    void remove(const T& value) {

    }
};


template <typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& list) {
 
    return os;
}


template <typename T>
istream& operator>>(istream& is, LinkedList<T>& list) {
   
    return is;
}

int main() {
    
    LinkedList<int> myList;
    myList.insert(1);
    myList.insert(2);
    myList.insert(3);

 cout << "Lista initiala: " << myList << endl;

    myList.remove(2);

   cout << "Lista dupa stergere: " << myList << endl;

    return 0;
}
