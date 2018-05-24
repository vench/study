## -*- Makefile -*-
##
## Пользователь: vench
## Время: 02.04.2018 9:30:22
## Makefile created by Oracle Developer Studio.
##
## Этот файл создан автоматически.
##


#### Определения компиляторов и средств, используемые совместно всеми целями сборки #####
CCC = g++
CXX = g++
BASICOPTS = -g -std=c++11 
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# Определите целевые каталоги.
TARGETDIR_main.cpp=build


all: $(TARGETDIR_main.cpp)/main.cpp

## Цель: main.cpp
OBJS_main.cpp =  \
	$(TARGETDIR_main.cpp)/lib.o \
	$(TARGETDIR_main.cpp)/MyString.o \
	$(TARGETDIR_main.cpp)/Counter.o \
	$(TARGETDIR_main.cpp)/ArrayStack.o \
	$(TARGETDIR_main.cpp)/ListStack.o \
	$(TARGETDIR_main.cpp)/ArrayQueue.o \
	$(TARGETDIR_main.cpp)/StackException.o \
	$(TARGETDIR_main.cpp)/main.o
USERLIBS_main.cpp = $(SYSLIBS_main.cpp) 
DEPLIBS_main.cpp =  
LDLIBS_main.cpp = $(USERLIBS_main.cpp)


# Ссылка или архив
$(TARGETDIR_main.cpp)/main.cpp: $(TARGETDIR_main.cpp) $(OBJS_main.cpp) $(DEPLIBS_main.cpp)
	$(LINK.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ $(OBJS_main.cpp) $(LDLIBS_main.cpp)


# Скомпилировать исходные файлы .o 
$(TARGETDIR_main.cpp)/lib.o: $(TARGETDIR_main.cpp) lib.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ lib.cpp
	
$(TARGETDIR_main.cpp)/MyString.o: $(TARGETDIR_main.cpp) MyString.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ MyString.cpp
	
$(TARGETDIR_main.cpp)/ListStack.o: $(TARGETDIR_main.cpp) ListStack.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ ListStack.cpp
	
$(TARGETDIR_main.cpp)/Counter.o: $(TARGETDIR_main.cpp) Counter.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ Counter.cpp
		
$(TARGETDIR_main.cpp)/ArrayStack.o: $(TARGETDIR_main.cpp) ArrayStack.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ ArrayStack.cpp
	
$(TARGETDIR_main.cpp)/StackException.o: $(TARGETDIR_main.cpp) StackException.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ StackException.cpp	
	
$(TARGETDIR_main.cpp)/ArrayQueue.o: $(TARGETDIR_main.cpp) ArrayQueue.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ ArrayQueue.cpp
	
$(TARGETDIR_main.cpp)/main.o: $(TARGETDIR_main.cpp) main.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ main.cpp



#### При выполнении команды "Очистить цель" будут удалены все созданные файлы ####
.clean-impl:
	
	
.build-pos:
	
clean:
	rm -f \
		$(TARGETDIR_main.cpp)/main.cpp \
		$(TARGETDIR_main.cpp)/lib.o \
		$(TARGETDIR_main.cpp)/MyString.o \
		$(TARGETDIR_main.cpp)/Counter.o \
		$(TARGETDIR_main.cpp)/StackException.o \
		$(TARGETDIR_main.cpp)/ArrayStack.o \
		$(TARGETDIR_main.cpp)/ListStack.o \
		$(TARGETDIR_main.cpp)/ArrayQueue.o \
		$(TARGETDIR_main.cpp)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_main.cpp)


# Создать целевой каталог (при необходимости)
$(TARGETDIR_main.cpp):
	mkdir -p $(TARGETDIR_main.cpp)


# Включить проверку зависимостей
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Linux

