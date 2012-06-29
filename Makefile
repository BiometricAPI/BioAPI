CPP_FLAGS+= -fvisibility=hidden
CPP_FLAGS+= -fPIC 
CPP_FLAGS+= -I include 
CPP_FLAGS+= -D BIOAPI_MEM_DEBUG 
CPP_FLAGS+= -D BIOAPI_HANDLE_DEBUG

LIBNAME=bioapi.so
SRC      := $(wildcard src/*.cpp)
OBJ      := $(patsubst %.cpp,%.o,$(SRC))
PRECOMPILED_HEADER_SRC=src/common.h
PRECOMPILED_HEADER=$(PRECOMPILED_HEADER_SRC).gch

all: $(LIBNAME)
$(LIBNAME): $(OBJ)
	@echo ==== $< =========================================
	@g++ $(OBJ) $(CPP_FLAGS) -shared -o $@

$(PRECOMPILED_HEADER): $(PRECOMPILED_HEADER_SRC) src/*.h include/*.h
	@echo ==== $< =========================================
	@g++ -H $(PRECOMPILED_HEADER_SRC) $(CPP_FLAGS)

%.o: %.cpp $(PRECOMPILED_HEADER)
	@echo ==== $< =========================================
	@g++ $< $(CPP_FLAGS) -c -o $@