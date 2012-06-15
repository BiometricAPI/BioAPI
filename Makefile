all:
	g++ -I include src/*.cpp -fPIC -shared -o bioapi.so
