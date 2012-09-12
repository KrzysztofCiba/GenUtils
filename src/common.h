/**
 * @file 
 * @brief Fortran77 common to C++ wrapper.
 */

#ifndef COMMON_H
#define COMMON_H

//! Extern Fortran77 functions
extern "C" {
	//! common init
	void   init_();
	//! common printout
	void   writeout_();
	//! common modification
	void   modify_();
}

/**
 * @class global_ 
 * @author Krzysztof Ciba Krzysztof.Ciba@NOSPAMagh.edu.pl 
 *
 * @brief Fortran77 common to C++ wrapper.
 *    
 *   here is definition of common from Fortran77 code (from file common.inc)
 *   <pre>
 *    DOUBLE PRECISION D1, D2, DTAB(5)
 *    INTEGER I1, I2, ITAB(5)
 *    CHARACTER*14  ROCKSTAR
 *    COMMON /GLOBAL/ D1, D2, DTAB, I1, I2, ITAB, ROCKSTAR
 *   </pre>
 *
 * Here are also bodies of:
 * <ul>
 * <li> F77 INIT 
 * <pre>
 *     SUBROUTINE INIT
 *     include 'common.inc'
 *     INTEGER I
 *     WRITE (*,*) " *** JUMP INSIDE INIT SUBROUTINE ***"
 *     D1 = 1234.0D0
 *     D2 = 4321.0D0    
 *     I1 = -1
 *     I2 = 1
 *     ROCKSTAR = 'PorcupineTree'
 *     DO I=1, 5, 1
 *       ITAB(I) = I
 *       DTAB(I) = I * I
 *     ENDDO
 *     WRITE (*,*) " *** QUIT FORM INIT SUBROUTINE   ***"
 *     RETURN
 *     END
 *  </pre>
 * <li> F77 WRITEOUT
 * <pre>
 *     SUBROUTINE WRITEOUT
 *     INCLUDE 'common.inc'
 *     INTEGER I
 *     WRITE (*,*) " *** JUMP INSIDE WRITEOUT SUBROUTINE ***"
 *     WRITE (*,*) "       /GLOBAL/ common variables are"
 *     WRITE (*,*) " I1        = ", I1
 *     WRITE (*,*) " I2        = ", I2
 *     WRITE (*,*) " D1        = ", D1
 *     WRITE (*,*) " D2        = ", D2
 *     WRITE (*,*) " ROCKSTAR  = ", ROCKSTAR
 *     DO i=1,5,1
 *       WRITE (*,*) ' ITAB(',I,')  = ', ITAB(I)
 *     ENDDO
 *     DO i=1,5,1
 *       WRITE (*,*) ' DTAB(',I,')  = ', DTAB(I)
 *     ENDDO
 *     WRITE (*,*) " *** QUIT FROM WRITEOUT SUBROUTINE   ***"
 *     RETURN
 *     END
 * </pre>
 * <li> F77 MODIFY
 * <pre>
 *     SUBROUTINE MODIFY
 *     INCLUDE 'common.inc'
 *     INTEGER I
 *     WRITE (*,*) " *** JUMP INSIDE MODIFY SUBROUTINE ***"
 *     D1 = 0.5D0 * D1 
 *     D2 = 0.5D0 * D2
 *     I1 = I1 + 1
 *     I2 = I2 - 1     
 *     ROCKSTAR = "Camel"
 *     DO I=1,5,1
 *       ITAB(I) = 100 - I
 *       DTAB(I) = I * D1 / D2 
 *     ENDDO
 *     WRITE (*,*) " *** QUIT FROM MODIFY SUBROUTINE   ***"
 *     RETURN
 *     END
 *  </pre>
 * </ul>
 *
 */
extern "C" {
 	extern struct {
		//! dummy double
		double d1;
		//! dummy double
		double d2;
		//! dummy double table
		double dtab[5];
		//! dummy int
		int i1;
		//! dummy int
		int i2;
		//! dummy int table
		int itab[5];	
		//! dummy char table
		char rockstar[14];
	} global_;
}

#endif // COMMON_H
