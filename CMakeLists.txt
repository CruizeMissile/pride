cmake_minimum_required(VERSION 3.8)
project(pride)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/external/scaffold")
include(scaffold)

sf_check_master_project(PRIDE_MASTER_PROJECT)
option(ENABLE_SAMPLES "Enable building and testing samples for pride" ${PRIDE_MASTER_PROJECT})
option(ENABLE_TESTING "Enable building and testing test for pride" ${PRIDE_MASTER_PROJECT})

option(ENABLE_BENCHMARKS "Enable building and testing benchmarks for pride" OFF)
option(ENABLE_CLANG_FORMAT "Enable formatting with clang-format" OFF)
option(ENABLE_CLANG_TIDY "Enable static analisys with cppcheck" OFF)
option(ENABLE_CPPCHECK "Enable static analisys with cppcheck" OFF)
option(ENABLE_CODECOV "Enable code coverage reports with codecov" OFF)

add_subdirectory(pride)

if (ENABLE_BENCHMARKS AND PRIDE_MASTER_PROJECT)
  add_subdirectory(benchmarks)
endif()

if (ENABLE_SAMPLES AND PRIDE_MASTER_PROJECT)
  add_subdirectory(samples)
endif()

if (ENABLE_TESTING AND PRIDE_MASTER_PROJECT AND NOT NO_TESTS)
  add_subdirectory(tests)
endif()

sf_setup_modules()

if(ENABLE_CLANG_FORMAT AND PRIDE_MASTER_PROJECT)
  include(clangformat)
  sf_clangformat_add_target(${PRIDE_LIB})
  sf_clangformat_create_command()
endif()

if(ENABLE_CLANG_TIDY AND PRIDE_MASTER_PROJECT)
  include(clangtidy)
  sf_clangtidy_add_target(${PRIDE_LIB})
  sf_clangtidy_create_command()
endif()

if(ENABLE_CPPCHECK AND PRIDE_MASTER_PROJECT)
  include(cppcheck)
  sf_cppcheck_add_target(${PRIDE_LIB} EXCLUDE_REGEX_LIST "cli" "fmt")
  sf_cppcheck_create_command(CHECKS warning,performance)
endif()

if(ENABLE_CODECOV AND PRIDE_MASTER_PROJECT)
  include(codecov)
endif()
