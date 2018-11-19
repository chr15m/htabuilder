all: main.js ../main.exe

watch:
	while true; do $(MAKE) -q || $(MAKE); sleep 0.1; done

zip: ../main.zip

../main.zip: all
	cd .. && zip -r main.zip . -i main.exe src/main.hta src/*.js src/*.ico

../main.exe: launch.c main.res
	i686-w64-mingw32-gcc -o $@ $^ -Wl,-subsystem,windows

main.res: main.rc AppIcon.ico
	i686-w64-mingw32-windres $< -O coff -o $@

AppIcon.ico: icon.png
	convert -background transparent $< -define icon:auto-resize=16,24,32,48,64,72,96,128,256 $@

icon.png: icon.svg
	inkscape -z -e $@ -w 256 -h 256 $<

#hta.h: main.hta
#	xxd -i main.hta > hta.h

main.js: core.cljs ./node_modules/.bin/wisp
	./node_modules/.bin/wisp < $< > $@

./node_modules/.bin/wisp:
	echo {} > package.json
	npm i wisp

clean:
	rm -f hta.h icon.png AppIcon.ico main.res ../main.exe package.json main.js

