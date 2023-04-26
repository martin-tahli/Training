cmake_minimum_required(VERSION 3.5.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)

project(starcraft)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

#generate project binary
add_executable(
        ${PROJECT_NAME}
        ${INC_DIR}/Defines.h
        ${INC_DIR}/BattleField.h
        ${INC_DIR}/BATTLE.h
        ${INC_DIR}/Vector.h
        ${INC_DIR}/CheckInput.h
        ${INC_DIR}/Utility.h
        ${INC_DIR}/RaceUtilities.h
        ${INC_DIR}/ErrorHandler.h
        ${INC_DIR}/printWinnerTeamRace.h

        ${INC_DIR}/WarUnitsH/Phoenix.h
        ${INC_DIR}/WarUnitsH/Carrier.h
        ${INC_DIR}/WarUnitsH/Viking.h
        ${INC_DIR}/WarUnitsH/BattleCruser.h
        ${INC_DIR}/WarUnitsH/Mutalisk.h
        ${INC_DIR}/WarUnitsH/BroodLord.h

        ${INC_DIR}/UnitTypesStructuresH/BasicUnitType.h
        ${INC_DIR}/UnitTypesStructuresH/ProtossUnitType.h
        ${INC_DIR}/UnitTypesStructuresH/TerranUnitType.h
        ${INC_DIR}/UnitTypesStructuresH/ZergUnitType.h

        ${INC_DIR}/CurrentAttackingUnitsH/CurrentAttackingPhoenix.h
        ${INC_DIR}/CurrentAttackingUnitsH/CurrentAttackingCarrier.h
        ${INC_DIR}/CurrentAttackingUnitsH/CurrentAttackingViking.h
        ${INC_DIR}/CurrentAttackingUnitsH/CurrentAttackingBattleCruiser.h
        ${INC_DIR}/CurrentAttackingUnitsH/CurrentAttackingMutalisk.h
        ${INC_DIR}/CurrentAttackingUnitsH/CurrentAttackingBroodLord.h

        ${INC_DIR}/FuncPointersForAttacksInvokeH/FunctionsPtrAttackingUnits.h
        ${INC_DIR}/FuncPointersForDefenceInvokeH/FunctionsPtrDamageReceiveUnits.h


        ${SRC_DIR}/main.c
        ${SRC_DIR}/Vector.c
        ${SRC_DIR}/Utility.c
        ${SRC_DIR}/BattleField.c
        ${SRC_DIR}/BATTLE.c
        ${SRC_DIR}/CheckInput.c
        ${SRC_DIR}/RaceUtilities.c
        ${SRC_DIR}/printWinnerTeamRace.c
        ${SRC_DIR}/ErrorHandler.c

        ${SRC_DIR}/WarUnitsC/Phoenix.c
        ${SRC_DIR}/WarUnitsC/Carrier.c
        ${SRC_DIR}/WarUnitsC/Viking.c
        ${SRC_DIR}/WarUnitsC/BattleCruser.c
        ${SRC_DIR}/WarUnitsC/Mutalisk.c
        ${SRC_DIR}/WarUnitsC/BroodLord.c


        ${SRC_DIR}/CurrentAttackingUnitsC/CurrentAttackingPhoenix.c
        ${SRC_DIR}/CurrentAttackingUnitsC/CurrentAttackingCarrier.c
        ${SRC_DIR}/CurrentAttackingUnitsC/CurrentAttackingViking.c
        ${SRC_DIR}/CurrentAttackingUnitsC/CurrentAttackingBattleCruiser.c
        ${SRC_DIR}/CurrentAttackingUnitsC/CurrentAttackingMutalisk.c
        ${SRC_DIR}/CurrentAttackingUnitsC/CurrentAttackingBroodLord.c

        ${SRC_DIR}/FuncPointersForAttacksInvokeC/FunctionsPtrAttackingUnits.c
        ${SRC_DIR}/FuncPointersForDefenceInvokeC/FunctionsPtrDamageReceiveUnits.c
        )


target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${INC_DIR}
)

set_target_c_standard(${PROJECT_NAME} 11)
enable_target_c_warnings(${PROJECT_NAME})
