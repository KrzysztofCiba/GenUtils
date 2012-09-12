/**
 * @file
 * @author Krzysztof Ciba (Krzysztof.Ciba@NOSPAMagh.edu.pl)
 *
 * @brief Dummy Generator_i class definition.
 */

#include <sstream>

#include "Generator_i.h"
#include "common.h"

bool Generator_i::userParse( std::string cmd ) {
	bool OK =  true;
	StringParse sp( cmd );

	std::string user_label;
  
	user_label = sp.getLabel();
	
	// label OK 
	if ( OK ) {
		// smaple dummy variable reading  
		if ( user_label == std::string("SEEDS") ) {
			if ( ! ( OK = sp.getVal( m_seed1 ) ) )
				std::cout << sp.what() << std::endl;
			if ( ! ( OK = sp.getVal( m_seed2 ) ) )
				std::cout << sp.what() << std::endl;
		}
	}
	
	return OK;
}
//! dummy options initalisation
void Generator_i::dummyopts(std::vector< std::string > cvec) {
	m_commandVector = cvec;
}


//! dummy init
void Generator_i::dummyinit() {
			
	// presetting local variables
	m_i1 = +1;
	m_i2 = -1;
	m_d1 = 0.123456789;
	m_d2 = 0.987654321;

	m_itab1 = 99999;
	m_itab2 = 9999;
	m_itab3 = 999;
	m_itab4 = 99;
	m_itab5 = 9;

	m_dtab[0] = 1.0;
	m_dtab[1] = 2.0;
	m_dtab[2] = 3.0;
	m_dtab[3] = 4.0;
	m_dtab[4] = 5.0;
	
	m_rstar= "DavidBowie";
	m_local = "MickeyMouse";

	m_seed1 = 0;
	m_seed2 = 0;
}



//! a generator initalisation
void Generator_i::initGenerator() { 
		
	// constructing GenCommands 
	IntCmd* I1 = new IntCmd(" PYDAT1     MSEL  I1",&m_i1,&global_.i1,"%s %s %s %i" );
	m_cmdMap[I1->name()] = I1;
	
	IntCmd* I2 = new IntCmd("I2",&m_i2,&global_.i2,"%s %i" );
	m_cmdMap[I2->name()] = I2;
	
	DoubleCmd* D1 = new DoubleCmd("D1",&m_d1,&global_.d1,"%s %lf" );
	m_cmdMap[D1->name()] = D1;
	
	DoubleCmd* D2 = new DoubleCmd("D2",&m_d2,&global_.d2,"%s %lf" );
	m_cmdMap[D2->name()] = D2;
	
	// only local variable, e.g. fot some steering :)
	CharCmd* LOCAL = new CharCmd(std::string("LOCAL"),m_local);
	m_cmdMap[LOCAL->name()] = LOCAL;


	CharCmd* RS = new CharCmd(std::string("ROCKSTAR"),m_rstar,&(*global_.rockstar),"%s %s");
	m_cmdMap[RS->name()] = RS;

	IntCmd* ITAB1 = new IntCmd("ITAB 1",&m_itab1,&global_.itab[0],"%s %i %i" );
	m_cmdMap[ITAB1->name()] = ITAB1;

	IntCmd* ITAB2 = new IntCmd("ITAB 2",&m_itab2,&global_.itab[1],"%s %i %i" );
	m_cmdMap[ITAB2->name()] = ITAB2;
	
	IntCmd* ITAB3 = new IntCmd("ITAB 3",&m_itab3,&global_.itab[2],"%s %i %i" );
	m_cmdMap[ITAB3->name()] = ITAB3;

	IntCmd* ITAB4 = new IntCmd("ITAB 4",&m_itab4,&global_.itab[3],"%s %i %i" );
	m_cmdMap[ITAB4->name()] = ITAB4;

	IntCmd* ITAB5 = new IntCmd("ITAB 5",&m_itab5,&global_.itab[4],"%s %i %i" );
	m_cmdMap[ITAB5->name()] = ITAB5;

	DoubleCmd* DTAB1 = new DoubleCmd("DTAB 1",&m_dtab[0],&global_.dtab[0],"%s %i %lf" );
	m_cmdMap[DTAB1->name()] = DTAB1;

	DoubleCmd* DTAB2 = new DoubleCmd("DTAB 2",&m_dtab[1],&global_.dtab[1],"%s %i %lf" );
	m_cmdMap[DTAB2->name()] = DTAB2;
	
	DoubleCmd* DTAB3 = new DoubleCmd("DTAB 3",&m_dtab[2],&global_.dtab[2],"%s %i %lf" );
	m_cmdMap[DTAB3->name()] = DTAB3;
	
	DoubleCmd* DTAB4 = new DoubleCmd("DTAB 4",&m_dtab[3],&global_.dtab[3],"%s %i %lf" );
	m_cmdMap[DTAB4->name()] = DTAB4;

	DoubleCmd* DTAB5 = new DoubleCmd("DTAB 5",&m_dtab[4],&global_.dtab[4],"%s %i %lf" );
	m_cmdMap[DTAB5->name()] = DTAB5;

};

void Generator_i::printout() {
		std::cout << "[G_i] DEFINED COMMANDS are:" << std::endl;
	itGenComPtrMap it;
	for ( it = m_cmdMap.begin();
	 			it != m_cmdMap.end(); 
 				++it ) {

		GenCommandBase* cmd = it->second;

		IntCmd* intcmd = dynamic_cast<IntCmd*>( cmd );
		if ( intcmd ) {
			std::cout << "[G_i] " << (*intcmd) << std::endl;
		}
		DoubleCmd* dblcmd = dynamic_cast<DoubleCmd*>( cmd );
		if ( dblcmd ) {
			std::cout << "[G_i] " << (*dblcmd) << std::endl;
		}
		CharCmd* chcmd = dynamic_cast<CharCmd*>( cmd );
		if ( chcmd ) {
			std::cout << "[G_i] " << (*chcmd) << std::endl;
		}		
	} 

	std::cout << "[G_i] SEEDS seed1 = " << m_seed1 << ", seed2 = " << m_seed2 << std::endl;

 }
	
//! an event generation
//! not implemented yet
void Generator_i::genEvent() {
	

};

//! a command parsing
void Generator_i::parseCommands() {

	if ( m_commandVector.size() != 0 ) {
		std::vector< std::string >::iterator it;
		for ( it = m_commandVector.begin();
					it != m_commandVector.end();
					++it ) {

			GenCommandBase* base;
 
			std::cout << "[G_i] The job option command is = " << (*it) << std::endl;
			
			std::stringstream inout;
			inout << (*it);
			std::string word;
			std::vector< std::string > words;
			std::vector< std::string >::iterator itw;
			
			while ( inout >> word )
				words.push_back( word );
			

			std::string label;
			bool parsedOK = false;
			for ( itw = words.begin(); itw != words.end(); ++itw ) {
				
				if ( parsedOK ) break;

				// buid label from words
				if ( itw == words.begin() ) {
					label = (*itw); // 1st word
				} else 
					label += std::string(" ") + (*itw); // other else pleus space

				if ( isPresent( label ) ) { // label is present?
					if ( ( NULL != ( base = get(label) ) )  // base command is present?
							 && ( base->parse(*it) ) ) { // and parsed successfully?
						parsedOK = true;
						break;
					} else {
						std::cout << " parsing of command " << (*it) 
											<< " ends with error " << std::endl; 
					}
				}
			}
		
			if ( ! parsedOK ) {
				std::cout << "[G_i] WARNING *** command \"" << (*it) << "\" cannot be parsed..." << std::endl;
				std::cout << "[G_i] WARNING *** handle it here using an \'old\' style" << std::endl;
				parsedOK =  	userParse(*it);
			}
		}
	} // else		
}; // for 
 

GenCommandBase* Generator_i::get( std::string name ) {
	itGenComPtrMap it;
	it = m_cmdMap.find( name );
	if ( it != m_cmdMap.end() ) {
		return it->second;
	}
	return NULL;
}

void Generator_i::local2global() { 

	itGenComPtrMap it;
	for ( it = m_cmdMap.begin();
			  it != m_cmdMap.end();
				it++ ) 
		it->second->local2global();
	
};

void Generator_i::global2local() { 

	itGenComPtrMap it;
	for ( it = m_cmdMap.begin();
			  it != m_cmdMap.end();
				it++ ) 
		it->second->global2local();

};


bool Generator_i::isPresent( std::string name ) {
	itGenComPtrMap it;
	it = m_cmdMap.find( name );
	if ( it != m_cmdMap.end() ) return true;
	return false;
};


