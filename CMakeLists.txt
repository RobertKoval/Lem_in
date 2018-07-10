cmake_minimum_required(VERSION 3.9)
project(Leminv3 C)

set(CMAKE_C_STANDARD 11)

add_executable(Leminv3 src/main.c src/read_input.c src/utillity.c
        src/manage_ants.c src/queue/add_queue.c src/queue/remove_queue.c src/validate_values.c
        src/save_values.c src/graph/add_vertex.c src/algorithm.c src/move_ants.c
        src/graph/remove_graph.c)

target_link_libraries(Leminv3 ${CMAKE_SOURCE_DIR}/libft/libft.a)