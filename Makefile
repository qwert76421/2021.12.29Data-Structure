CC=g++
EXE=main.exe
OBJS=main.o Treap.o SortedArray.o SkipList.o Hash.o

$(EXE) : $(OBJS) 
	$(CC) -o $(EXE) $(OBJS) 

%.o : %.cpp
	$(CC) -c -o $@ $< 

clean : 
	rm $(EXE) $(OBJS) 
