a.out : main.o Utilisateur.o Systeme.o 
	g++ main.o Utilisateur.o Systeme.o 

main.o : src/main.cc src/Utilisateur.h src/Systeme.h
	g++ -c src/main.cc

Systeme.o : src/Utilisateur.h src/Systeme.h src/Systeme.cc
	g++ -c src/Systeme.cc

Utilisateur.o : src/Utilisateur.h src/Utilisateur.cc
	g++ -c src/Utilisateur.cc

clean : 
	rm -f *.o a.out