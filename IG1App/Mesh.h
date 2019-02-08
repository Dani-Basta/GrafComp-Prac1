//#pragma once
#ifndef _H_Mesh_H_
#define _H_Mesh_H_

#include <GL/freeglut.h>
#include <glm.hpp>

//-------------------------------------------------------------------------

class Mesh 
{
public:
	static Mesh* createRGBAxes(GLdouble l); // creates a new 3D RGB axes mesh
	static Mesh* generaPoliespiral(glm::dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni,
		GLdouble incrLado, GLdouble numVert); //Ejercicio 1: crea una espiral
	static Mesh* generaDragon(GLuint numVert); //Ejercicio 2: crea un dragon
	static Mesh* generaTriangulo(GLdouble r); //Ejercicio 3: triángulo RGB 
	static Mesh* generaTrianguloRGB(GLdouble r); //Ejercicio 3: triángulo RGB 
	static Mesh* generaRectangulo(GLdouble w, GLdouble h); //Ejercicio 4: rectángulo RGB.
	static Mesh* generaRectanguloRGB(GLdouble w, GLdouble h); //Ejercicio 4: rectángulo RGB.
	static Mesh* generaEstrella3D(GLdouble re, GLdouble np, GLdouble h, GLdouble ri);  //Ejercicio 5: Estrella 3D.
	static Mesh* generaContCubo(GLdouble l); //Ejercicio 6: Caja.

	Mesh(void) { };
	~Mesh(void);
	virtual void render();

	glm::dvec3* getVertices() { return vertices; };  // vertex array
	glm::dvec4* getColors() { return colors; };      // color array
   
protected:

	GLuint numVertices = 0;   // arrays size (number of elements)
	GLuint primitive = GL_TRIANGLES;  // graphic primitive: GL_POINTS, GL_LINES, GL_TRIANGLES, ...

	glm::dvec3* vertices = nullptr;  // vertex array
	glm::dvec4* colors = nullptr;    // color array
};

//-------------------------------------------------------------------------

#endif //_H_Scene_H_