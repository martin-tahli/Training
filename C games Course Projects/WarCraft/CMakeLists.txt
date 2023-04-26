cmake_minimum_required(VERSION 3.5.1)

include(cmake_helpers/helpers_c.cmake)

project(warcraft)

set(INC_DIR include)
set(SRC_DIR src)
     
#generate project binary
add_executable(
    ${PROJECT_NAME}
        ${INC_DIR}/Defines.h
        ${INC_DIR}/Vector.h
        ${INC_DIR}/ClassHero.h
        ${INC_DIR}/ErrorHandler.h
        ${INC_DIR}/Utilities.h

        ${INC_DIR}/BattleField.h
        ${INC_DIR}/BattleProcessor.h
        ${INC_DIR}/CheckInput.h

        # HUMAN RACE
        ${INC_DIR}/HumanRace/HumanRaceDefines.h
        ${INC_DIR}/HumanRace/ClassPaladin.h
        ${INC_DIR}/HumanRace/ClassArchMage.h
        # UNDEAD RACE
        ${INC_DIR}/UndeadRace/UndeadRaceDefines.h
        ${INC_DIR}/UndeadRace/ClassDeathKnight.h
        ${INC_DIR}/UndeadRace/ClassDrawRanger.h

        ########## SOURCE FILES ##########
        ${SRC_DIR}/main.c
        ${SRC_DIR}/Vector.c
        ${SRC_DIR}/ClassHero.c
        ${SRC_DIR}/BattleField.c
        ${SRC_DIR}/BattleProcessor.c
        ${SRC_DIR}/CheckInput.c
        ${SRC_DIR}/ErrorHandler.c
        ${SRC_DIR}/Utilities.c

        # HUMAN RACE
        ${SRC_DIR}/HumanRace/ClassPaladin.c
        ${SRC_DIR}/HumanRace/ClassArchMage.c

        # UNDEAD RACE
        ${SRC_DIR}/UndeadRace/ClassDrawRanger.c
        ${SRC_DIR}/UndeadRace/ClassDeathKnight.c
        )

target_include_directories(
    ${PROJECT_NAME} 
        PRIVATE 
            ${INC_DIR}
)  

set_target_c_standard(${PROJECT_NAME} 11)
enable_target_c_warnings(${PROJECT_NAME})
