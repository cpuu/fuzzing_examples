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

## afl-gcc(cov)
```
afl-gcc -c -o aql-parser.o_cov aql-parser.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -c -o lvm.o_cov lvm.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -c -o aql-adt.o_cov aql-adt.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -c -o test_aql.o_cov test_aql.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -c -o aql-lexer.o_cov aql-lexer.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -o test_aql_cov.exe aql-parser.o_cov lvm.o_cov aql-adt.o_cov test_aql.o_cov aql-lexer.o_cov  -fprofile-arcs
```
