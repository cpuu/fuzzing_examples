$ afl-gcc -o vuln vuln.c

$ mkdir findings_dir

$ afl-fuzz -i seeds/ -o findings_dir/ ./vuln @@

$ AFL_SKIP_CPUFREQ=1 AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 afl-fuzz -i seeds/ -o findings_dir/ ./vuln @@
