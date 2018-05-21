#------------------------------------------------------------------------------
#  Makefile for CMPS 101 pa3
#  Creates an executable jar file called Sparse.  This makefile will compile 
#  all .java files in your current working directory.  
#------------------------------------------------------------------------------
	
JAVASRC    = Sparse.java Matrix.java List.java
SOURCES    = README Makefile $(JAVASRC)
MAINCLASS  = Sparse
CLASSES    = Sparse.class Matrix.class List.class
JARFILE    = Sparse.jar

all: $(JARFILE)

$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(CLASSES)
	rm Manifest

$(CLASSES): $(JAVASRC)
	javac -Xlint $(JAVASRC)

clean:
	rm -f Sparse.class Matrix.class List.class
