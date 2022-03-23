cpp = g++

cxxflags = -g -Wall

target = link_advanced

src_source = ../link_list/

all : $(target) publish

$(target) : $(src_source)my_link_list.o advanced_test.o
	$(cpp) $(cxxflags) $(src_source)my_link_list.cpp advanced_test.cpp -o $(target)

publish   :
	mkdir -p ../obj_advanced
	mv *.o ../obj_advanced
	mv $(src_source)*.o ../obj_advanced

clean :
	rm -rf *.o $(target) ../obj_advanced


