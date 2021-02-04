# fuzzing_examples

## Requirement
```
$ su - root
# echo core >/proc/sys/kernel/core_pattern
# cd /sys/devices/system/cpu
# echo performance | tee cpu*/cpufreq/scaling_governor
```

## plain
Build
```
gcc -c -o aql-parser.o_plain aql-parser.c -Wall -Wno-unused-variable  -DINPUT_STDIN 
gcc -c -o lvm.o_plain lvm.c -Wall -Wno-unused-variable  -DINPUT_STDIN 
gcc -c -o aql-adt.o_plain aql-adt.c -Wall -Wno-unused-variable  -DINPUT_STDIN 
gcc -c -o test_aql.o_plain test_aql.c -Wall -Wno-unused-variable  -DINPUT_STDIN 
gcc -c -o aql-lexer.o_plain aql-lexer.c -Wall -Wno-unused-variable  -DINPUT_STDIN 
gcc -o test_aql_plain.exe aql-parser.o_plain lvm.o_plain aql-adt.o_plain test_aql.o_plain aql-lexer.o_plain 
```
Run
dumb mode
```
afl-fuzz -n -i testcase_dir -o findings_dir ./test_aql_plain.exe @@
```
qemu mode
```
afl-fuzz -m none -Q -i testcase_dir -o findings_dir ./test_aql_plain.exe @@
```
Clean
```
rm -rf ./findings_dir/
rm ./*.o_plain ./test_aql_plain.exe
```
## afl-gcc
Build
```
afl-gcc -c -o aql-parser.o_afl aql-parser.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -c -o lvm.o_afl lvm.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -c -o aql-adt.o_afl aql-adt.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -c -o test_aql.o_afl test_aql.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -c -o aql-lexer.o_afl aql-lexer.c -Wall -Wno-unused-variable  -fprofile-arcs -ftest-coverage
afl-gcc -o test_aql_afl.exe aql-parser.o_afl lvm.o_afl aql-adt.o_afl test_aql.o_afl aql-lexer.o_afl  -fprofile-arcs
```
Run
```
afl-fuzz -i testcase_dir -o findings_dir ./test_aql_afl.exe @@
```

Check
```
$ ./test_aql_afl.exe ./findings_dir/crashes/id\:000000\,sig\:06\,src\:000000\,op\:havoc\,rep\:64
-----------------------------
T▒▒▒▒▒▒T▒▒▒▒▒d▒▒▒▒▒3▒▒3
-------------------------
size of input data = 34
start parsing!!

JB patched : aql-lexer.c:243 next_token() : stack buffer overflow (next_token) : lexer->value >= DB_MAX_ELEMENT_SIZE

*** stack smashing detected ***: ./test_aql_afl.exe terminated
Aborted

```
Clean
```
rm -rf ./findings_dir/
rm ./*.o_afl* ./test_aql_afl.exe

```
## afl-gcc with Address Sanitizer
Build
```
AFL_USE_ASAN=1 afl-gcc -c -o aql-parser.o_asan aql-parser.c -Wall -Wno-unused-variable
AFL_USE_ASAN=1 afl-gcc -c -o lvm.o_asan lvm.c -Wall -Wno-unused-variable
AFL_USE_ASAN=1 afl-gcc -c -o aql-adt.o_asan aql-adt.c -Wall -Wno-unused-variable
AFL_USE_ASAN=1 afl-gcc -c -o test_aql.o_asan test_aql.c -Wall -Wno-unused-variable
AFL_USE_ASAN=1 afl-gcc -c -o aql-lexer.o_asan aql-lexer.c -Wall -Wno-unused-variable
AFL_USE_ASAN=1 afl-gcc -o test_aql_asan.exe aql-parser.o_asan lvm.o_asan aql-adt.o_asan test_aql.o_asan aql-lexer.o_asan
```
Run
```
afl-fuzz -m none -i testcase_dir -o findings_dir ./test_aql_asan.exe @@
```
Check
```
./test_aql_asan.exe ./findings_dir/crashes/id\:000000\,sig\:06\,src\:000000\,op\:havoc\,rep\:4
```
Clean
```
rm -rf ./findings_dir/
rm ./*.o_asan* ./test_aql_asan.exe
```
