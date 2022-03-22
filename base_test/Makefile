cpp  = g++

source_dir = ../link_list/

target = link_list

obj_dir = ../

cxxflags = -g -Wall

all : $(target) publish

$(target) : $(source_dir)my_link_list.o test.o
	$(cpp) $(cxxflags) $(source_dir)my_link_list.cpp test.cpp -o $(target) 

publish:
	mkdir -p $(obj_dir)obj
	mv *.o $(obj_dir)obj
	mv $(source_dir)*.o $(obj_dir)obj

clean:
	rm -rf  $(target) $(obj_dir)obj
	


