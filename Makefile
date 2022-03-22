cpp  = g++

target = link_list

cxxflags = -g -Wall

all : $(target) publish

$(target) : my_link_list.o test.o
	$(cpp) $(cxxflags) my_link_list.cpp test.cpp -o $(target) 

publish:
	mkdir -p obj
	mv *.o obj

clean:
	rm -rf *.o $(target) obj
	


