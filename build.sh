for n in *.cpp moced/*.cpp; do echo "Building $n"...; g++ -D__UNIX__ -D__LINUX__ -D__UNIX_JACK__  -std=c++11 -I . -I moced/ -I uiced/ -I 3th_party/ `pkg-config QtCore QtGui jack --cflags` -c "$n" || break; done
g++ -c  -I 3th_party/  3th_party/rtmidi-2.0.1/RtMidi.cpp
g++ -o cythar *.o   `pkg-config QtCore QtGui jack --libs`
