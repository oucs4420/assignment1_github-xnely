#include <iostream>
#include <fstream>
using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1

int main( int argc, char* argv[] )
{
    std::cout<<"program: "<<argv[0]<<'\n';
    std::ifstream file;
    int count;
    std::string trash; // take side affect of std::getline
    for (int arg = 1; arg < argc; ++arg){
        std::cout<<' '<<argv[arg]<<": ";
        file.open(argv[arg]);
        if(file.fail()) std::cout<<"-1\n";
        else{
            count = 0;
            while(std::getline(file, trash)) ++count; // use getline to count # of '\n'
            std::cout<<count<<'\n';
        }
        file.close();
    }

    exit(0); // this means that the program executed correctly!
}
