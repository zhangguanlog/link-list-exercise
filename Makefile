cpp  = g++

target = link_list

cxxflags = -g -Wall

$(target) : my_link_list.o test.o
	$(cpp) $(cxxflags) my_link_list.cpp test.cpp -o $(target) 



clean:
	rm -rf *.o $(target)
	


