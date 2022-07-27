# CMake generated Testfile for 
# Source directory: /home/johannes/test2/popl2020-artifact/prosynth/souffle/src/interpreter/tests
# Build directory: /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/interpreter/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(interpreter_relation "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/interpreter/tests/test_interpreter_relation")
set_tests_properties(interpreter_relation PROPERTIES  LABELS "unit_test;interpreter" _BACKTRACE_TRIPLES "/home/johannes/test2/popl2020-artifact/prosynth/souffle/cmake/SouffleTests.cmake;315;add_test;/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/interpreter/tests/CMakeLists.txt;9;souffle_add_binary_test;/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/interpreter/tests/CMakeLists.txt;0;")
add_test(ram_arithmetic "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/interpreter/tests/test_ram_arithmetic")
set_tests_properties(ram_arithmetic PROPERTIES  LABELS "unit_test;interpreter" _BACKTRACE_TRIPLES "/home/johannes/test2/popl2020-artifact/prosynth/souffle/cmake/SouffleTests.cmake;315;add_test;/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/interpreter/tests/CMakeLists.txt;10;souffle_add_binary_test;/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/interpreter/tests/CMakeLists.txt;0;")
add_test(ram_relation "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/interpreter/tests/test_ram_relation")
set_tests_properties(ram_relation PROPERTIES  LABELS "unit_test;interpreter" _BACKTRACE_TRIPLES "/home/johannes/test2/popl2020-artifact/prosynth/souffle/cmake/SouffleTests.cmake;315;add_test;/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/interpreter/tests/CMakeLists.txt;11;souffle_add_binary_test;/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/interpreter/tests/CMakeLists.txt;0;")
