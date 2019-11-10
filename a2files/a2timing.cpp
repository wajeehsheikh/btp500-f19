/**************************************************************************/
/*                                                                        */
/*   A2 timing                                                            */
/*                                                                        */
/*   To compile: g++ a2timing timer.cpp -std=c++0x                        */
/*                                                                        */
/*   You are free to alter both tablepartD.h and the main to make it      */
/*   easier to get data for graphing.  This main outputs 1 timing,        */
/*   after every 1000 updates().  Only rule is that you should not        */
/*   alter the data generation and data usage (ie first 3 lines of main)  */
/*                                                                        */
/**************************************************************************/

#include "tablepartD.h"
#include "timer.h"
#include <string>
#include <iostream>
#include <cstdlib>

const int maxRecords=2000000;

void createData(string keys[],int data[],int max);
int main(void){

    std::string* keys = new std::string[maxRecords];        //list of test cases. 
    int* data=new int[maxRecords];
    createData(keys,data,maxRecords);

    //all tables start with capacity of 2, and max load factor of 70%.  
    //first grow occurs after 4 things are added
    LPTable<int> table(5,0.7);
    Timer T;
    std::cout << "number of items in table, time" << std::endl;
    std::cout << 0 << ", " << 0.0 << std::endl;
    for(int i=0;i<200000;i++){
    	T.start();
    	table.update(keys[i],data[i]);
    	T.stop();
    	if(i%1000==999){
    		std::cout << i+1 << ", " << T.currtime() << std::endl;
    	}
    }

}




void createData(std::string keys[],int data[],int max){
	FILE* fp=fopen("dictionary.txt","r");
	int i=0;
	std::string front="A_";
	char curr[50];
	while(fscanf(fp,"%s\n",curr)==1){
		keys[i]=curr;
		data[i]=rand()%100;
		i++;                      
	}
	int numWords=i;
	int j=0;
	while(i<max){
		keys[i]=front+keys[j];
		data[i]=rand()%100;
		i++;
		j++;
		if(j==numWords){
			front[0]+=1;
			j=0;
		}
	}
}

