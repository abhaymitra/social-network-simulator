all:
	export OMP_NUM_THREADS=4
	g++ -std=c++11 -w graph.cpp Node.cpp reader.cpp augFunctions.cpp generateFaculty.cpp generateStudents.cpp setCourses.cpp setFriends.cpp graphml.cpp main.cpp -fopenmp -o generator
	g++ -std=c++11 -w timekeeper.cpp -o timekeeper	
	g++ -std=c++11 -w graph.cpp augFunctions.cpp Node.cpp parser.cpp analyzer.cpp -o analyzer
	chmod +x run.sh
