//IMPLEMENTATION OF THE ADDRESS CLASS
#include "tree.h"

Address::Address(){}

Address::Address(float lat, float lon, string num, string street){
    latitude = lat;
    longitude = lon;
    houseNumber = num;
    streetName = street;
}

Address::~Address(){}

//SET FUNCTIONS
void Address::setLat(float lat){
    latitude = lat;
}

void Address::setLon(float lon){
    longitude = lon;
}

void Address::setHouseNum(string num){
    houseNumber = num;
}

void Address::setStreetName(string street){
    streetName = street;
}

//GET FUNCTIONS
float Address::getLat(){
    return latitude;
}

float Address::getLon(){
    return longitude;
}

string Address::getHouseNum(){
    return houseNumber;
}

string Address::getStreetName(){
    return streetName;
}

void Address::print(){
    cout <<  latitude << ", " << longitude << ", " << houseNumber << ", " << streetName << endl;
}


//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//  Extender:   Rylan McAlister
//-----------------------------------------------------------
BinaryTree::BinaryTree(){
    Root = NULL;
}

BinaryTree::~BinaryTree(){}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(Address &loc, Node * Tree){
    // Data value not found 
    if (Tree == NULL)
        return false;

    // Data value found 
    else if (Tree->place.getStreetName()+Tree->place.getHouseNum() == loc.getStreetName()+loc.getHouseNum()){
        loc = Tree->place;
        return true;
    }

    // Recursively search for data value
    else if (Tree->place.getStreetName()+Tree->place.getHouseNum() > loc.getStreetName()+loc.getHouseNum())
        return (SearchHelper(loc, Tree->Left));
    else if (Tree->place.getStreetName()+Tree->place.getHouseNum() < loc.getStreetName()+loc.getHouseNum());
        return (SearchHelper(loc, Tree->Right));
    
    return false;
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(Address &loc){
    // Call tree searching function
    return (SearchHelper(loc, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(Address loc, Node * &Tree){
    // Insert data into the tree
    if (Tree == NULL){
        Tree = new Node;
        Tree->place = loc; 
        Tree->Left = NULL;
        Tree->Right = NULL;
        return true;
    }

    // Data value already inserted
    else if (Tree->place.getLat() == loc.getLat() && Tree->place.getLon() == loc.getLon() 
            && (Tree->place.getStreetName()+Tree->place.getHouseNum()) == (loc.getStreetName()+loc.getHouseNum()))
        return false;     

    // Recursively search for insertion position
    //Sorted by latitude values [36.03-36.15]
    else if (Tree->place.getStreetName()+Tree->place.getHouseNum() > loc.getStreetName()+loc.getHouseNum())
        return (InsertHelper(loc, Tree->Left));
    else if (Tree->place.getStreetName()+Tree->place.getHouseNum() < loc.getStreetName()+loc.getHouseNum())
        return (InsertHelper(loc, Tree->Right));
    return false;
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(Address loc){
    // Call tree insertion function
    return (InsertHelper(loc, Root));
}


//-----------------------------------------------------------
// Delete a single node from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::DeleteNode(Node * &Tree){
    Node *Temp = Tree;

    // Node has 0 children
    if ((Tree->Left == NULL) && (Tree->Right == NULL))
        Tree = NULL;

    // Node has 1 child
    else if (Tree->Left == NULL)
        Tree = Tree->Right;
    else if (Tree->Right == NULL)
        Tree = Tree->Left;

    // Node has 2 children
    else {
        // Find leftmost node in right subtree
        Node *Parent = Tree;
        Temp = Tree->Right;
        while (Temp->Left != NULL){
            Parent = Temp;
            Temp = Parent->Left;
        }
        // Replace deleted data with leftmost value
        if (Parent == Tree)
            Parent->Right = Temp->Right;
        else
            Parent->Left = Temp->Right;
        Tree->place = Temp->place;
    }

    // Delete node
    delete Temp;
    return true;
}

//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
bool BinaryTree::DeleteHelper(Address loc, Node * &Tree){
    // Data value not found
    if (Tree == NULL)
        return false;

    // Data value found and deleted
    else if (Tree->place.getStreetName()+Tree->place.getHouseNum() == (loc.getStreetName()+loc.getHouseNum()))
        return (DeleteNode(Tree));

    // Recursively search for node to delete
    else if (Tree->place.getStreetName()+Tree->place.getHouseNum() > loc.getStreetName()+loc.getHouseNum())
        return (DeleteHelper(loc, Tree->Left));
    else if (Tree->place.getStreetName()+Tree->place.getHouseNum() < loc.getStreetName()+loc.getHouseNum())
        return (DeleteHelper(loc, Tree->Right));
    else
        return false;
}

//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Delete(Address loc){
    // Call tree deletion function
    return (DeleteHelper(loc, Root));
}

int BinaryTree::CountHelper(Node* Tree){
    if(Tree == NULL)
        return 0;  
    else 
        return CountHelper(Tree->Left) + CountHelper(Tree->Right) + 1;
        //Left then right, add one for the root. 
        //Essentially counts how many times each function call is used.
}

//-----------------------------------------------------------
// Returns the total amount of nodes in the tree.
//-----------------------------------------------------------
int BinaryTree::count(){
    return CountHelper(Root);
}

//-----------------------------------------------------------
// Height helper function.
//-----------------------------------------------------------
int BinaryTree::HeightHelper(Node* Tree){
    if(Tree == NULL) //Node has no value.
        return 0;
    else
        return max(HeightHelper(Tree->Left),HeightHelper(Tree->Right))+1;
        //Adds branch of depth up. Gives the highest value.
}

//-----------------------------------------------------------
// Returns the deepest branch of the tree.
//-----------------------------------------------------------
int BinaryTree::height(){
    return HeightHelper(Root);
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree){
    // Check terminating condition
    if (Tree != NULL){
        // Print left subtree
        PrintHelper(Tree->Left);

        // Print node value
        Tree->place.print();

        // Print right subtree
        PrintHelper(Tree->Right);
    }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print(){
    // Call tree printing function
    PrintHelper(Root);
    cout << endl;
}