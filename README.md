# wmodel-native

header generation
```
javac -h ./ ru/ifmo/onell/problem/WModelRunner.java
```

make sure the JAVA_HOME is set, in my case:
```
export JAVA_HOME=/usr/lib/jvm/default
```

Compile the lib (need to make adjustments when compiling libIOH)
```
g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux ru_ifmo_onell_problem_WModelRunner.cpp  -o wmodel.o -lIOH  
g++ -shared -fPIC -o libwmodel.so wmodel.o -lc -lIOH
```

Java needs to see the lib
```
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:%pathtoliblocation"  
