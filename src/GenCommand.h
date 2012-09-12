/**
 * @file GenCommand.h
 * @brief A GenCommand template definition.
 * @author Krzysztof Ciba (Krzysztof.Ciba@NOSPAMagh.edu.pl)
 * @date Sept 27, 2006
 */

#ifndef GENCOMMAND_H
#define GENCOMMAND_H

// from standard libraries
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <complex>
#include <map>
#include <typeinfo>
#include <string.h>
#include <cstddef>

//#include <unistd.h>

#include "GenCommandBase.h"
#include "StringParse.h"


///////////////////////////////////////////////////////////////////////
//
//  GenCommand<T1, T2> non-specialised 
//                     declaration and definition  
//
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
/**
 * @class GenCommand 
 * @author Krzysztof Ciba (Krzysztof.Ciba@NOSPAMagh.edu.pl)
 * @date Sept 27th, 2006
 * 
 * @brief A template that generates a class, that holds pointers
 * to the local (i.e. member of another class) and/or global
 * (i.e. member of global common) variables.
 *
 * Notice, that the objects created by the template only bind
 * together two different memory adresses, that is. Your class should
 * provide a local member of desired type, and you also should provide
 * somehow an access to the global variable (i.e. a member of external 
 * common from Fortran code). 
 * 
 * Variables could have a different types, but to avoid any 
 * complications, please use objects defined in typedef statments.
 * The integrity of datas are suppose to be checked on higher level 
 * (i.e. in std::map definitions). This feature could be dangerous, 
 * and then probably will be deprecated in future versions. 
 * 
 * It is only an approximation. The simple objects (double, float, int etc.)
 * are glued together, but I have no idea how to glue tables. 
 *
 * One possible solution is to bind together only intresting places of
 * matrices, using defined interface, which is high enough efficient
 * for small tables (a few elements). Binding together bigger tables 
 * will be anyway painfull, because you have to provide an unwinded 
 * code... 
 *
 * Notice also, that there is no way to bind global variable to the 
 * functions (e.g. setters and getters from another objects), works are 
 * under way, but it requires a lot of coding. Any idea are welcome.
 *
 * I also try to provide more integrity with StringParse objects, i.e. 
 * a new std::string member "format" (which should looks like old-fashioned 
 * but very good and fast printf and scanf functions). This would help
 * to read from stringstream desired values with exact required types. 
 *
 *<p>
 * <b>The format of format :)</b><br>
 * The format itself should be a subset of format from old C read/write
 * functions scanf() and printf():<br>
 * <b>"%s"</b>&nbsp;["%s", "%f", "%i", ...]<br>
 * where:
 * <ul>
 * <li> "%s" is obligatory parameter, which forces the StringParse object
 * to read a name of command
 * <li> others format flags (from which at least is obligatory), indicate 
 * to read:
 *  <ul>
 *    <li> "%i"  - a signed integer value
 *    <li> "%o"  - an unsigned integer value
 *    <li> "%s"  - a table of chars (global) or std::string (local)
 *    <li> "%lf" - a floating point (type: double)
 *    <li> "%f"  - a floating point (type: float)
 *  </ul>
 *</ul> </p>
 * <p>
 * <b>Fixing the format fields</b><br>
 * <i>Your code NEVER and EVER should fix in the format
 * a width or precision of fields to read.</i>  Any format fields that 
 * specify the width or precision will be internally reformatted (i.e.
 * "%8.4f" to "%f"), but I do not guarantee that result will be exact. </p>
 *
 * @warning Using of local or/and global/setters and getters is NOT implemented yet.
 */

template <typename T1, typename T2>
class GenCommand : public GenCommandBase {

 public:

	/** 
	 * a constructor with global and local variable
	 * @param name - a name of command
	 * @param local - a reference to local (i.e. memeber of class) variable
	 * @param global - a reference to global (i.e. member of common) variable 
	 * @param fmt - a string with format
	 */
	GenCommand(std::string name, T1* local, T2* global, std::string fmt) {

		m_name = rename( name );
		m_fmt = reformat( fmt );

		m_local_val = local;
		m_global_val = global;
		
		// set the flags
		m_local_flag = true;
		m_global_flag = true;

	}

	/**
	 * a constructor with only local variable
	 * @param name   a command name
	 * @param val    a reference to local variable
	 * @param fmt a string with  format
	 */
	GenCommand(std::string name, T1 & val, std::string fmt) {
		
		m_name = rename( name );
		m_fmt = reformat(fmt);
		m_local_val = val;
		
		// set the flags
		m_local_flag  = true;
		m_global_flag = false;

	}


	//! local value getter
	T1 getLocal() { return *m_local_val; };
	
	//! global value getter
	T2 getGlobal() { return *m_global_val; };

	//! local value setter
	//! @param val a new value of local var
	void setLocal( const T1 & val ) { 
		if ( this->isLocal() ) (*m_local_val) = val; 
	};
	
	//! global var setter
	//! @param val a new value of global var
	void setGlobal( const T2 & val ) { 
		if ( this->isGlobal() ) (*m_global_val) = val; 
	};

	//! updates local AND global variables
	//! @param local a new value of local var
	//! @param global a new value of global var
	void update(const  T1 & local, const T2 & global ) {
		if ( this->isLocal()  ) (*m_local_val) = local;
		if ( this->isGlobal() ) (*m_global_val) = global;
	}

	//! synchronizes local and global values
	//! @param local2global if eq. true local value is copied to global value,
	//!                     vice versa otherwise, true by default    
	void synchronize( bool local2global = true );
	
	//! a command parser
	//! @param str a command string
	//! @return true if succeded, false otherwise
	bool parse( std::string str );

	/**
	 * does a  prinouts of object, for testing only, could be removed or
	 * redefined (to cope with MsgStream ?) 
	 * @param stream an output stream 
	 * @param gc an object to printout
	 * @return a reference to stream, as it should :)
	 */
	friend std::ostream& operator<<(std::ostream& stream, 
																	GenCommand<T1, T2> & gc) {
		stream << " name = " << gc.name();
		if ( gc.local() ) stream << " local = " << gc.getLocal();
		if ( gc.global() ) stream << " global = " << gc.getGlobal();
		return stream;
	}


 private:

	//! a local (i.e. member of class)
	T1* m_local_val;

	//! a global (i.e. member of external common block)
	T2* m_global_val;
	
};


template <typename T1, typename T2>
void GenCommand<T1, T2>::synchronize( bool local2global ) {
	if ( isGlobal() && isLocal() ) {
		if ( local2global ) {
			(*m_global_val) = (T2)(*m_local_val);
		} else {
			(*m_local_val) = (T1)(*m_global_val);
		}
	} 
}

template <typename T1, typename T2>	
bool GenCommand<T1, T2>::parse(std::string str) {

	StringParse parser(str);
	std::vector< std::string >  fmt_vec; 
	std::vector< std::string >::iterator it;
	std::stringstream inout;

	std::string word;
	
	inout << fmt();
	while ( inout >> word ) fmt_vec.push_back( word );

	int i = 0;
	bool OK = false;
	for( i ; i < fmt_vec.size()-1; ++i ) {
		if ( i == fmt_vec.size()-2 ) {
			T1 val;
			OK = parser.getVal( val );
			if ( OK ) {
				setLocal(val);
			} else {
				std::cout << parser.what() << std::endl;
			}
		} else {
			OK = parser.getVal( word );
		}
	}
	return OK;
}


///////////////////////////////////////////////////////////////////////
//
//  GenCommand<std::string, char*> specialised template
//                                 declaration and definition  
//
///////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
/**
 * @class GenCommand< std::string, char*>
 * @author Krzysztof Ciba (Krzysztof.Ciba@NOSPAMagh.edu.pl)
 * @date Sept 27, 2006
 *
 * @brief A specialized template for char* and std::string types.
 * 
 * Notice, that your local variable should always be of type std::string, 
 * while the global one of type char*. 
 *
 * Interface is stictly the same as in generic GenCommand template plus
 * additional functionality to cope with the lenght of char* variable.
 *
 * The lenght of global char* is counted during the object creation, so 
 * you'd never change it by calling setLen(), unless you know 
 * what you are doing. It could ba highly dangerous, you could overwrite
 * other variables in Fortran common blocks!
 * 
 */
template<>
class GenCommand< std::string, char*> : public GenCommandBase {

 public:

	/**
	 * a constructor with global and local variable
	 * @param name - a name of command
	 * @param local - a reference to local (i.e. memeber of class) variable
	 * @param global - a reference ro global (i.e. member of common) variable 
	 * @param fmt - at the moment "%s %s" (which is default), you'd better don't touch this (i.e. use default)
	 */
	GenCommand(std::string name, 
						 std::string &local, 
						 char* global, 
						 std::string fmt = "%s %s") {

		m_name = rename ( name );
		m_fmt = reformat( fmt ) ;

		m_local_val = &local;
		m_global_val = global;

		m_len = 0;
		char ch;
		while ( ch = global[++m_len]  );

		m_local_flag = true;
		m_global_flag = true;

	}

	/**
	 * a constructor with only local variable
	 * @param name   a command name
	 * @param val    a reference to local variable
	 * @param fmt    a format (default = "%s %s"), do not modify, always use dafult
	 * @warning Lenght of string is undefined, set to zero. This is not the problem, I suppose. 
	 */
	GenCommand(std::string name, 
						 std::string &val, 
						 std::string fmt = "%s %s") {

		m_name = rename( name );
		m_fmt = reformat( fmt );
		m_local_val = &val;
		m_local_flag = true;
		m_global_flag = false;
		m_len = 0;

	}

	//! local value getter
	std::string getLocal( ) { return (*m_local_val); };
	
	//! global value getter
	char* getGlobal() { return m_global_val; };

	//! local value setter
	//! @param val a new value of local var
	void setLocal( const std::string & val ) { 
		if ( this->isLocal() ) m_local_val->assign( val.c_str(), val.length()); 
	};

	/**
	 * sets the lenght of global char*
	 * do not touch unless you know, what UR doing
	 * notice, that initially lenght of global char* is 
	 * set in the constructor 
	 * @param len a lenght of global char* value
	 */
	void setLen( const size_t len ) {  m_len = len; };

	//! global var setter
	//! @param val a new value of global var
	void setGlobal( const char*  val ) { 
		if ( this->isGlobal() ) strncpy(m_global_val, val, m_len);
	};

	//! updates local and global values
	//! @param local a new value of local var
	//! @param global a new value of global var
	void update(const  std::string & local, const char* global ) {
		if ( this->isLocal()  ) m_local_val->assign(local.c_str(), local.length());
		if ( this->isGlobal() ) strncpy(m_global_val, global, m_len);
	}

	//! synchronizes local and global values
	//! @param local2global if eq. true local value is copied to global value,
	//!                     vice versa otherwise, true by default    
	void synchronize( bool local2global = true )  {
		if ( isGlobal() && isLocal() ) {
			if ( local2global ) {
				strncpy(m_global_val, m_local_val->c_str(), m_len);
			} else {
				std::string copy = m_global_val ;
				m_local_val->assign(copy.c_str(), copy.length()) ;
			}
		} 
	}



	//! global variable lenght getter
	size_t len() const { return m_len; };

	//! string parser
	//! @param str  a command string
	//! @return true is succeded, false otherwise
	bool parse( std::string str ) {

		StringParse parser(str);
		std::vector< std::string > fmt_vec; 
		std::vector< std::string >::iterator it;
		std::stringstream inout;
		
		std::string word;
		
		inout << fmt();
		while ( inout >> word ) fmt_vec.push_back( word );

		int i = 0;
		bool OK = false;
		for( i ; i < fmt_vec.size()-1; ++i ) {
			if ( i == fmt_vec.size()-2 ) {
				std::string val;	
				OK = parser.getVal( val );
				if ( OK ) {
					setLocal(val);
				} else {
					std::cout << parser.what() << std::endl;
				}
			} else {
				OK = parser.getVal( word );
			}
		}
		return OK;
	}

	/**
	 * does a  prinouts of object, for testing only, could be removed or
	 * redefined (to cope with MsgStream ?) 
	 * @param stream an output stream 
	 * @param gc an object to printout
	 * @return a reference to stream, as it should :)
	 */
	friend std::ostream& operator<<(std::ostream& stream, 
																	GenCommand<std::string, char*> & gc) {
		stream << " name = " << gc.name();
		if ( gc.local() ) stream << " local = " << gc.getLocal(); 
		if ( gc.global() ) { 
			stream << " global = " << gc.getGlobal() << " len =  " << gc.len(); 
		}
		return stream;
	}

 private:

	//! a local (i.e. member of class)
	std::string * m_local_val;

	//! a global (i.e. member of external common block)
	char* m_global_val;
	
	//! lenght of m_global_val
	size_t m_len;
	
};



///////////////////////////////////////////////////////////////////////
//
//
//                T Y P E D E F S
//
//
///////////////////////////////////////////////////////////////////////
#include "GenCommand_typedefs.h"

#endif // GENCOMMAND_H
