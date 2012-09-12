/**
 * @file
 * @author Krzysztof.Ciba@NOSPAM.agh.edu.pl
 * @date Oct 19th, 2006
 * 
 * @brief Test program.
 */

#include <iostream>
#include <string>

#include "Generator_i.h"
#include "common.h"

using namespace std;

//! main program entry
int main() {

	string line("***********************************************************\n");

	cout << line << line << line 
			 << " GenCommand + StringParse testing" << endl 
			 << line << line << line << endl << endl;;
		
	cout << endl << endl << line;
	cout << "              TEST 1" << endl;
	cout << "              Generator_i constructing" << endl << line << endl;
		

	cout << line;
	cout << "[f77] calling writeout_()" << endl; 
	writeout_();
	cout << line;
	cout << "[f77] calling init_() " << endl;
	init_();
	cout << line;
	cout << "[f77] calling writeout_()" << endl; 
	writeout_();
	cout << line;
	cout << "[c++] building Generator_i object..." << endl;
	Generator_i myGen;
	cout << line;
	cout << "[c++] calling Generator_i.initGenerator()" << endl;
	myGen.initGenerator();
	cout << line;
	cout << "[c++] calling Generator_i:dummyinit()" << endl;
	myGen.dummyinit();
	cout << line;
	cout << "[c++] calling Generator_i.printout()" << endl;
	myGen.printout();
	cout << line;
	cout << "[f77] calling writeout_()" << endl; 
	writeout_();
	cout << line << endl << endl;


	cout << endl << endl << line;
	cout << "              TEST 2" << endl;
	cout << "              local2global copy" << endl << line <<  endl << endl;
		

	cout << line;
	cout << "[c++] calling Generator_i:dummyinit()" << endl;
	myGen.dummyinit();
	cout << line;
	cout << "[f77] calling writeout_()" << endl; 
	writeout_();
	cout << line;
	cout << "[c++] calling Generator_i.printout()" << endl;
	myGen.printout();
	cout << line;
	cout << "[c++] calling Generator_i::local2global()" << endl;
	myGen.local2global();
	cout << line;
	cout << "[f77] calling writeout_()" << endl; 
	writeout_();
	cout << line;
	cout << "[c++] calling Generator_i.printout()" << endl;
	myGen.printout();
	cout << line << endl << endl;

	
	cout << endl << endl << line;
	cout << "              TEST 3" << endl;
	cout << "              global2local copy" << endl << line <<  endl << endl;
		

	cout << line;
	cout << "[f77] calling modify_()" << endl;
	modify_();
	cout << line;
	cout << "[f77] calling writeout_()" << endl; 
	writeout_();
	cout << line;
	cout << "[c++] calling Generator_i.printout()" << endl;
	myGen.printout();
	cout << line;
	cout << "[c++] calling Generator_i::global2local()" << endl;
	myGen.global2local();
	cout << line;
	cout << "[f77] calling writeout_()" << endl; 
	writeout_();
	cout << line;
	cout << "[c++] calling Generator_i.printout()" << endl;
	myGen.printout();
	cout << line << endl << endl;
	

	cout << endl << endl << line;
	cout << "              TEST 4" << endl;
	cout << "              command parsing" << endl << line <<  endl << endl;

	vector< string > cvec;
	cvec.push_back("   D1 -.123456");
	cvec.push_back("D2 .123456");	
	cvec.push_back("  DTAB \t\t1 1.1");
	cvec.push_back("DTAB   2 2.2");
	cvec.push_back(" DTAB 3 3.3");
	cvec.push_back("DTAB   4 4.4");
	cvec.push_back("  DTAB    5 5.5");
	cvec.push_back("PYDAT1 MSEL I1 11111");
	cvec.push_back("    I2 22222");
	cvec.push_back("ITAB 1 11111");
	cvec.push_back("  ITAB 2 22222   ");
	cvec.push_back("ITAB 3 33333");
	cvec.push_back("  ITAB 4 44444\t\t");
	cvec.push_back("ITAB 5 55555");
	cvec.push_back("ROCKSTAR         PinkFloyd");
	cvec.push_back("UNKNOWN  0");
	cvec.push_back("SEEDS  999999 666666");
	cvec.push_back("LOCAL DonaldDuck");
 

	cout << line;
	cout << "[c++] calling Generator_i.printout()" << endl;
	myGen.printout();
	cout << line;
	cout << "[c++] calling Generator_i.dummyopts( cvec )" << endl;
	myGen.dummyopts(cvec);
	cout << line;
	cout << "[c++] calling Generator_i.parseCommands( cvec )" << endl;
	myGen.parseCommands();
	cout << line;
	cout << "[c++] calling Generator_i.printout()" << endl;
	myGen.printout();

	

	


	return 0;
}
