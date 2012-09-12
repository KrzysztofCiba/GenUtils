/**
 * @file
 * @author Krzysztof Ciba (Krzysztof.Ciba@NOSPAMagh.edu.pl)
 *
 * @brief Dummy Generator_i class declaration.
 */

#ifndef GENERATOR_I_H 
#define GENERATOR_I_H


#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "GenCommandBase.h"
#include "GenCommand.h"
#include "StringParse.h"

// common definition
#include "common.h"

/**
 * @class Generator_i  
 * @date 5th Oct, 2006
 * @author Krzysztof Daniel Ciba Krzysztof.Ciba@NOSPAMagh.edu.pl 
 *
 * @brief A dummy generator wrapper.
 */
class Generator_i  {

public:
	//! default constructor
	Generator_i() {};

	//! default destructor
	~Generator_i() {};

	//! a generator initalisation
	virtual void initGenerator();
	
	//! an event generation
	virtual void genEvent();

	//! a command parsing
	virtual void parseCommands();
	
	//! print out GenCommands
	void printout();
	
	//! copy values from local variables to generator commons
	void local2global();
	
	//! copy values form generator commons to local variables
	void global2local(); 

	//! dummy local variable initalisation
	//! only for testing purpose
	void dummyinit();

	//! dummy m_commandVector initialisation
	//! @param cvec dummy options
	//! only for testing purpose
	void dummyopts(std::vector< std::string > cvec);

	//! user-defined specialised command parsing 
	//! called, when GenCommand is not defined in m_cmdMap
	//! as template not always can handle 
	//! not ordinary commands...
	//! @param cmd a command to parse
	//! @return true, if parsing was successful, false otherwise
	bool userParse( std::string cmd );
	

private:

	//! a vector with generator commands read from JobOptionsSvc
	std::vector< std::string > m_commandVector;
	
	//! a dummy 'complicated' command variable
	int m_seed1;
	//! a dummy 'complicated' command variable
	int m_seed2;
	

	//! a member for mapping global_.i1
	int m_i1;

	//! a member for mapping global_.i2
	int m_i2;

	//! a member for mapping global_.d1;
	double m_d1;

	//! a member for mapping global_.d2;
	double m_d2;

	//! a member for mapping 1st element of global_.itab[]
	int m_itab1;
	
	//! a member for mapping 2nd element of global_.itab[]
	int m_itab2;
	
	//! a member for mapping 3rd element of global_.itab[]
	int m_itab3;
	
	//! a member for mapping 4th element of global_.itab[]
	int m_itab4;
	
	//! a member for mapping 5th element of global_.itab[]
	int m_itab5;
	
	//! a member for mapping  element of global_.dtab[]
	double m_dtab[5];

	//! a member for mapping global_.rockstar
	std::string m_rstar;

	//! an only local variable
	std::string m_local;


	//! a map containning strings and GenCommandBase*
	GenComPtrMap m_cmdMap;

	//! helper functions to find desired GenCommand 
	//! @param name a command name
	bool isPresent( std::string name );
	
	//! a helper function to get desired command
	//! @param name command name
	//! @brief remember to use dynamic_cast<Derived*>
	//! to get full functionality  
	GenCommandBase* get( std::string name );

};

#endif // GENERATOR_I_H
