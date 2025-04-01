CC = g++
CFLAGS = -Wall -std=c++17  # Common flags
SOURCES = match_words.cpp # List your source files
TARGET_RELEASE = match_words_release
TARGET_DEBUG = match_words__debug

all: $(TARGET_RELEASE) $(TARGET_DEBUG)

$(TARGET_RELEASE): $(SOURCES)
	$(CC) $(CFLAGS) -O3 -s -o $@ $^

$(TARGET_DEBUG): $(SOURCES)
	$(CC) $(CFLAGS) -g -o $@ $^

clean:
	rm -f $(TARGET_RELEASE) $(TARGET_DEBUG)