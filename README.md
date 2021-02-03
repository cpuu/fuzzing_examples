# fuzzing_examples

## plain
```
gcc -c -o aql-parser.o_plain aql-parser.c -Wall -Wno-unused-variable  -DINPUT_STDIN 
gcc -c -o lvm.o_plain lvm.c -Wall -Wno-unused-variable  -DINPUT_STDIN 
gcc -c -o aql-adt.o_plain aql-adt.c -Wall -Wno-unused-variable  -DINPUT_STDIN 
gcc -c -o test_aql.o_plain test_aql.c -Wall -Wno-unused-variable  -DINPUT_STDIN 
gcc -c -o aql-lexer.o_plain aql-lexer.c -Wall -Wno-unused-variable  -DINPUT_STDIN 
gcc -o test_aql_plain.exe aql-parser.o_plain lvm.o_plain aql-adt.o_plain test_aql.o_plain aql-lexer.o_plain 
```

## afl-gcc
```
afl-gcc -c -o aql-parser.o_afl aql-parser.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -c -o lvm.o_afl lvm.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -c -o aql-adt.o_afl aql-adt.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -c -o test_aql.o_afl test_aql.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -c -o aql-lexer.o_afl aql-lexer.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -o test_aql_afl.exe aql-parser.o_afl lvm.o_afl aql-adt.o_afl test_aql.o_afl aql-lexer.o_afl  -fprofile-arcs
```

# Run
```
# afl-fuzz  -i testcase_dir_000 -o findings_dir_000  ./test_aql_afl.exe @@
```
