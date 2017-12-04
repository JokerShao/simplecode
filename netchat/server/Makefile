LDFLAGS+=-lsqlite3

all:
	gcc -o ./build/rgs_server ./source/rgs_server.c $(LDFLAGS)
	gcc -o ./build/login_server ./source/login_server.c $(LDFLAGS)
	gcc -o ./build/addfrd_server ./source/addfrd_server.c $(LDFLAGS)
	gcc -o ./build/rmbaddr_server ./source/rmbaddr_server.c $(LDFLAGS)
	gcc -o ./build/chat_server ./source/chat_server.c $(LDFLAGS)
	gcc -o ./start ./source/start.c	

clean:
	rm ./build/rgs_server ./build/login_server ./build/addfrd_server ./build/rmbaddr_server ./build/chat_server start -f
