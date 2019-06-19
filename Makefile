
CXX = g++
CXXFLAGS = -g -w -Wformat

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src


SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

TARGET_EXEC ?= sake

INCLUDES = -I/usr/local/include 
LIBRARIES = -L/usr/local/lib -L/usr/local/include -lGLEW -lglfw -DIMGUI_IMPL_OPENGL_LOADER_GLEW -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo


INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INCLUDES) $(LIBRARIES)


$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(CPPFLAGS)
	@echo ------------------Build Complete--------------------

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean: 
	rm -rf build/src/*.o
	rm -rf build/src/imgui/*.o
	rm sake

-include $(DEPS)

MKDIR_P ?= mkdir -p









