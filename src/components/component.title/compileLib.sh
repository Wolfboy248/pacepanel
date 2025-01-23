gcc -fPIC -shared -o ./components/Title_component.so "$1"/titleComponent.c "$1"/../component.c -I. -lSDL2 -lSDL2_ttf
