#ifndef AO_H
#define AO_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>

class assign_obj{
    private:
        
        struct  node{
            char data;
            int count;
            node* next;
        };
        
        node* head;
        node* tail;


    public:
        assign_obj();
        assign_obj(std::string);
        friend std::ostream& operator<<(std::ostream & out, assign_obj & obj);
        
        void compact();
        void f_add(char i);
        void e_add(char i);

        const assign_obj& operator=(const assign_obj &);
        friend const assign_obj operator+(assign_obj &,assign_obj &);

        ~assign_obj();
        assign_obj(const assign_obj&); 
};





//Input and output none

//This function will just set head and tail to nullptr
assign_obj:: assign_obj(){
    head = tail = nullptr;
}



//Input
//one string s

//output none

//This function will go through each character of string and convert it to uppercase and put it in the link list
assign_obj:: assign_obj(std::string s){

    head = tail = nullptr;

    for(int i = 0; i < s.size(); i++){

        char c = std::toupper(s[i]);
       
        if(!head){

            head = tail = new node{c,1,nullptr};
            
        }else{

            tail->next = new node{c,1,nullptr};
            tail = tail->next;
        }

    }

}




//Input 
//one class object obj
//one ostream out

//output
//return out

//This fuction will go through each data in obj.head  and each count (convert integer into string) and 
//than output the data in this format [value:count value:count ....]
std::ostream& operator<<(std::ostream & out, assign_obj & obj){

    out << "[ ";

    assign_obj::node* p= obj.head;
    
    while (p)
    {

        out << p->data << ":" << std::to_string(p->count) << " ";

        p = p->next;
    }

    out << "]" << "\n";

    return out;
}





//Input and output none

//This function will go through link list and if it find duplicate value it increase the count of first value and 
//than it will delete the duplicate node from linked list.
//Lastly by using selection sort, I rearrage the data in link list in alphabetical order.
void assign_obj:: compact(){
   
    for(node* p = head; p; p = p->next){
   
        node* prev = p;
    
        for(node* q = p->next; q; q = q->next){
           
            if(p->data == q->data){
               
                p->count += q->count;

                node* del  = q;
                q = prev;
                prev->next = del->next;

                delete del;

            }else{

                prev = q;
            }


        }

    }

    //placing things in link list in alphabetical order
    for(node* p = head; p; p = p->next){

        node* m = p;

        for(node* q = p->next; q; q = q->next){

            if(q->data < m->data){
                
                m = q;

            }
        }

        char temp = p->data;
        int num = p->count;

        p->data = m->data;
        p->count = m->count;

        m->data = temp;
        m->count = num;

    }

}




//Input
//one character i, that will be put at the front of linked list

//output none

//This function will convert passed in character from lowercase to uppercase and put it in the p node that will point to head
//than head will point wherever p is pointing.
void assign_obj:: f_add(char i){
    
    char c = std::toupper(i);
    node* p;
    p = new node{c,1,head};
    head = p;
}




//Input
//one character i, that will be put at the end of a item array

//output none

//This function will convert passed in character from lowercase to uppercase and put at the end of link list.
void assign_obj:: e_add(char i){

    char c = std::toupper(i);

    tail->next = new node{c,1,nullptr};
    tail = tail->next;
}





//Input 
//one class object rhs 

//Output
//-------------------ASSIGNMENT-------------------
//return *this;

//This function will first check if &rhs == this. If it is not than it will delete head and 
//Than head and tail set equl to nullptr. After thst all the data from rhs.head  will be copied in head.
const assign_obj & assign_obj::  operator=(const assign_obj & rhs){
    
    if(&rhs == this){
        return *this;
    }
    
    node* p = head;

    while(p){

        node* del = p;
        p = p->next;
        delete del;
    }

    std::cout<< "-----------------ASSIGNMENT-------------------" << std::endl;
    
    head = tail = nullptr;
    
    
    for(node* q = rhs.head; q; q = q->next){

        if(!head){
            head = tail = new node{q->data,q->count,nullptr};

        }else{

            tail->next = new node{q->data,q->count,nullptr};
            tail = tail->next;

        }
        
    }


    return *this;
}




//Input 
//Two class objects a1 and a2

//output
//return a1

//This fuction will create new class object a3. Than it go through data of a1 and a2 and put it in a3 assign_obj.
//and than call compact() fuction on a3.
const assign_obj operator+(assign_obj & a1,assign_obj & a2){



    assign_obj a3;
    
    a3.head = a3.tail = nullptr;
    
    for(assign_obj::node* p = a1.head; p; p = p->next){

        if(!a3.head){
            a3.head = a3.tail = new assign_obj::node{p->data,p->count,nullptr};

        }else{

            a3.tail->next = new assign_obj::node{p->data,p->count,nullptr};
            a3.tail = a3.tail->next;
        }

    }

    for(assign_obj::node* q = a2.head; q; q = q->next){

        a3.tail->next = new assign_obj::node{q->data,q->count,nullptr};
        a3.tail = a3.tail->next;

    }
    

    a3.compact();

    return a3;
}



//Input none

//Output
//-------------------DELETE-------------------

//This function will delete head node
assign_obj:: ~assign_obj(){
    
    std::cout<< "-------------------DELETE---------------------" << std::endl;
    node* p = head;

    while(p){

        node* del = p;
        p = p->next;
        delete del;
    }
}


//Input 
//one class object rhs

//Output
//--------------COPY----------------

//This function will copy the data from rhs.head  to head node
assign_obj:: assign_obj(const assign_obj&rhs){

    head = tail = nullptr;
    
    std::cout<< "--------------------COPY----------------------" << std::endl;
    
    for(node* q = rhs.head; q; q = q->next){

        if(!head){
            head = tail = new node{q->data,q->count,nullptr};

        }else{

            tail->next = new node{q->data,q->count,nullptr};
            tail = tail->next;
        }
        
    }
    
} 


#endif