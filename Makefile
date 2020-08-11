TARGET: exe                             
exe:main.o mylib.a                      
	gcc main.o -o FLSTS -L . mylib.a  
mylib.a:commands.o tree.o               
	ar rs mylib.a commands.o tree.o 
commands.o:commands.c                   
	gcc -c commands.c -o commands.o 
tree.o:tree.c                           
	gcc -c tree.c -o tree.o         
main.o:main.c                           
	gcc -c main.c -o main.o         
clean:                                  
	rm commands.o                  
	rm tree.o                       
	rm main.o
	rm mylib.a                      
	rm FLSTS                          

