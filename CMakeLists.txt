cmake_minimum_required(VERSION 2.8.4)
project(cpp)

# CMake FindThreads is broken until 3.1
#find_package(Threads REQUIRED)
set(CMAKE_THREAD_LIBS_INIT pthread)

set(CMAKE_CXX_STANDARD 17)


set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)
set(gtest_SOURCE_DIR ${EXT_PROJECTS_DIR}/googletest/googletest)


enable_testing()
include_directories(${gtest_SOURCE_DIR}/include)


set(WHITE_BEAR_SOURCE_FILES
        WhiteBear.cc
        WhiteBear.h
		#IItem.h
        #NormalItem.h
        #CheeseItem.h
        #LegolasItem.h
        #ConcertTicketItem.h
        )

set(WHITE_BEAR_UNIT_TESTS_SOURCE_FILES
        ${WHITE_BEAR_SOURCE_FILES}
        WhiteBearUnitTests.cc)

#set(SOURCE_FILES
#        ${WHITE_BEAR_SOURCE_FILES}
#        ${WHITE_BEAR_TEXT_TESTS_SOURCE_FILES})

add_subdirectory(${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR}/bin EXCLUDE_FROM_ALL)
add_executable(WhiteBear ${WHITE_BEAR_SOURCE_FILES} WhiteBearMain.cc)

#target_link_libraries(WhiteBear gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(WhiteBear gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(WhiteBear gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(WhiteBear gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(WhiteBear gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(WhiteBear gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(WhiteBear gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})

add_executable(WhiteBearUnitTests ${WHITE_BEAR_UNIT_TESTS_SOURCE_FILES})
target_link_libraries(WhiteBearUnitTests gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})



#set(WHITE_BEAR_CHARACTERIZATION_TESTS_SOURCE_FILES
#        ${WHITE_BEAR_SOURCE_FILES}
#        WhiteBearCharacterizationTests.cc)

#set(SOURCE_FILES
#        ${ABC_SOURCE_FILES}
#        ${CDE_TEXT_TESTS_SOURCE_FILES})



#add_executable(WhiteBearCharacterizationTests ${WHITE_BEAR_CHARACTERIZATION_TESTS_SOURCE_FILES})
#target_link_libraries(WhiteBearCharacterizationTests gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
