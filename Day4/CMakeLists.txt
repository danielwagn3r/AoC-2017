cmake_minimum_required (VERSION 3.0)

project(HighEntropyPhasphases)

find_package(Boost 1.66.0 REQUIRED COMPONENTS container filesystem program_options)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(hepassphrases hepassphrases.cc abstract_part.cc part_one.cc part_two.cc)
  target_link_libraries(hepassphrases ${Boost_LIBRARIES})
endif()
