wave_eq.png.png: cuerda.dat plot.py
	python plot.py
cuerda.dat: cuerda.x
	./cuerda.x > cuerda.dat
cuerda.x: cuerda.cpp
	g++ cuerda.cpp -o cuerda.x

clean:
	rm cuerda.x
