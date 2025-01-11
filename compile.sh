#!/bin/bash

# Detect the OS
OS=$(uname)

# Set common flags
SRC_FILES=$(find . -name '*.c' ! -path './src/components/*')
OUT_FILE="pacePanel"
COMMON_FLAGS="-lSDL2 -lSDL2_ttf -rdynamic -ldl"

COMPILE_LIB_SCRIPTS=$(find . -name 'compileLib.sh')

for script in $COMPILE_LIB_SCRIPTS; do
	echo "Compiling $script..."
	dir=$(dirname "$script")
	bash "$script" "$dir"
done

echo ""
echo "////// COMPILATION OF COMPONENT LIBRARIES COMPLETED //////"
echo ""

# OS-specific compilation flags
if [[ "$OS" == "Linux" ]]; then
    echo "Detected Linux"
    EXTRA_FLAGS="-lX11"
elif [[ "$OS" == "Darwin" ]]; then
    echo "Detected macOS"
    EXTRA_FLAGS="-framework Cocoa -framework OpenGL -framework SDL2 -framework SDL2_ttf"
elif [[ "$OS" =~ MINGW* || "$OS" =~ MSYS* ]]; then
    echo "Detected Windows"
    EXTRA_FLAGS="-lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf"
else
    echo "Unsupported OS: $OS"
    exit 1
fi

# Compile the program
echo "Compiling with flags: $COMMON_FLAGS $EXTRA_FLAGS"
gcc -o "$OUT_FILE" $SRC_FILES $COMMON_FLAGS $EXTRA_FLAGS

# Run the program if compilation is successful
if [[ $? -eq 0 ]]; then
    echo "Compilation successful. Running $OUT_FILE..."
    ./"$OUT_FILE"
else
    echo "Compilation failed."
    exit 1
fi

