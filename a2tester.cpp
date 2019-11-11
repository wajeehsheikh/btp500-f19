/**************************************************************************/
/*                                                                        */
/*   A2 tester file                                                       */
/*                                                                        */
/*   To compile: g++ a2tester -std=c++0x                                  */
/*                                                                        */
/*   V1.1: fixed bug with update() check                                  */
/*                                                                        */
/**************************************************************************/

#include "table.h"
#include <string>
#include <iostream>
#include <cstdlib>

bool test1(std::string key[], int data[], int max, std::string& error);	
bool test2(std::string key[], int data[], int max, std::string& error);	
bool test3(std::string key[], int data[], int max, std::string& error);	
bool test4(std::string key[], int data[], int max, std::string& error);	
bool test5(std::string key[], int data[], int max, std::string& error);	
bool test6(std::string key[], int data[], int max, std::string& error);	
bool test7(std::string key[], int data[], int max, std::string& error);	
bool test8(std::string key[], int data[], int max, std::string& error);	
bool test9(std::string key[], int data[], int max, std::string& error);	
bool test10(std::string key[], int data[], int max, std::string& error);	
bool test11(std::string key[], int data[], int max, std::string& error);	

const int numTests=11;
const int maxRecords=2000000;

typedef bool (*TestPtr)(std::string [], int [], int , std::string& );
void createData(string keys[],int data[],int max);
int main(void){
	TestPtr runTest[numTests]={test1, test2, test3, test4, test5, 
		                       test6, test7, test8, test9, test10,
		                   	   test11};
	std::string msg;
	bool result=true;
	int numPassed=0;

    std::string* keys = new std::string[maxRecords];        //list of test cases. 
    int* data=new int[maxRecords];

    createData(keys,data,maxRecords);
	for(int i=0;result && i<numTests;i++){
		result = runTest[i](keys,data,maxRecords,msg);
		if(!result){
			std::cout << msg << std::endl;
		}
		else{
			numPassed++;
			std::cout << "Test " << i+1 << " passed!" << std::endl;
		}
	}
	if(numPassed == numTests){
		std::cout << "Congratulations! You have passed testing for A2 part 3" << std::endl;
	}
	else{
		std::cout << "Looks like you still have some work left to do" << std::endl;
	}
}
/* test1: Initialization, numRecords(),  isEmpty()
*/
bool test1(std::string keys[], int data[], int max, std::string& error){
	LPTable<int> table1(1000,0.65);
	LPTable<int> table2(10000,0.75);
	bool isGood=true;
	if(table1.numRecords()!=0 || table2.numRecords()!=0){
		isGood=false;
		error="Error 1a: numRecords() should return 0 when table is empty";
	}
	else{
		if(!table1.isEmpty() || !table2.isEmpty()){
			isGood=false;
			error="Error 1b: isEmpty() should return true when table is empty";

		}
	}


	return isGood;
}

/*test2: use update() with new records, grow() should not occur in these calls.
numRecords() and isEmpty() is also checked.
*/
bool test2(std::string keys[], int data[], int max, std::string& error){
	LPTable<int> table1(1000,0.65);
	LPTable<int> table2(10000,0.70);
	LPTable<int> table3(100000,0.60);

	bool isGood=true;
	int i=0;
	int count=0;
	while(isGood && count<650){
		table1.update(keys[i],data[i]);
		if(table1.isEmpty()){
			isGood=false;
			error="Error 2a: table is not empty, isEmpty() should return false, your isEmpty() returns true";
		}
		if(isGood && table1.numRecords()!=count+1){
			isGood=false;
			error="Error 2b: table should have ";
			error+= std::to_string(count+1);
			error+=" records, your numRecords() returned: ";
			error+=std::to_string(table1.numRecords());				
		}
		i++;
		count++;
	}


	count=0;
	while(isGood && count<7000){
		table2.update(keys[i],data[i]);

		if(table2.isEmpty()){
			isGood=false;
			error="Error 2c: table is not empty, isEmpty() should return false, your isEmpty() returns true";
		}
		if(isGood && table2.numRecords()!=count+1){
			isGood=false;
			error="Error 2d: table should have ";
			error+= std::to_string(count+1);
			error+=" records, your numRecords() returned: ";
			error+=std::to_string(table2.numRecords());				
		}		
	
		i++;
		count++;
	}


	count=0;
	while(isGood && count<60000){
		table3.update(keys[i],data[i]);
		if(table3.isEmpty()){
			isGood=false;
			error="Error 2e: table is not empty, isEmpty() should return false, your isEmpty() returns true";
		}
		if(isGood && table3.numRecords()!=count+1){
			isGood=false;
			error="Error 2f: table should have ";
			error+= std::to_string(count+1);
			error+=" records, your numRecords() returned: ";
			error+=std::to_string(table3.numRecords());				
		}		

		i++;
		count++;
	}

	return isGood;

}

/*test3: use update() with new records, grow() should not occur in these calls.
check that find works.
*/
bool test3(std::string keys[], int data[], int max, std::string& error){
	LPTable<int> table1(1000,0.65);
	LPTable<int> table2(10000,0.70);
	LPTable<int> table3(100000,0.60);
	bool isGood=true;
	int i=0;
	int count=0;
	while(count<650){
		table1.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;
	while(count<7000){
		table2.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;
	while(count<60000){
		table3.update(keys[i],data[i]);
		i++;
		count++;
	}

	i=0;
	count=0;
	while(isGood && count<650){
		int value;
		isGood=table1.find(keys[i],value);
		if(!isGood){
			error="Error 3a: find returned false for a record that should exist in the table";
		}
		else{
			if(value!=data[i]){
				isGood=false;				
				error="Error 3b: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find passed back: ";
				error+=to_string(value);
			}
		}
		i++;
		count++;
	}
	count=0;
	while(isGood && count<7000){
		int value;
		isGood=table2.find(keys[i],value);
		if(!isGood){
			error="Error 3c: find returned false for a record that should exist in the table";
		}
		else{
			if(value!=data[i]){
				isGood=false;								
				error="Error 3d: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find passed back: ";
				error+=to_string(value);
			}
		}
		i++;
		count++;
	}
	count=0;
	while(isGood && count<60000){
		int value;
		isGood=table3.find(keys[i],value);
		if(!isGood){
			error="Error 3e: find returned false for a record that should exist in the table";
		}
		else{
			if(value!=data[i]){
				isGood=false;				
				error="Error 3f: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find passed back: ";
				error+=to_string(value);
			}
		}
		i++;
		count++;
	}


	return isGood;
}

/*test 4: modify records, ensure numRecords() is returning the correct value
*/
bool test4(std::string keys[], int data[], int max, std::string& error){

	LPTable<int> table1(1000,0.65);
	LPTable<int> table2(10000,0.70);
	LPTable<int> table3(100000,0.60);
	bool isGood=true;
	int i=0;
	int count=0;
	while(count<650){
		table1.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;
	while(count<7000){
		table2.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;
	while(count<60000){
		table3.update(keys[i],data[i]);
		i++;
		count++;
	}

	i=0;
	count=0;
	while(isGood && count<650){
		if(count%2){
			table1.update(keys[i],data[i]+1);
		}

		if(table1.numRecords()!=650){
			isGood=false;
			error="Error 4a: table should have ";
			error+= std::to_string(650);
			error+=" records, your numRecords() returned: ";
			error+=std::to_string(table1.numRecords());				
		}

		i++;
		count++;
	}
	count=0;
	while(isGood && count<7000){
		if(count%2){
			table2.update(keys[i],data[i]+2);
		}
		if(table2.numRecords()!=7000){
			isGood=false;
			error="Error 4b: table should have ";
			error+= std::to_string(7000);
			error+=" records, your numRecords() returned: ";
			error+=std::to_string(table2.numRecords());				
		}		

		i++;
		count++;
	}
	count=0;
	while(isGood && count<60000){
		if(count%2){
			table3.update(keys[i],data[i]+3);
		}
		if(table3.numRecords()!=60000){
			isGood=false;
			error="Error 4c: table should have ";
			error+= std::to_string(600000);
			error+=" records, your numRecords() returned: ";
			error+=std::to_string(table3.numRecords());				
		}		
		i++;
		count++;
	}
	return isGood;
}
/*test 5: Modify records and test find, ensure that find returns true 
for all records and that the values are updated
*/

bool test5(std::string keys[], int data[], int max, std::string& error){
	LPTable<int> table1(1000,0.65);
	LPTable<int> table2(10000,0.70);
	LPTable<int> table3(100000,0.60);
	bool isGood=true;
	int i=0;
	int count=0;
	while(count<650){
		table1.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;
	while(count<7000){
		table2.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;
	while(count<60000){
		table3.update(keys[i],data[i]);
		i++;
		count++;
	}

	i=0;
	count=0;
	while(count<650){
		if(count%2){
			table1.update(keys[i],data[i]+1);
		}
		i++;
		count++;
	}
	count=0;
	while(count<7000){
		if(count%2){
			table2.update(keys[i],data[i]+2);
		}
		i++;
		count++;
	}
	count=0;
	while(count<60000){
		if(count%2){
			table3.update(keys[i],data[i]+3);
		}
		i++;
		count++;
	}


	i=0;
	count=0;
	int value;
	int correct;

	while(isGood && count<650){
		isGood=table1.find(keys[i],value);
		if(!isGood){
			error="Error 5a: find returned false for a record that should exist in the table";
		}
		else{
			correct=data[i]+(count%2);
			if(value!=correct){
				isGood=false;				
				error="Error 5b: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(correct);
				error+="\nyour find passed back: ";
				error+=to_string(value);
			}
		}
		i++;
		count++;
	}
	count=0;
	while(isGood && count<7000){
		isGood=table2.find(keys[i],value);
		if(!isGood){
			error="Error 5c: find returned false for a record that should exist in the table";
		}
		else{
			correct=data[i]+(count%2)*2;

			if(value!=correct){

				isGood=false;								
				error="Error 5d: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(correct);
				error+="\nyour find passed back: ";
				error+=to_string(value);
			}
		}
		i++;
		count++;
	}
	count=0;
	while(isGood && count<60000){
		int value;
		isGood=table3.find(keys[i],value);
		if(!isGood){
			error="Error 5e: find returned false for a record that should exist in the table";
		}
		else{
			correct=data[i]+(count%2)*3;
			if(value!=correct){
				isGood=false;				
				error="Error 5f: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(correct);
				error+="\nyour find passed back: ";
				error+=to_string(value);
			}
		}
		i++;
		count++;
	}
	return isGood;

}

/*Test 6: add enough records that will force a resize, ensure all records can be found
*/
bool test6(std::string keys[], int data[], int max, std::string& error){
	LPTable<int> table1(1000,0.65);
	LPTable<int> table2(10000,0.70);
	LPTable<int> table3(100000,0.60);

	int i;
	int count;
	bool isGood=true;
	for(i=0, count=0;isGood && count<6500;count++, i++){

		table1.update(keys[i],data[i]);

		if(table1.isEmpty()){
			isGood=false;
			error="Error 6a: table is not empty, isEmpty() should return false, your isEmpty() returns true";
		}
		if(isGood && table1.numRecords()!=count+1){
			isGood=false;
			error="Error 6b: table should have ";
			error+= std::to_string(count+1);
			error+=" records, your numRecords() returned: ";
			error+=std::to_string(table1.numRecords());				
		}

	}

	for(count=0; isGood&&  count<70000; count++,i++){
		table2.update(keys[i],data[i]);
		if(table2.isEmpty()){
			isGood=false;
			error="Error 6c: table is not empty, isEmpty() should return false, your isEmpty() returns true";
		}
		if(isGood && table2.numRecords()!=count+1){
			isGood=false;
			error="Error 6d: table should have ";
			error+= std::to_string(count+1);
			error+=" records, your numRecords() returned: ";
			error+=std::to_string(table2.numRecords());				
		}

	}

	for(count=0; isGood && count<600000; count++,i++){
		table3.update(keys[i],data[i]);
		if(table3.isEmpty()){
			isGood=false;
			error="Error 6e: table is not empty, isEmpty() should return false, your isEmpty() returns true";
		}
		if(isGood && table3.numRecords()!=count+1){
			isGood=false;
			error="Error 6f: table should have ";
			error+= std::to_string(count+1);
			error+=" records, your numRecords() returned: ";
			error+=std::to_string(table3.numRecords());				
		}

	}


	int value;

	i=0;
	count=0;
	while(isGood && count<6500){
		isGood=table1.find(keys[i],value);
		if(!isGood){
			error="Error 6g: find returned false for a record that should exist in the table";
		}
		else{
			if(value!=data[i]){
				isGood=false;				
				error="Error 6h: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find passed back: ";
				error+=to_string(value);
			}
		}
		i++;
		count++;

	}
	count=0;
	while(isGood && count<70000){
		isGood=table2.find(keys[i],value);
		if(!isGood){
			error="Error 6i: find returned false for a record that should exist in the table";
		}
		else{
			if(value!=data[i]){
				isGood=false;								
				error="Error 6j: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find passed back: ";
				error+=to_string(value);
			}
		}
		i++;
		count++;
	}
	count=0;
	while(isGood && count<600000){
		int value;
		isGood=table3.find(keys[i],value);
		if(!isGood){
			error="Error 6k: find returned false for a record that should exist in the table";
		}
		else{
			if(value!=data[i]){
				isGood=false;				
				error="Error 6l: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find passed back: ";
				error+=to_string(value);
			}
		}
		i++;
		count++;
	}
	return isGood;

}


/*Test 7: Test remove()*/
bool test7(std::string keys[], int data[], int max, std::string& error){
	LPTable<int> table(500000,0.70);
	bool isGood=true;

	for(int i=0;i<350000;i++){
		table.update(keys[i],data[i]);
	}
	for(int i=0;isGood && i<350000;i+=2){
		isGood=table.remove(keys[i]);
		if(!isGood){
			error="Error 7a: remove() should have returned true, function returned falsed";
		}
	}

	int value;
	int result;
	for(int i=0;isGood && i<350000;i++){
		result=table.find(keys[i],value);
		if(i%2){
			if(!result){
				isGood=false;
				error="Error 7b: key (";
				error+=keys[i];
				error+=") that was not removed find() is returning false";
			}
			else{
				if(value != data[i]){
					isGood=false;
					error="Error 7c: value passed back from find is not correct after a remove operation";
				}
			}
		}
		else {
			if(result){
				isGood=false;
				error="Error 7d: key (";
				error+=keys[i];
				error+=") was removed but find() is returning true";			
			}
		}
	}
	return isGood;
}




/*Test 8: Test Copy Constructor, ensure that copy is same as original*/
bool test8(std::string keys[], int data[], int max, std::string& error){
	LPTable<int> table1(1000,0.65);
	LPTable<int> table2(10000,0.70);
	LPTable<int> table3(100000,0.60);
	bool isGood=true;
	int i=0;
	int count=0;
	while(count<650){
		table1.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;
	while(count<7000){
		table2.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;
	while(count<60000){
		table3.update(keys[i],data[i]);
		i++;
		count++;
	}

	LPTable<int> table1copy=table1;
	LPTable<int> table2copy=table2;
	LPTable<int> table3copy=table3;

	if(isGood && table1copy.numRecords() != table1.numRecords()){
		error="Error 8a: number of records was not correct.\n Correct number of records: ";
		error+=to_string(table1.numRecords());
		error+="\nYour function returns: ";
		error+=to_string(table1copy.numRecords());
		isGood=false;
	}
	if(isGood && table2copy.numRecords() != table2.numRecords()){
		error="Error 8b: number of records was not correct.\n Correct number of records: ";
		error+=to_string(table2.numRecords());
		error+="\nYour function returns: ";
		error+=to_string(table2copy.numRecords());
		isGood=false;

	}
	if(isGood && table3copy.numRecords() != table3.numRecords() ){
		error="Error 8c: number of records was not correct.\n Correct number of records: ";
		error+=to_string(table3.numRecords());
		error+="\nYour function returns: ";
		error+=to_string(table3copy.numRecords());
		isGood=false;
	}

    //alter original record's data
	while(count<650){
		table1.update(keys[i],data[i]+1);
		i++;
		count++;
	}
	count=0;
	while(count<7000){
		table2.update(keys[i],data[i]+1);
		i++;
		count++;
	}
	count=0;
	while(count<60000){
		table3.update(keys[i],data[i]+1);
		i++;
		count++;
	}

	i=0;
	count=0;
	while(isGood && count<650){
		int value;
		isGood=table1copy.find(keys[i],value);
		if(!isGood){
			error="Error 8d: find returned false for a record that should exist in the table created with copy constructor";
		}
		else{
			if(value!=data[i]){
				isGood=false;				
				error="Error 8e: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find passed back: ";
				error+=to_string(value);
				error+="\nperhaps a deep copy was not made";

			}
		}
		i++;
		count++;
	}
	count=0;
	while(isGood && count<7000){
		int value;
		isGood=table2.find(keys[i],value);
		if(!isGood){
			error="Error 8f: find returned false for a record that should exist in the table created with copy constructor";
		}
		else{
			if(value!=data[i]){
				isGood=false;								
				error="Error 8g: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find passed back: ";
				error+=to_string(value);
				error+="\nperhaps a deep copy was not made";

			}
		}
		i++;
		count++;
	}
	count=0;
	while(isGood && count<60000){
		int value;
		isGood=table3.find(keys[i],value);
		if(!isGood){
			error="Error 8h: find returned false for a record that should exist in the table created with copy constructor";
		}
		else{
			if(value!=data[i]){
				isGood=false;				
				error="Error 8i: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find passed back: ";
				error+=to_string(value);
				error+="\nperhaps a deep copy was not made";
			}
		}
		i++;
		count++;
	}


	return isGood;



}

/*Test 9: Check that deep copy was created with copy constructor*/
bool test9(std::string keys[], int data[], int max, std::string& error){
	LPTable<int> table1(1000,0.65);
	LPTable<int> table2(10000,0.70);
	LPTable<int> table3(100000,0.60);
	bool isGood=true;
	int i=0;
	int count=0;
	while(count<650){
		table1.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;
	while(count<7000){
		table2.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;
	while(count<60000){
		table3.update(keys[i],data[i]);
		i++;
		count++;
	}

	//duplicate table2
	table2=table1;

	count=0;
	while(count<650){
		table1.update(keys[i],data[i]+2);
		i++;
		count++;
	}

	count=0;
	i=0;
	while(isGood && count<650){
		int value;
		isGood=table2.find(keys[i],value);
		if(!isGood){
			error="Error 9a: find returned false for a record that should be in the table";
		}
		else{
			if(value!=data[i]){
				isGood=false;				
				error="Error 9b: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find() passed back: ";
				error+=to_string(value);
				error+="\nperhaps a deep copy was not made";

			}
		}
		i++;
		count++;
	}

	table2=table3;

	i=7650;
	count=0;
	while(count<60000){
		table2.update(keys[i],data[i]+2);
		i++;
		count++;
	}

	count=0;
	i=7650;
	while(isGood && count<60000){
		int value;
		isGood=table3.find(keys[i],value);
		if(!isGood){
			error="Error 9c: find returned false for a record that should be in the table";
		}
		else{
			if(value!=data[i]){
				isGood=false;				
				error="Error 9d: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find() passed back: ";
				error+=to_string(value);
				error+="\nperhaps a deep copy was not made";

			}
		}
		i++;
		count++;
	}

	return isGood;
}


/*Test 10: Test Copy Assignment Operator*/
bool test10(std::string keys[], int data[], int max, std::string& error){
	LPTable<int> table(100000,0.65);
	bool isGood=true;
	int i=0;
	int count=0;
	while(count<65000){
		table.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;

	LPTable<int> moved1=std::move(table);

	i=0;
	count=0;
	while(isGood && count<65000){
		int value;
		isGood=moved1.find(keys[i],value);
		if(!isGood){
			error="Error 10a: find returned false for a record that should exist in the table created with copy constructor";
		}
		else{
			if(value!=data[i]){
				isGood=false;				
				error="Error 10b: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find passed back: ";
				error+=to_string(value);
				error+="\nperhaps a deep copy was not made";
			}
		}
		i++;
		count++;
	}

	return isGood;


}
/*Test 11: Timing runs, no errors for these.*/
bool test11(std::string keys[], int data[], int max, std::string& error){
	LPTable<int> table1(1000,0.65);
	LPTable<int> table2(10000,0.70);
	LPTable<int> table3(100000,0.60);
	bool isGood=true;
	int i=0;
	int count=0;
	while(count<650){
		table1.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;
	while(count<7000){
		table2.update(keys[i],data[i]);
		i++;
		count++;
	}
	count=0;
	while(count<60000){
		table3.update(keys[i],data[i]);
		i++;
		count++;
	}

	//duplicate table2
	table2=std::move(table1);

	count=0;
	i=0;
	while(isGood && count<650){
		int value;
		isGood=table2.find(keys[i],value);
		if(!isGood){
			error="Error 11a: find returned false for a record that should be in the table";
		}
		else{
			if(value!=data[i]){
				isGood=false;				
				error="Error 11b: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find() passed back: ";
				error+=to_string(value);
				error+="\nperhaps a deep copy was not made";

			}
		}
		i++;
		count++;
	}

	table2=std::move(table3);

	i=7650;
	count=0;
	while(isGood && count<60000){
		int value;
		isGood=table2.find(keys[i],value);
		if(!isGood){
			error="Error 11c: find returned false for a record that should be in the table";
		}
		else{
			if(value!=data[i]){
				isGood=false;				
				error="Error 11d: value associated with key: ";
				error+=keys[i];
				error+= " should be: ";
				error+=to_string(data[i]);
				error+="\nyour find() passed back: ";
				error+=to_string(value);
				error+="\nperhaps a deep copy was not made";

			}
		}
		i++;
		count++;
	}

	return isGood;
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

