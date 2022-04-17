all:
	g++ -o HNote HNote.cpp -std=c++17
	strip HNote
test:
	g++ -o DebugNote HNote.cpp -std=c++17 -fsanitize=address -g
fix:
	g++ -o HNoteFixed HNote.cpp -std=c++17
clean:
	rm HNote
