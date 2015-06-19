CC = g++

PRGGRAM_NAME = \
	 bin/Project1

CXXFLAGS = \
	 -MMD \
	 -Wall \
	 -Wno-deprecated \
	 -g \
	 -std=c++11 \

LDLIBS = \
	-lGL -lGLU -lglfw -lGLEW \

INCLUDE_PATH= \
	 /usr/include/ \
	 ./precomp/ \
	 ./src/ \
	 ./src/lib_linux/ \
	 ./src/source/ \
	 ./ \

INCLUDE_PATH := $(addprefix -I,$(INCLUDE_PATH))

INCLUDE= \
	 ./src/lib_linux/lib_linux.h \

INCLUDE := $(addprefix -include ,$(INCLUDE))

# Files

SRCDIR += \
	 ./src \
	 ./src/source/class/window \
	 ./src/source/class/camera \
	 ./src/source/class/draw \
	 ./src/source/class/model \
	 ./src/source/class/model/cube \
	 ./src/source/class/model/obj \
	 ./src/source/class/buffer \
	 ./src/source/class/buffer/frameBuffer \
	 ./src/source/class/uniform/ \
	 ./src/source/class/texture \
	 ./src/source/class/texture/texture2D \
	 ./src/source/class/shader \
	 ./src/source/class/shader/shader2D \
	 ./src/source/class/light \
	 ./src/source/class/tim \
	 ./src/source/class/tim/math \
	 ./src/source/class/tim/string \
	 ./src/source/class/input \
	 ./src/source/class/input/mouse \
	 ./src/source/class/input/keyboard \
	 ./src/source/class/test \
	 ./src/source/headers/callback \

CPP_FILES = $(wildcard $(addsuffix /*.cpp,$(SRCDIR)))
HEADER_FILES = $(wildcard src/*.h)

OBJECTS = $(addprefix obj/,$(CPP_FILES:.cpp=.o))
PRECOMPILE_HEADER = $(addprefix precomp/,$(HEADER_FILES:.h=.h.gch))
DEPENDS = $(addsuffix .d,$(OBJECTS))

# Targets

all: $(PRGGRAM_NAME)

$(PRGGRAM_NAME) : $(OBJECTS)
	@echo "LD	$@"
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $(OBJECTS) $(LDLIBS) 

obj/%.o : %.cpp
	@echo "CC 	$<"
	@mkdir -p $(dir $@)
	@g++ $(CXXFLAGS) -MF $@.d $(INCLUDE_PATH) $(INCLUDE) -c -o $@ $<

precompile: $(PRECOMPILE_HEADER)

.PHONY: all clean precompile

clean:
	@echo "RM	$(PRECOMPILE_HEADER)"
	@rm -f $(PRECOMPILE_HEADER)
	@echo "RM	$(OBJECTS)"
	@rm -f $(OBJECTS) 
	@echo "RM	$(DEPENDS)"
	@rm -f $(DEPENDS)
	@echo "RM	$(PRGGRAM_NAME)"
	@rm -f $(PRGGRAM_NAME)

-include $(DEPENDS)
