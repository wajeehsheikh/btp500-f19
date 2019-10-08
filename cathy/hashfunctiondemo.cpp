#include <iostream>
#include <string>
#include <functional>
 
int main(int argc, char* argv[]){
    std::string s;
 	int cap;
 	std::hash<std::string> hashFunction;
 	if(argc != 3){
 		std::cout << "a.out <key> <array capacity>" << std::endl;
 	}
 	else{
 		s=argv[1];
 		cap=atoi(argv[2]);
 		std::cout << "Hash of " << s << " is: ";
	    std::cout << hashFunction(s) << std::endl;
 		std::cout << "%% capacity is: ";
	    std::cout << hashFunction(s)%cap << std::endl;

	} 
}