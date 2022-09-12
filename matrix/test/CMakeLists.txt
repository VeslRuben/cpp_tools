

add_executable(constructor_test constructor_test.cpp)
target_link_libraries(constructor_test matrix)
target_include_directories(constructor_test PUBLIC ../include)
add_test(NAME Constructor_test COMMAND constructor_test)

add_executable(equals_test equals_test.cpp)
target_link_libraries(equals_test matrix)
target_include_directories(equals_test PUBLIC ../include)
add_test(NAME Equals_test COMMAND equals_test)

add_executable(matrix_op_test matrix_op_test.cpp)
target_link_libraries(matrix_op_test matrix)
target_include_directories(matrix_op_test PUBLIC ../include)
add_test(NAME Matrix_op_test COMMAND matrix_op_test)

add_executable(scaler_op_test scaler_op_test.cpp)
target_link_libraries(scaler_op_test matrix)
target_include_directories(scaler_op_test PUBLIC ../include)
add_test(NAME Scaler_op_test COMMAND scaler_op_test)

add_executable(get_set_test get_set_test.cpp)
target_link_libraries(get_set_test matrix)
target_include_directories(scaler_op_test PUBLIC ../include)
add_test(NAME Get_set_test COMMAND get_set_test)