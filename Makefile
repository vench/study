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
	$(TARGETDIR_main.cpp)/myRect.o \
	$(TARGETDIR_main.cpp)/Point.o \
	$(TARGETDIR_main.cpp)/myString.o \
	$(TARGETDIR_main.cpp)/Bochka.o \
	$(TARGETDIR_main.cpp)/Shape.o \
	$(TARGETDIR_main.cpp)/Circle.o \
	$(TARGETDIR_main.cpp)/Bin.o \
	$(TARGETDIR_main.cpp)/Oct.o \
	$(TARGETDIR_main.cpp)/Hex.o \
	$(TARGETDIR_main.cpp)/Bytes.o \
	$(TARGETDIR_main.cpp)/main.o
USERLIBS_main.cpp = $(SYSLIBS_main.cpp) 
DEPLIBS_main.cpp =  
LDLIBS_main.cpp = $(USERLIBS_main.cpp)


# Ссылка или архив
$(TARGETDIR_main.cpp)/main.cpp: $(TARGETDIR_main.cpp) $(OBJS_main.cpp) $(DEPLIBS_main.cpp)
	$(LINK.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ $(OBJS_main.cpp) $(LDLIBS_main.cpp)


# Скомпилировать исходные файлы .o
$(TARGETDIR_main.cpp)/myRect.o: $(TARGETDIR_main.cpp) myRect.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ myRect.cpp
	
$(TARGETDIR_main.cpp)/Bochka.o: $(TARGETDIR_main.cpp) Bochka.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ Bochka.cpp

$(TARGETDIR_main.cpp)/Circle.o: $(TARGETDIR_main.cpp) Circle.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ Circle.cpp
	
$(TARGETDIR_main.cpp)/Shape.o: $(TARGETDIR_main.cpp) Shape.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ Shape.cpp

$(TARGETDIR_main.cpp)/myString.o: $(TARGETDIR_main.cpp) myString.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ myString.cpp

$(TARGETDIR_main.cpp)/Bin.o: $(TARGETDIR_main.cpp) Bin.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ Bin.cpp
	
$(TARGETDIR_main.cpp)/Oct.o: $(TARGETDIR_main.cpp) Oct.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ Oct.cpp
	
$(TARGETDIR_main.cpp)/Hex.o: $(TARGETDIR_main.cpp) Hex.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ Hex.cpp
	
$(TARGETDIR_main.cpp)/Bytes.o: $(TARGETDIR_main.cpp) Bytes.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ Bytes.cpp

$(TARGETDIR_main.cpp)/Point.o: $(TARGETDIR_main.cpp) Point.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ Point.cpp

$(TARGETDIR_main.cpp)/main.o: $(TARGETDIR_main.cpp) main.cpp
	$(COMPILE.cc) $(CCFLAGS_main.cpp) $(CPPFLAGS_main.cpp) -o $@ main.cpp



#### При выполнении команды "Очистить цель" будут удалены все созданные файлы ####
.clean-impl:
	
	
.build-pos:
	
clean:
	rm -f \
		$(TARGETDIR_main.cpp)/main.cpp \
		$(TARGETDIR_main.cpp)/myRect.o \
		$(TARGETDIR_main.cpp)/myString.o \
		$(TARGETDIR_main.cpp)/Bochka.o \
		$(TARGETDIR_main.cpp)/Shape.o \
		$(TARGETDIR_main.cpp)/Circle.o \
		$(TARGETDIR_main.cpp)/Bin.o \
		$(TARGETDIR_main.cpp)/Oct.o \
		$(TARGETDIR_main.cpp)/Hex.o \
		$(TARGETDIR_main.cpp)/Bytes.o \
		$(TARGETDIR_main.cpp)/Point.o \
		$(TARGETDIR_main.cpp)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_main.cpp)


# Создать целевой каталог (при необходимости)
$(TARGETDIR_main.cpp):
	mkdir -p $(TARGETDIR_main.cpp)


# Включить проверку зависимостей
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Linux

