# Include sources.mk to get SOURCES and INCLUDES variables
include sources.mk

# Default target
TARGET = c1m2

# Compiler Definitions
CC = gcc
CROSS_CC = arm-none-eabi-gcc

# Flags
COMMON_FLAGS = -Wall -Werror -g -O0 -std=c99
HOST_FLAGS =
MSP432_FLAGS = -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs

# Platform Specific Flags
ifeq ($(PLATFORM),MSP432)
    CC = $(CROSS_CC)
    LDFLAGS += -T ../msp432p401r.lds
    CFLAGS += $(MSP432_FLAGS) -DMSP432
else ifeq ($(PLATFORM),HOST)
    CFLAGS += $(HOST_FLAGS) -DHOST
endif

# Build Targets
build: $(SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS) $(addprefix -I, $(INCLUDES)) -o $(TARGET).out $^
	size $(TARGET).out

$(TARGET).map: $(TARGET).out
	$(CROSS_CC) -Wl,-Map,$@ -o $^

# Generate Dependency Files
%.d: %.c
	$(CC) $(CFLAGS) -MMD -MF $@ -MP -MT"$@ $(@:.d=.o)" -c $<

# Generate Object Files
%.o: %.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INCLUDES)) -c -o $@ $<

%.i: %.c
	$(CC) $(CFLAGS) -E $< -o $@

%.asm: %.c
	$(CC) $(CFLAGS) -S $< -o $@
	objdump -d $(TARGET).out > $@.txt

# Clean Target
clean:
	rm -f *.o *.out *.map *.d *.asm *.i

# Phony Targets
.PHONY: build clean compile-all

-include $(SOURCES:.c=.d)