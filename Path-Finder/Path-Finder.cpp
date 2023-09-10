#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>


template <typename T>
class stack{

    public:
        stack(){
            top = nullptr;
        }

        T pop(){
            
            T ret = peek();
            node* to_del = top;
            top = top->next;
            delete to_del;
            return ret;
        }

        void push(T x){

            top = new node{x,top};

        }

        T peek(){
           if(isEmpty()){
                std::cout<< "Stack is Empty." <<std::endl;
                exit(1);
            }

            return top->data;

        }

        bool isEmpty(){
            return top == nullptr;
        }


    private:
        struct  node{
            T data;
            node* next;
        };
        
        node* top;
    
};



struct state{

    int row,col,pre_row,pre_col,sum;
    char symbol;

};



//Input
//Two vector (v and w). v vector have data from text file and w vector will be used to store the path

//output 
//return true if it finds the path otherwise it will return false.

//This function will go through while loop and checks if poistion goes out of bound or hit dead end, it reach the the end if curr.sum 
//is positive it return true otherwise it continue and push new positions in state stack. It alse have one more if which is going to 
//be used for backtracing in case we finds path but curr.sum is negative.
bool path_finder(std::vector<std::vector<int>> & v, std::vector<std::vector<char>> & w){
    
    stack<state> s;
    s.push({0,0,0,0,0});

    while (!s.isEmpty()){

        state curr = s.pop(); 

        if((curr.row <= -1 || curr.col <= -1 || curr.row >= v.size() || curr.col >= v[curr.row].size()) || w[curr.row][curr.col] == 'v' || w[curr.row][curr.col] == '^' || w[curr.row][curr.col] == '>' || w[curr.row][curr.col] == '<'){

            if(curr.symbol == '<'){

                w[curr.pre_row][curr.pre_col] = '-';

            }

        }else if(curr.symbol == '<'){

                w[curr.pre_row][curr.pre_col] = '-';

        }else if(curr.row == v.size()-1 && curr.col == v[curr.row].size()-1){
                
                curr.sum += v[curr.row][curr.col];
        
                w[curr.pre_row][curr.pre_col] = curr.symbol;

                if(curr.sum > 0){

                    w[curr.row][curr.col] = 'X';

                    return true;

                }

                if(curr.symbol == '<'){

                    w[curr.pre_row][curr.pre_col] = '-';

                }

        }else{

            curr.sum += v[curr.row][curr.col];

            if(curr.row > curr.pre_row){
                w[curr.pre_row][curr.col] = 'v';

            }

            if(curr.row < curr.pre_row
            ){
                w[curr.row+1][curr.col] = '^';
            }

            if(curr.col > curr.pre_col){
                w[curr.row][curr.pre_col] = '>';

            }

            if(curr.col < curr.pre_col){
                w[curr.row][curr.col+1] = '<';

            } 

            curr.pre_row = curr.row;
            curr.pre_col = curr.col;

            s.push(state{curr.row,curr.col-1,curr.pre_row,curr.pre_col,curr.sum,'<'});

            s.push(state{curr.row-1,curr.col,curr.pre_row,curr.pre_col,curr.sum,'^'});

            s.push(state{curr.row,curr.col+1,curr.pre_row,curr.pre_col,curr.sum,'>'});

            s.push(state{curr.row+1,curr.col,curr.pre_row,curr.pre_col,curr.sum,'v'});

        }

    }

    return false;
    
}




//Input
//1. Two vector (v and w). v vector is going to store the values from text file and w vector will be filled with dashes
// and it will will used to store the path in path_finder function.
//2. one string, it have the name of the file from where we are going to read the data.

//output
//It will print vector v, afte reading all the data from text file.

//This function will read the values from text file and store those values in vector v. 
//Also, it is going to fill the vector w with dashes.
void read_in(std::vector<std::vector<int>> & v, std::string & name, std::vector<std::vector<char>> & w){

    std::ifstream fin;
    int read;

    int sum = 0;
    int i = 0;
    int j = 0;
    

    fin.open(name);

    if(fin.is_open()){

        while(fin >> read){

            if(sum < 1){

                v.resize(read);
                w.resize(read);
                sum++;

            }else if(sum > 0 && sum < 2){

                for(int i = 0; i < v.size(); i++){
                    v[i].resize(read);
                    w[i].resize(read);
                }
                
                sum++;

            }else{
                
                v[i][j] = read;
                w[i][j] = '-';
                j++;


                if(j >= v[0].size()){
                    i++;
                    j = 0;
                }
                
            }

        }

    };

    fin.close();


    std::cout<<std::endl;
    std::cout<< "OG Matrix" << std::endl; 
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){

            std::cout<<std::setw(4)<<v[i][j];
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

}




//No Input

//Output
//It will print out the path saved in w vector

//This function have one string which is going to store the name of the file from where we are going to read the data and
//2 vector v and w. v vector will have the data from text file and w vector is going to store path. Then it will call read_in and
//path_finder function and print out the path result.
int main(){


    std::string name = "Matrix4.txt";
    std::vector<std::vector<int>> v (0,std::vector<int>(0)); //OG vatrix
    std::vector<std::vector<char>> w (0,std::vector<char>(0)); //Path vatrix

    read_in(v, name, w);
    
    if(path_finder(v, w) == true){

        std::cout<<std::endl;
        std::cout<< "Path Matrix" << std::endl; 

        for(int i = 0; i < w.size(); i++){

            for(int j = 0; j < w[0].size(); j++){
                std::cout<<std::setw(4)<<w[i][j];
            }

            std::cout<<std::endl;
        }
        
    }else{
        std::cout<< "No path found." << std::endl;
    }

    return 0;

}