project(text)

target_sources(${LIB_NAME}
	PRIVATE
		text.hpp
		text.cpp
)

target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
