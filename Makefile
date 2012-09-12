
CXX=g++
COMP=-c -O2 -frtti -fpermissive
FCOMP=-c -O2

MYNAME="KrzysztofCiba"
PROJ_NAME=`basename  ${PWD} /`
DATE=`date +%d%m%y`
ZIP_NAME=${PROJ_NAME}_${MYNAME}_${DATE}

SRC=./src/StringParse.cxx ./src/StringParse.h ./src/Generator_i.cxx ./src/Generator_i.h ./src/GenCommandBase.cxx
TEST=./bin/testGenerator_i

work_dir=`pwd`
obj_dir=${work_dir}/obj

all: test

default: all

./obj/common.o: ./src/common.F ./src/common.inc
	gfortran $(FCOMP) ./src/common.F -o ./obj/common.o

./obj/StringParse.o: ./src/StringParse.cxx  ./src/StringParse.h
	g++ $(COMP) ./src/StringParse.cxx -o ./obj/StringParse.o

./obj/GenCommandBase.o: ./src/GenCommandBase.h ./src/GenCommandBase.cxx
	g++ $(COMP) ./src/GenCommandBase.cxx -o ./obj/GenCommandBase.o

./obj/Generator_i.o: ./src/Generator_i.cxx  ./src/Generator_i.h
	g++ $(COMP) ./src/Generator_i.cxx -o ./obj/Generator_i.o  

test: ./obj/common.o ./obj/StringParse.o ./obj/Generator_i.o ./obj/GenCommandBase.o ./src/testGenerator_i.cxx
	g++ -lgfortran -frtti -O2 ./src/testGenerator_i.cxx ./obj/GenCommandBase.o \
	./obj/Generator_i.o ./obj/StringParse.o ./obj/common.o   -o ${TEST}

doc: $(SRC)
	doxygen 

tar: 
	@echo creating tarball  ../${ZIP_NAME}
	cd .. && tar chf - ${PROJ_NAME} | gzip -f9 > ${ZIP_NAME}.tar.gz
	@echo ../${ZIP_NAME}.tar.gz created


clean:
	rm -Rf ./obj/*.o
	rm -Rf ./doc/html/*.*
	rm -Rf ./bin/*.*
