# Build C++ with opencv static library (opencv_world)
``` g++ <source> -I<include-path> -L<lib-path> -l<lib-name> -o <executable> ```  

Example: 
``` g++ hello.cpp -I/home/mehmet/c_projects/learn-opencv4/cpp_static_lib/include -L/home/mehmet/c_projects/learn-opencv4/cpp_static_lib/lib -lopencv_world -o hello ```  

# Build c++ program with system wide installed opencv4 library
``` g++ <source> `pkg-config --cflags --libs opencv4` -o <executable> ```

Example:
``` g++ hello.cpp `pkg-config --cflags --libs opencv4` -o hello_output ```
