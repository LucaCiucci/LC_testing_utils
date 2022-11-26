#[[LC_NOTICE_BEGIN
LC_NOTICE_END]]

cmake_minimum_required(VERSION 3.20)

project(
	LC_testing_utils
	VERSION 0.0
	#LICENSE "MIT"
	DESCRIPTION "LC testing utils"
	LANGUAGES CXX
)

add_library(
	LC_testing_utils
)

set_property(TARGET LC_testing_utils PROPERTY CXX_STANDARD 20)

target_sources(
	LC_testing_utils
	PRIVATE
	"lib/src/tmp.cpp"
)

target_include_directories(
	LC_testing_utils
	PUBLIC
	"lib/include"
)



#find_package(LC_base_classes REQUIRED)
#target_link_libraries(LC_testing_utils PUBLIC LC::LC_base_classes)