CC = g++
CFLAGS = -Wall -std=c++17 # Common flags
LDFLAGS = -lmpfr -lgmp
SOURCES = lla_2_ecef.cpp geoNumber.cpp lla.cpp llaTrajectory.cpp utils.cpp ecef.cpp ecefTrajectoy.cpp # List your source files
TARGET_RELEASE = lla_2_ecef_release
TARGET_DEBUG = lla_2_ecef_debug

all: $(TARGET_RELEASE) $(TARGET_DEBUG)

$(TARGET_RELEASE): $(SOURCES)
	$(CC)  $(CFLAGS) -O3 -s -o $@ $^ $(LDFLAGS)

$(TARGET_DEBUG): $(SOURCES)
	$(CC) $(LDFLAGS) $(CFLAGS) -g -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET_RELEASE) $(TARGET_DEBUG)