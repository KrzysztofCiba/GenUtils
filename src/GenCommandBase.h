/**
 * @file GenCommandBase.h
 * @brief A GenCommand template definition.
 * @author Krzysztof Ciba (Krzysztof.Ciba@NOSPAMagh.edu.pl)
 * @date Oct 19th, 2006
 */

#ifndef GENCOMMANDBASE_H
#define GENCOMMANDBASE_H

// from standard libraries
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <map>

///////////////////////////////////////////////////////////////////////
/**
 * @class GenCommandBase 
 * @author Krzysztof Ciba (Krzysztof.Ciba@NOSPAMagh.edu.pl)
 * @date Oct 18th, 2006
 *
 * @brief Base class for template specialised GenCommand template class. 
 *
 *
 * Declaration of pure  virtual interface only. Notice, that not all 
 * functions have their interface analogs. 
 *
 * To get full functionality, you sometimes have to downcasting using
 * dynamic_cast< Derivied* > ( Base* ). Esspecially when using 
 * GenCommand<std::string, char*>, as those type has its own 
 * specialised interface. 
 *
 */
class GenCommandBase { 

 public:
	//! default constructor
	GenCommandBase() { };
	//! default destructor
	~GenCommandBase() { }; 

	//! synchronizes local and global values
	//! @param local2global if eq. true local value is copied to global value,
	//!                     vice versa otherwise, true by default    
	virtual void synchronize( bool local2global = true )  = 0;
	
	//! yet another shorthand for synchronize()
	virtual void local2global() {	synchronize(true);	}; 

	//! yet another shorthand for synchronize()
	virtual void global2local() {	synchronize(false);	};

	//! a command parsing 
	virtual bool parse( std::string com ) = 0;

	//! checks if GenCommand has local var set
	bool isLocal() const { return m_local_flag; };

	//! a shorthand for  isLocal()
	bool local() const { return m_local_flag; };

	//! checks if GenCommand has global var set
	bool isGlobal() const { return m_global_flag; };

	//! a shorthand for  isGlobal()
	bool global() const { return m_global_flag; };

	//! a command name getter
	std::string name() const { return m_name; };

	//! a command format getter
	std::string format() const { return m_fmt; };
	
	//! a command format getter (shorthand for format() )
	std::string fmt() const { return m_fmt; };


	//! a helper function to discard whitespaces in label
	//! @param name  an original name
	//! @return string with words separated by one space
	//! @warning Should be called in constructor.
	virtual std::string  rename( std::string name );

	//! a helper function to discard widths and precisions in format
	//! @param fmt an original format
	//! @return a formatted string as in scanf() and printf() functions
	//! but without width and precision fields
	//! @warning No integrity check at this level! The format specification
	//!  can differ from type of variables!!! 
	virtual std::string reformat( std::string fmt );


 protected:
	
	//! a name of command (aka label)
	std::string m_name;

	//! a format
	std::string m_fmt;
		
	//! flag of local var set 
	bool m_local_flag;

	//! flag of global var set
	bool m_global_flag;

};



/// include typedefs
#include "GenCommandBase_typedefs.h"


#endif // GENCOMMANDBASE_H
