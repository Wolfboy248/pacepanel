gcc -fPIC -shared -o ./components/timer_component.so "$1"/timerComponent.c "$1"/../component.c -I. -lSDL2 -lSDL2_ttf
