TARGET_EXEC ?= dicosto_test

BUILD_DIR ?= ./build
DEST_DIR ?= ./bin
SRC_DIRS ?= ./prog/src ./test/src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS)) -I./prog/include -I./test/include -I./vendor/Catch2/single_include -I./vendor/plog/include

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -g3 -gdwarf-2 -Debug

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
	mkdir -p $(DEST_DIR)
	cp $(BUILD_DIR)/$(TARGET_EXEC) $(DEST_DIR)/$(TARGET_EXEC)

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) -r $(DEST_DIR)
	$(RM) $(shell find -name *.log)

-include $(DEPS)

MKDIR_P ?= mkdir -p
