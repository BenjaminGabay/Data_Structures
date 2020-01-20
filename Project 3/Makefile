# Makefile for Project 3

#These are the Macros
LD = $(shell which g++)
CXX = $(shell which g++)
override CXXFLAGS += -std=c++11 -g -Wall
EXE = Project3.out
OBJS = main.o Song.o Library.o TitleCompare.o ArtistCompare.o AlbumCompare.o GenreCompare.o YearCompare.o
DEPS = $(addprefix.,$(OBJS:.o=.d))	

#Create Executable file
$(EXE): $(DEPS) $(OBJS)
	$(LD) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $@            

#Means to Generate .d for each of the .cpp files	
.%.d: %.cpp
	@$(RM) $@; \
	$(CXX) -MM -MF $@ -MT "$(<:.cpp=.o) $@" -c $(CPPFLAGS) $<		

#Means to Generate .o for each of the .cpp files
$(OBJS): %.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

#Include dependency files in Makefile
-include $(DEPS)

#Clean command
.PHONY: clean
clean:
	$(RM) $(OBJS) $(DEPS) $(EXE)

#Run command
#"$(LIBRARY_FILE)" allows for command line argument using command
#make run LIBRARY_FILE=<file_name>
.PHONY: run
run: $(EXE)
	./$(EXE) $(LIBRARY_FILE)	
	
#Valgrind command on $(EXE) with command line argument
val:
	valgrind ./$(EXE) $(LIBRARY_FILE)	

#Finsih and zip project
finish: clean			
	rm -rf src.zip					
	zip -R src.zip '*.cpp' '*.h' 'Makefile'

