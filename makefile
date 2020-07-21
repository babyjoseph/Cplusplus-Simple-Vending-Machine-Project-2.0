OBJ = main.o dataProduct.o addProduct.o adminAccess.o savingTo.o customerAccess.o readTo.o removeProduct.o sortingProduct.o fillMe.o
CPP = g++
all : main
.PHONY : all
	$(OBJ) : %.o : %.cpp
	$(CPP) -c -I. $< -o $@
main : $(OBJ)
	$(CPP) $(OBJ) -o $@
.PHONY : clean
clean :
	rm $(OBJ) main
