#
#  CMakeLists.txt: CMake configuration file for Project-Desert-Tortoise
#
#  Copyright (C) 2022 Ángel Ruiz Fernandez
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as
#  published by the Free Software Foundation, version 3.
#
#  This program is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public
#  License along with this program.  If not, see
#  <http://www.gnu.org/licenses/>
#
#

cmake_minimum_required(VERSION 3.5.1)

project(desert-tortoise)

# Directories
set(COMMONDIR common)
set(POESDIR POESTIPdemod)

# Files
set(COMMONSRC
    ${COMMONDIR}/AGC.c
    #${COMMONDIR}/ByteSync.c
    ${COMMONDIR}/CarrierTrackingPLL.c
    ${COMMONDIR}/GardenerClockRecovery.c
    ${COMMONDIR}/LowPassFilter.c
    ${COMMONDIR}/ManchesterDecode.c
    ${COMMONDIR}/MMClockRecovery.c
    ${COMMONDIR}/wave.c
)

set(COMMONHEADER
    ${COMMONDIR}/AGC.h
    #${COMMONDIR}/ByteSync.h
    ${COMMONDIR}/CarrierTrackPLL.h
    ${COMMONDIR}/GardenerClockRecovery.h
    ${COMMONDIR}/LowPassFilter.h
    ${COMMONDIR}/ManchesterDecode.h
    ${COMMONDIR}/MMClockRecovery.h
    ${COMMONDIR}/wave.h
)

set(POESSRC
    ${POESDIR}/ByteSync.c
    ${POESDIR}/main.c
)

set(POESHEADER
    ${POESDIR}/ByteSync.h
)

set(POESCONF ${POESDIR}/config.h)

# Flags
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING
       "Choose the type of build, options are: None Debug Release RelWithDebInfo
MinSizeRel."
       FORCE )
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3 -march=native")

# Executables
add_executable(demodPOES ${COMMONHEADER} ${COMMONSRC} ${POESHEADER} ${POESSRC})

# Install target
install(TARGETS demodPOES DESTINATION bin)
target_link_libraries(demodPOES m)