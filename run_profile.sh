clang++ -pg -O1 -std=c++17 -fno-rtti -stdlib=libc++ -Wall -o pocketpy src/main.cpp
time ./pocketpy benchmarks/fib.py
mv benchmarks/gmon.out .
gprof pocketpy gmon.out > gprof.txt
rm gmon.out
