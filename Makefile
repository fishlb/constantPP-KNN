# 输出目录
BUILD_DIR = build

# 编译器设置
CC = g++
CFLAGS = -fomit-frame-pointer -maes -std=c++11 -msse4.2 -fno-strict-aliasing -pedantic -Wall -Wextra -Wunreachable-code -Wmissing-declarations -Wunused-function -Wno-overlength-strings -Wno-deprecated-declarations -O3
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -Wl,-Bstatic -lcrypto -Wl,-Bdynamic -ldl -lssl -lgmpxx -lgmp -lpthread

# 源文件路径
SOURCES = fss-client.cpp fss-server.cpp fss-common.cpp fss-test.cpp
OBJECTS = $(addprefix $(BUILD_DIR)/,$(SOURCES:.cpp=.o))
EXECUTABLE = $(BUILD_DIR)/fss-test
LIB = $(BUILD_DIR)/libfss.a

# 检查是否需要启用AESNI
ifeq ($(AESNI), 1)
    CFLAGS += -DAESNI
endif

all: $(SOURCES) $(EXECUTABLE) $(LIB)

$(EXECUTABLE): $(OBJECTS)
    $(CC) -o $@ $^ $(LDFLAGS)

$(LIB): $(BUILD_DIR)/fss-client.o $(BUILD_DIR)/fss-server.o $(BUILD_DIR)/fss-common.o
    ar rcs $@ $^

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
    $(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
    mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	rm -f *.o $(LIB) $(OBJECTS) $(EXECUTABLE)

.PHONY: install
install: 
    mkdir -p $(DESTDIR)$(PREFIX)/lib
    mkdir -p $(DESTDIR)$(PREFIX)/include
    cp $(LIB) $(DESTDIR)$(PREFIX)/lib/$(LIB)
    cp *.h $(DESTDIR)$(PREFIX)/include/
