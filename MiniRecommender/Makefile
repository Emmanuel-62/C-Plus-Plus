a.out : main.o Utilisateur.o
	g++ main.o Utilisateur.o

main.o : src/main.cc src/Utilisateur.h 
	g++ -c src/main.cc

Utilisateur.o : src/Utilisateur.h src/Utilisateur.cc
	g++ -c src/Utilisateur.cc

clean : 
	rm -f *.o a.out