#ifndef AO_H
#define AO_H

#include <iostream>
#include <vector>
#include <cctype>



class assign_obj{
    private:
        
        struct item{
            char value;
            int count;
        };
        std::vector<item> A;
        int size;
    public:
        // just set size to zero
        assign_obj();
        // take in a string and stores it in A it should convert all chacacter to upper case
        assign_obj(std::string);

        // prints out this whole object 
        // [value:count value:count ....]
        friend std::ostream& operator<<(std::ostream & out, assign_obj & obj);

        //will combine the two objects together. If both objs have the same value the counts should be added together. 
        //this function should call compact on both objects before combining
        friend const assign_obj operator+(assign_obj &,assign_obj &);

        //Will compact the A so all identical chars are added together in on item.
        //the resulting vector should be in alphabetical order
        void compact();

        //add a new character to the front of the vector
        void f_add(char i);
        //add a new character to the end of the vector
        void e_add(char i);
};
  


//Input and output none

//This function will just set size to zero
assign_obj:: assign_obj(){
    size = 0;
}



//Input
//one string s

//output none

//This function will go through each character of string and convert it to uppercase and push it the last of A item vector
assign_obj:: assign_obj(std::string s){

    for(int i = 0; i < s.size(); i++){

        char c = std::toupper(s[i]);
        A.push_back({c,1});

    }
}




//Input 
//one class object obj
//one ostream out

//output
//return out

//This fuction will go through each data in obj.A vector and convert integer into string and 
//than output the data in this format [value:count value:count ....]
std::ostream& operator<<(std::ostream & out, assign_obj & obj){

    out << "[ ";

    for(unsigned i = 0; i < obj.A.size(); i++){

        out << obj.A[i].value << ":" << std::to_string(obj.A[i].count) << " ";
    }

    out << "]" << "\n";

    return out;
}



//Input 
//Two class objects a1 and a2

//output
//return a1

//This fuction will go through every data in a2 and put it at the last of a1 vector.
//and than call conpact() fuction on a1.
//I don't need to call the compact() function in this fuction on both a1 and a2 before for loop
//because it is already called in assign_driver.cpp file.
const assign_obj operator+(assign_obj & a1,assign_obj & a2){
    
    for(int i = 0; i < a2.A.size(); i++){
        a1.A.push_back(a2.A[i]);
    }
    a1.compact();
    return a1;
}




//Input and output none

//This fuction will create one extra item vector in which we put the data from A item vector by increase count
//of already added character or by adding data at the end of B vector.
//After that we resize the A vector size equal to B vector size and than transfer all the data from B vector into A vector back.
//Lastly by using selection sort, I rearrage the data in vector in alphabetical order.
void assign_obj:: compact(){

    std::vector<item> B(0);//new vector of item
    for(int i = 0; i < A.size(); i++){
    
        int count = 0;
    
        for(int j = 0; j < B.size(); j++){
           
            if(B[j].value == A[i].value){
               
                B[j].count += A[i].count;
                count++;
            }

        }

        if(count == 0){
           B.push_back(A[i]);
        }

    }


    //putting the data back into A item vector from B item vector
    A.resize(B.size());
    for(int i = 0; i < B.size(); i++){
        A[i] = B[i];
    }

    //placing things in A item vector in alphabetical order
    for(int i = 0; i < A.size(); i++){

        int m = i;

        for(int j = i+1; j < A.size(); j++){

            if(A[m].value > A[j].value){
                m = j; 
            }
        }

        item temp = A[i];
        A[i] = A[m];
        A[m] = temp;

    }

}




//Input
//one character i, that will be put at the position 0 of item vector 

//output none

//This function will convert passed in character from lowercase to uppercase and put at the position 0.
//Before it put new charater at position zero, it will increase the size of vector by 1 and shift all the inputs
//by 1 position back. So, tht we can put new character at position zero
void assign_obj:: f_add(char i){
    
    A.resize(A.size()+1);

    char c = std::toupper(i);
    for(int i = A.size()-1; i > 0; i--){
        A[i] = A[i-1];
    }

    A[0] = {c,1};
}


//Input
//one character i, that will be put at the end of item vector 

//output none

//This function will convert passed in character from lowercase to uppercase and put at the last of item vector
void assign_obj:: e_add(char i){

    char c = std::toupper(i);
    A.push_back({c,1});
}

#endif