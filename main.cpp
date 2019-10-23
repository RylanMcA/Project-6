#include "tree.h"

//USE INPUT FILE 2 FOR BST.

void getInput(string &num, string &street){
    cout << "What is the house number? (enter an integer):  ";
    cin >> num;
    cin.ignore();
    cout << "What is the street name? (enter a string): ";
    getline(cin, street);
}

void searchAdd(BinaryTree &tree, string num, string street){
    getInput(num,street);
    Address userLoc = Address(0,0,num,street);
    if(tree.Search(userLoc)){ //Search for it once. Just find it.
        cout << "\nFound that address... " << endl;
        userLoc.print();
    }
    else  
        cout << "\nUnable to find that entry..." << endl; 
}

void deleteAdd(BinaryTree &tree, string num, string street){
    getInput(num,street);
    Address userLoc = Address(0,0,num,street);
    if(tree.Delete(userLoc))
        cout << "\nDeleted that entry for you..." << endl;
    else
        cout << "\nUnable to find and delete that entry... " << endl;
}

void readFile(BinaryTree &tree){
    float lat, lon;
    string num, street = "";
    char ch = ' ';
    ifstream din;
    
    string file="";
    cout << "What file are you using? (USE input2.txt FORM THE WEBSITE): ";
    cin >> file;
    din.open(file);
    while (din >> lat >> lon >> num){
        din.get(ch);
        getline(din, street);
        Address temp = Address(lat,lon,num,street);
        tree.Insert(temp); 
    } 
    din.close();
}

int main(){
    // Local variables
    string num,street = " ";
    BinaryTree tree;
    readFile(tree);
    
    char sel = ' ';
    while(sel != 's' && sel != 'd'){
        cout << "What are you trying to do?\ns - Search\nd - Delete";
        cout << "\nInput: ";
        cin >> sel;
    }
    
    if(sel == 's')
        searchAdd(tree, num, street);
    if(sel == 'd')
        deleteAdd(tree, num, street);  
    return 0;
}

