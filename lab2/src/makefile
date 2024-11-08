CC=g++#Компилятор
BINARY=fcalc#Название файла программы
LIBS=opslib#Библиотека для программы
LIBFOLDER=../lib#Папка с библиотекой
DEPFOLDER=../include#Папка с хедерами
INSTFOLDER=../bin#Папка установки
DEPFLAGS=-I$(DEPFOLDER) -MP -MD#Флаги компиляции для хедеров
LDFLAGS=$(foreach L, $(LIBS), -L$(LIBFOLDER) -l:$(L).lib)#Флаги компиляции для библиотеки
CPPFILES=$(wildcard *.cpp)#Список файлов .cpp
DEPFILES=$(patsubst %.cpp,%.d,$(CPPFILES))#Преобразуем список файлов .cpp в список .d
OBJECTS=$(patsubst %.cpp,%.o,$(CPPFILES))#Преобразуем список файлов .cpp в список .o

# Цель по умолчанию. Выполняет компиляцию части программного комплекса.
compile: $(BINARY)

# Компилируем программу
$(BINARY): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

# Все .cpp компилируем в .o
%.o: %.cpp 
	$(CC) $(DEPFLAGS) -c $^

# Очистка папки от ранее откомпилированных двоичных файлов
clean:
	rm $(BINARY) $(OBJECTS) $(DEPFILES)

# Устанавливаем библиотеки в папку установки
install:
	$(info installing into "$(INSTFOLDER)")
	-mkdir $(INSTFOLDER)
	cp $(BINARY) $(INSTFOLDER)

# Удаляем библиотеки из папки установки
uninstall:
	$(info uninstalling from "$(INSTFOLDER)")
	rm $(INSTFOLDER)/$(BINARY)

# Чтобы make в любом случае выполнял данные цели
.PHONY: compile clean install uninstall