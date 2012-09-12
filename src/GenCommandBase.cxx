/**
 * @file 
 * @brief GenCommandBase class definition.
 * @author Krzysztof Ciba (Krzysztof.Ciba@NOSPAMagh.edu.pl)
 * @date Oct 24th, 2006 
 */


#include "GenCommandBase.h"


std::string GenCommandBase::rename( std::string name ) {

	std::string new_name;
	std::stringstream inout;
	std::string word;
	inout << name;
	inout >> new_name;
	while ( inout >> word ) new_name += " " + word; 

	std::cout << " old name =" << name << std::endl; 
	std::cout << " new name =" << new_name << std::endl;  
	return new_name;
}

std::string GenCommandBase::reformat(std::string fmt) {

	std::string new_fmt;

	std::string good("%siolf \t");

	if (  ! fmt.empty() ) {
		
		if ( fmt.find_first_not_of(good) != std::string::npos )  {
	
			std::vector < std::string > fmt_str;
		
			fmt_str.push_back(  std::string("s" ) ); 
			fmt_str.push_back(  std::string("i" ) );  
			fmt_str.push_back(	std::string("o" ) );  
			fmt_str.push_back(  std::string("lf") ); 	
			fmt_str.push_back(	std::string("f" ) );

			std::string ff_start("%");

			std::stringstream inout;
			// load original format into stringstream
			inout << fmt;
		
			std::string piece;
			// read piece word by word
			while( inout >> piece ) {

				// find the beginning %
				std::string::size_type start = piece.find( ff_start ) + ff_start.size();
				
				// loop over ending chars
				std::vector< std::string >::iterator it_fmt;			
				bool found = false;
				for( it_fmt = fmt_str.begin(); 
						 it_fmt != fmt_str.end(); 
						 it_fmt++ ) {
					if ( ! found ) {
						std::string::size_type end = 0;
						// find format field end
						end = piece.rfind( (*it_fmt) );
						if ( end != std::string::npos ) {
							// ok, serach completed, load new format field to returned format
							new_fmt += (ff_start + (*it_fmt) + " ");
							found = true;
						} // if ( end != 0 ) ...
					} // if ( ! found ) ...
				} // for ( it_fmt = ...) 
			} // while ( inout >> ) ...
		} // if ( fmt.find_firts_not...
		else new_fmt = fmt;
	} // if ( ! fmt.empty() ) ...
	return new_fmt;
}

