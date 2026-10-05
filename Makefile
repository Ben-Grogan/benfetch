SRC = src/benfetch.cpp src/modules/os.cpp src/modules/kernel.cpp src/modules/ram.cpp src/modules/gpu.cpp src/modules/user.cpp src/modules/cpu.cpp

benfetch: $(SRC)
	g++ -o benfetch $(SRC) -lpci

clean:
	rm -f benfetch