all:
	g++ -o SVC SVC.cpp -std=c++17
	strip SVC
san:
	g++ -o san-SVC SVC.cpp -std=c++17 -fsanitize=address -g
dbg:
	g++ -o dbg-SVC SVC.cpp -std=c++17
clean:
	rm SVC
