/**
 * @file
 * @author Krzysztof Ciba (Krzysztof.Ciba@NOSPAMagh.edu.pl)
 * @brief Typedefs for various GenCommandBase and STL containers.
 */



#ifndef GENCOMMANDBASE_TYPEDEFS_H
#define GENCOMMANDBASE_TYPEDEFS_H

///////////////////////////////////////////////////////////////////
// shorthands for GenComBase 
///////////////////////////////////////////////////////////////////

//! a map with structure < std::string, GenComBase* >)  
typedef std::map< std::string, 
									GenCommandBase* > GenComPtrMap;

//! a iterator to GenComMap map
typedef std::map< std::string, 
									GenCommandBase* >::iterator  itGenComPtrMap;

//! a const iterator to GenComMap map
typedef std::map< std::string, 
									GenCommandBase* >::const_iterator  citGenComPtrMap;


#endif // GENCOMMANDBASE_TYPEDEFS_H
