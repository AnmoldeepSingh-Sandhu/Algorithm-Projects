#include <iostream>
#include <vector>

//Input 
// 3 vectors (v1, v2, cs). cs is a combo vector.
// string s which have atoz characters in it.
// string random_s which is going to store random characters in it.

//output
//It will print out random_s string

//In this function we will run for loop to fill random_s string and vectors(v1,v2,cs).
void generate_sv(std::vector<int> & v1, std::vector<int> & v2, std::vector<int> & cs, std::string s, std::string & random_s){

    //random string
    for(int i = 0; i < 16; i++){

        int r = rand()*1%2;

        if(r == 0){
            random_s += s[rand()*26 % 27];

        }else{
            random_s += toupper(s[rand()*26 % 27]);
        }
    }



    
    //random vectors
    int count = 0;
    for(unsigned i = 0; i < v1.size(); i++){

        if(count == 0){

            v1[i] = rand();
            v2[i] = rand();
            
            count++;

        }else{
            do{
                v1[i] = rand();

            }while(v1[i] < v1[i-1]);
            
            do{
                v2[i] = rand();

            }while(v2[i] > v2[i-1]);
        }


    }


    //combo vector unsorted
    for(unsigned i = 0; i < cs.size(); i++){

        if(i <= 7){
            cs[i] = v1[i];
        }else{
            cs[i] = v2[i-8];
        }
    }


    //print random_s
    std::cout<<std::endl;
    std::cout<< "Random String: " << random_s << std::endl;
    std::cout<<std::endl;

}





//Input
//string random_s which have random characters in it.
//vector cs which have number from both v1 and v2 vector.

//output none

//This function is basically going to sort the random_s string and vector cs
void sort(std::string & random_s, std::vector<int> & cs){

    int c1 = 0;
    int c2 = 0;

    for(int i = 0; i < 16; i++){

        if(++c1 && islower(random_s[i])){
            char temp = random_s[i];

            for(int j = random_s.substr(0, i).size(); j > 0; j--){
                c1++;
                random_s[j] = random_s[j-1];
            }

            random_s[0] = temp;

        }
    }

    std::cout<< "c1: " << c1 << std::endl;
    
    
    for(unsigned i = 0; i < cs.size(); i++){

        int m = i;

        for(unsigned j = i+1; j < cs.size(); j++){

            if(++c2 && cs[m] > cs[j]){
                m = j;
            }

        }

        int temp = cs[i];
        cs[i] = cs[m];
        cs[m] = temp;       
        
    } 

    std::cout<< "c2: " << c2 << std::endl;
}






//Input
// 3 vectors (v1, v2, cs). cs is a combo vector.
// string s which have organized random_s string.

//output
//It will print out string s and all vectors (v1,v2,cs).
void print(std::string s, std::vector<int> v1, std::vector<int> v2, std::vector<int> cs){

    //print organized string
    std::cout<< "Organized String: ";
    std::cout<< s << std::endl;
    std::cout<<std::endl;



    //print v1
    std::cout<< "Vector One: ";
    for(unsigned x : v1){
        std::cout<< x << " ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;



    //print v2
    std::cout<< "Vector Two: ";
    for(unsigned x : v2){
        std::cout<< x << " ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;



    //print combo vector
    std::cout<< "Combo Vector: ";
    for(unsigned x : cs){
        std::cout<< x<<" ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;


}





int main(){

    std::string s = "abcdefghijklmnopqrstuvwxyz";
    std::string random_s = "";

    std::vector<int> v1(8);
    std::vector<int> v2(8);
    std::vector<int> cs(16);

    generate_sv(v1,v2,cs,s,random_s);

    sort(random_s, cs);

    print(random_s,v1,v2,cs);

    return 0;
}