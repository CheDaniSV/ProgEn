CC=g++#Компилятор
INSTFOLDER=../bin#Папка установки
DEPFOLDER=../include#Папка зависимостей
CPPFILES=$(wildcard *.cpp)#Список файлов .cpp
OBJECTS=$(patsubst %.cpp,%.o,$(CPPFILES))#Преобразуем список файлов .cpp в список .o
LIBS=$(patsubst %.cpp,%.dll,$(CPPFILES))#Преобразуем список файлов .cpp в список .dll
IMPLIBS=$(patsubst %.cpp,%.lib,$(CPPFILES))#Преобразуем список файлов .cpp в список .lib
IMPLFLAGS=$(foreach L, $(IMPLIBS), -Wl,--out-implib,$(L))#Для каждой библиотеки из списка IMPLIBS генерируем флаги для компиляции

# Цель по умолчанию. Выполняет компиляцию части программного комплекса
compile: $(LIBS)

# Все .o компилируем в .dll
%.dll: %.o
	$(CC) -shared -o $@ $^ $(IMPLFLAGS)

# Все .cpp компилируем в .o
%.o: %.cpp
	$(CC) -fPIC -c $^

# Очистка папки от ранее откомпилированных двоичных файлов
clean:
	rm $(LIBS) $(OBJECTS) $(IMPLIBS)

# Устанавливаем библиотеки в папку установки
install:
	$(info installing into "$(INSTFOLDER)")
	-mkdir $(INSTFOLDER) $(DEPFOLDER)
	cp *.dll $(INSTFOLDER)
	cp *.h $(DEPFOLDER)

# Удаляем библиотеки из папки установки
uninstall:
	$(info uninstalling from "$(INSTFOLDER)")
	rm $(INSTFOLDER)/*.dll $(DEPFOLDER)/*.h

# Чтобы .o файлы автоматически не удалялись
.PRECIOUS: %.o

# Чтобы make в любом случае выполнял данные цели
.PHONY: compile clean install uninstall