# ----------------------------
# Makefile Options
# ----------------------------

NAME = Calctale
ICON = icon.png
DESCRIPTION = "Undertale for the TI 84 CE!"
COMPRESSED = YES
COMPRESSED_MODE = zx0
ARCHIVED = YES
PREFER_OS_CRT = YES

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
