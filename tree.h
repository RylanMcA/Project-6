#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Address{
public:
    Address();
    Address(float lat, float lon, string num, string street);
    ~Address();
    void setLat(float lat);
    void setLon(float lon);
    void setHouseNum(string num);
    void setStreetName(string street);
    float getLat();
    float getLon();
    string getHouseNum();
    string getStreetName();
    void print();
    
private:
    float latitude, longitude;
    string houseNumber, streetName;
};

// Data node definition
class Node{
public:
    Address place; 
    Node *Left;
    Node *Right;
};

class BinaryTree{
public:
    // Constructor functions
    BinaryTree();
   ~BinaryTree();

    // General binary tree operations
    bool Search(Address &loc);
    bool Insert(Address loc);
    bool Delete(Address loc);
    int count();
    int height();
    void Print();

private:
    // Helper functions
    bool SearchHelper(Address &loc, Node* Tree);
    bool InsertHelper(Address loc, Node* &Tree);
    bool DeleteNode(Node* &Tree);
    bool DeleteHelper(Address loc, Node* &Tree);
    int CountHelper(Node* Tree);\
    int HeightHelper(Node* Tree);
    void PrintHelper(Node* Tree);
   
    // Tree pointer
    Node *Root;
};
