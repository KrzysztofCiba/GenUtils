/**
 * @file
 * @author Krzysztof Ciba (Krzysztof.Ciba@NOSPAMagh.edu.pl)
 * @brief Typedefs for varoius GenCommand and STL containers.
 */


#ifndef GENCOMMAND_TYPEDEFS_H
#define GENCOMMAND_TYPEDEFS_H

#include <map>
#include <complex>
#include <string>


///////////////////////////////////////////////////////////////////////
//
//
//                T Y P E D E F S
//
//
///////////////////////////////////////////////////////////////////////


//! shorthand for GenCommand<double, double> 
typedef GenCommand< double, double > DoubleCmd;

//! shorthand for GenCommand<float, float> 
typedef GenCommand< float, float > FloatCmd;

//! shorthand for GenCommand<int, int> 
typedef GenCommand< int, int > IntCmd;

//! shorthand for GenCommand<std::complex<double>, std::complex<double> > 
typedef GenCommand< std::complex < double >, 
										std::complex < double > > ComplexCmd;

//! shorthand for GenCommand<bool, bool> 
typedef GenCommand< bool, 
										bool > BoolCmd;

//! shorthand for GenCommand<std:string, char*> 
typedef GenCommand< std::string, 
										char* > StringCmd;

//! shorthand for GenCommand<std:string, char*> 
typedef GenCommand< std::string, 
										char* > CharCmd;

///////////////////////////////////////////////////////////////////
// maps and iterators (const and non-const)
///////////////////////////////////////////////////////////////////

//! shorthand  for map<string, DoubleCmd*>
typedef std::map < std::string,  
									 GenCommand< double, 
															 double >* > DoubleCmdPtrMap;

//! shorthand  for map<string, FloatCmd*>
typedef std::map < std::string,  
									 GenCommand< float, 
															 float >* > FloatCmdPtrMap;

//! shorthand  for map<string, IntCmd*>
typedef std::map < std::string,  
									 GenCommand< int, 
															 int >* > IntCmdPtrMap;

//! shorthand  for map<string, ComplexCmd*>
typedef std::map < std::string,  
									 GenCommand< std::complex < double >, 
															 std::complex < double > >* > ComplexCmdPtrMap;

//! shorthand  for map<string, StringCmd*>
typedef std::map < std::string, 
									 GenCommand< std::string, 
															 char* >* > StringCmdPtrMap;

//! shorthand  for map<string, CharCmd*>
typedef std::map < std::string, 
									 GenCommand< std::string, 
															 char* >* > CharCmdPtrMap;

//! shorthand for DoubleCmdPtrMap::const_iterator
typedef std::map < std::string,  
									 GenCommand< double, 
															 double >* >::const_iterator citDoubleCmdPtrMap;

//! shorthand for DoubleCmdPtrMap::iterator
typedef std::map < std::string,  
									 GenCommand< double, 
															 double >* >::iterator itDoubleCmdPtrMap;

//! shorthand for FloatCmdPtrMap::const_iterator
typedef std::map < std::string,  
									 GenCommand< float, 
															 float >* >::const_iterator citFloatCmdPtrMap;

//! shorthand for FloatCmdPtrMap::iterator
typedef std::map < std::string,  
									 GenCommand< float, 
															 float >* >::iterator itFloatCmdPtrMap;

//! shorthand for IntCmdPtrMap::const_iterator
typedef std::map < std::string,  
									 GenCommand< int, 
															 int >* >::const_iterator citIntCmdPtrMap;
//! shorthand for IntCmdPtrMap::iterator
typedef std::map < std::string,  
									 GenCommand< int, 
															 int >* >::iterator itIntCmdPtrMap;

//! shorthand for ComplexCmdPtrMap::const_iterator
typedef std::map < std::string,  
									 GenCommand< std::complex < double >, 
															 std::complex < double > >* >::const_iterator citComplexCmdPtrMap;

//! shorthand for ComplexCmdPtrMap::iterator
typedef std::map < std::string,  
									 GenCommand< std::complex < double >, 
															 std::complex < double > >* >::iterator itComplexCmdPtrMap;

//! shorthand for StringCmdPtrMap::const_iterator
typedef std::map < std::string, 
									 GenCommand< std::string, 
															 char* >* >::const_iterator citStringCmdPtrMap;

//! shorthand for StringCmdPtrMap::iterator
typedef std::map < std::string, 
									 GenCommand< std::string, 
															 char* >* >::iterator itStringCmdPtrMap;

//! shorthand for CharCmdPtrMap::const_iterator
typedef std::map < std::string, 
									 GenCommand< std::string, 
															 char* >* >::const_iterator citCharCmdPtrMap;

//! shorthand for CharCmdPtrMap::iterator
typedef std::map < std::string, 
									 GenCommand< std::string, 
															 char* >* >::iterator itCharCmdPtrMap;




#endif // GENCOMMAND_TYPEDEFS_H
