
      SUBROUTINE INIT

      include 'common.inc'
      INTEGER I

      WRITE (*,*) " *** JUMP INSIDE INIT SUBROUTINE ***"

      D1 = 1234.0D0
      D2 = 4321.0D0
      
      I1 = -1
      I2 = 1

      ROCKSTAR = 'PorcupineTree'

      DO I=1, 5, 1
         ITAB(I) = I
         DTAB(I) = I * I
      ENDDO

      WRITE (*,*) " *** QUIT FORM INIT SUBROUTINE   ***"

      RETURN
      END


      SUBROUTINE WRITEOUT

      INCLUDE 'common.inc'
      INTEGER I

      WRITE (*,*) " *** JUMP INSIDE WRITEOUT SUBROUTINE ***"
      WRITE (*,*) "       /GLOBAL/ common variables are"
      WRITE (*,*) " I1        = ", I1
      WRITE (*,*) " I2        = ", I2
      WRITE (*,*) " D1        = ", D1
      WRITE (*,*) " D2        = ", D2
      WRITE (*,*) " ROCKSTAR  = ", ROCKSTAR
      DO i=1,5,1
         WRITE (*,*) ' ITAB(',I,')  = ', ITAB(I)
      ENDDO
      DO i=1,5,1
         WRITE (*,*) ' DTAB(',I,')  = ', DTAB(I)
      ENDDO

      WRITE (*,*) " *** QUIT FROM WRITEOUT SUBROUTINE   ***"
      RETURN
      END

      SUBROUTINE MODIFY
      INCLUDE 'common.inc'
      INTEGER I

      WRITE (*,*) " *** JUMP INSIDE MODIFY SUBROUTINE ***"

      D1 = 0.5D0 * D1 
      D2 = 0.5D0 * D2
      
      I1 = I1 + 1
      I2 = I2 - 1
      
      ROCKSTAR = "Camel"

      DO I=1,5,1
         ITAB(I) = 100 - I
         DTAB(I) = I * D1 / D2 
      ENDDO
      WRITE (*,*) " *** QUIT FROM MODIFY SUBROUTINE   ***"
      RETURN
      END

