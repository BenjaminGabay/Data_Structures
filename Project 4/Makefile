# Makefile for Project 4

#These are the Macros
LD = $(shell which g++)
CXX = $(shell which g++)
override CXXFLAGS += -std=c++11 -g -Wall
EXE = Project4.out
OBJS = Project4.o
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
#"$(FILE)" allows for command line argument using command
#make run FILE=<file_name>
.PHONY: run
run: $(EXE)
	./$(EXE) $(FILE)	
	
#Valgrind command on $(EXE) with command line argument
val:
	valgrind ./$(EXE) $(FILE)	

#Finsih and zip project
finish: clean			
	rm -rf src.zip					
	zip -R src.zip '*.cpp' '*.h' 'Makefile'

