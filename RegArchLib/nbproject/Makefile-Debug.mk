#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Sources/cAr.o \
	${OBJECTDIR}/Sources/cCondMean.o \
	${OBJECTDIR}/Sources/cConstM.o \
	${OBJECTDIR}/Sources/cNormResiduals.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libRegArchLib.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libRegArchLib.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libRegArchLib.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/Sources/cAr.o: Sources/cAr.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cAr.o Sources/cAr.cpp

${OBJECTDIR}/Sources/cCondMean.o: Sources/cCondMean.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cCondMean.o Sources/cCondMean.cpp

${OBJECTDIR}/Sources/cConstM.o: Sources/cConstM.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cConstM.o Sources/cConstM.cpp

${OBJECTDIR}/Sources/cNormResiduals.o: Sources/cNormResiduals.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cNormResiduals.o Sources/cNormResiduals.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libRegArchLib.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
