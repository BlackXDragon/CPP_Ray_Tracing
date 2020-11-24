vectortestrun: tests/vectortest
	@./tests/vectortest

tests/vectortest: tests/vectortest.cpp vector3d.o
	@g++ -o tests/vectortest tests/vectortest.cpp vector3d.o

vector3d.o: vector3d.cpp vector3d.h
	@g++ -c vector3d.cpp

colortestrun: tests/colortest
	@./tests/colortest

tests/colortest: tests/colortest.cpp color.o
	@g++ -o tests/colortest tests/colortest.cpp color.o

color.o: color.cpp color.h
	@g++ -c color.cpp

imagetestrun: tests/imagetest
	@./tests/imagetest

tests/imagetest: tests/imagetest.cpp image.o color.o
	@g++ -o tests/imagetest tests/imagetest.cpp image.o color.o

image.o: image.cpp image.h color.o
	@g++ -c image.cpp

ray.o: ray.cpp ray.h vector3d.o
	@g++ -c ray.cpp

material.o: material.cpp material.h color.o
	@g++ -c material.cpp

light.o: light.cpp light.h color.o vector3d.o ray.o
	@g++ -c light.cpp

sphere.o: sphere.h sphere.cpp ray.o material.o vector3d.o
	@g++ -c sphere.cpp

renderer.o: renderer.h renderer.cpp ray.o sphere.o color.o material.o vector3d.o image.o
	@g++ -c renderer.cpp

render: render.cpp renderer.o ray.o sphere.o color.o vector3d.o image.o light.o
	@g++ -o render render.cpp vector3d.o color.o image.o ray.o material.o sphere.o light.o renderer.o

run: render
	@./render

clean:
	rm -f vector3d.o color.o image.o ray.o material.o light.o sphere.o renderer.o render
	rm -f tests/vectortest tests/colortest tests/imagetest