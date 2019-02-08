#include "Mesh.h"

using namespace glm;

//-------------------------------------------------------------------------

Mesh ::~Mesh(void) 
{
  delete[] vertices;  vertices = nullptr;
  delete[] colors;    colors = nullptr;
}
//-------------------------------------------------------------------------

void Mesh::render()
{
  if (vertices != nullptr) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, vertices);  // number of coordinates per vertex, type of each coordinate, stride, pointer 
    if (colors != nullptr) {
      glEnableClientState(GL_COLOR_ARRAY);
      glColorPointer(4, GL_DOUBLE, 0, colors);   // number of coordinates per color, type of each coordinate, stride, pointer 
    }
	
    glDrawArrays(primitive, 0, numVertices);   // primitive graphic, first index and number of elements to be rendered

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
  }
}
//-------------------------------------------------------------------------

//Crea una malla con los ejes RGB
Mesh * Mesh::createRGBAxes(GLdouble l)
{
  Mesh* m = new Mesh();
  m->primitive = GL_LINES;  
  m->numVertices = 6;	//Número de vértices de la figura que dibujamos. 
 //Dibujamos objetos en 3 dimensiones, entonces tenemos 6 vértices.

  m->vertices = new dvec3[m->numVertices];
  // X axis vertices
  m->vertices[0] = dvec3(0.0, 0.0, 0.0);   
  m->vertices[1] = dvec3(l, 0.0, 0);
  // Y axis vertices
  m->vertices[2] = dvec3(0, 0.0, 0.0);
  m->vertices[3] = dvec3(0.0, l, 0.0); 
  // Z axis vertices
  m->vertices[4] = dvec3(0.0, 0.0, 0.0);
  m->vertices[5] = dvec3(0.0, 0.0, l);

  m->colors = new dvec4[m->numVertices];
  // X axis color: red  ( Alpha = 1 : fully opaque)
  m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
  m->colors[1] = dvec4(1.0, 0.0, 0.0, 1.0);
  // Y axis color: green
  m->colors[2] = dvec4(0.0, 1.0, 0.0, 1.0);
  m->colors[3] = dvec4(0.0, 1.0, 0.0, 1.0);
  // Z axis color: blue
  m->colors[4] = dvec4(0.0, 0.0, 1.0, 1.0);
  m->colors[5] = dvec4(0.0, 0.0, 1.0, 1.0);
 
  return m; 
}
//-------------------------------------------------------------------------

Mesh* Mesh::generaPoliespiral(dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni,
	GLdouble incrLado, GLdouble numVert) {

	Mesh* m = new Mesh();
	m->primitive = GL_LINE_STRIP;
	m->numVertices = numVert;	//Número de vértices de la figura que dibujamos. 

	m->vertices = new dvec3[m->numVertices];

	double x = verIni.x;
	double y = verIni.y;

	double lado = ladoIni;
	double angulo = angIni;

	//Primer vértice.
	m->vertices[0] = dvec3(x, y, 0.0);

	for (int i = 1; i < m->numVertices; i++) {
		//Calculamos x del nuevo vértice.
		x += lado * cos(radians(angulo));

		//Calculamos y del nuevo vértice.
		y += lado * sin(radians(angulo));

		//Añadimos el nuevo vértice.
		m->vertices[i] = dvec3(x,y,0.0);

		//Incrementamos el angulo y la longitud.
		lado += incrLado;
		angulo += incrAng;
	}

	return m;
}
//-------------------------------------------------------------------------

Mesh* Mesh::generaDragon(GLuint numVert) { //Ejercicio 2: crea un dragon
	
	Mesh* m = new Mesh();
	m->primitive = GL_POINTS;
	m->numVertices = numVert;	//Número de vértices de la figura que dibujamos. 

	//Dibujamos objetos en 3 dimensiones, entonces tenemos 6 vértices.

	m->vertices = new dvec3[m->numVertices];

	m->vertices[0] = dvec3(0.0, 0.0, 0.0);

	for (int i = 1; i < numVert; i++) {
		if ((rand() / double(RAND_MAX)) < 0.787473)  // T1
			m->vertices[i] = dvec3(0.824074 * m->vertices[i-1].x + 0.281482 * m->vertices[i - 1].y - 0.882290,
									-0.212346 * m->vertices[i - 1].x + 0.864198 * m->vertices[i - 1].y - 0.110607,
									0.0);
		 else 
			m->vertices[i] = dvec3(0.088272 * m->vertices[i - 1].x + 0.520988 * m->vertices[i - 1].y + 0.785360,
								-0.463889 * m->vertices[i - 1].x - 0.377778 * m->vertices[i - 1].y + 8.095795,
							0.0);

	}

	return m;
}

//-------------------------------------------------------------------------


Mesh* Mesh::generaTriangulo(GLdouble r) { //Ejercicio 3: crea un triangulo RGB

	//Se utilizan los siguientes parámetros:
	//dvec2 centro = dvec2(0, 0);
	double angIni = 90;
	double incrAng = 120;

	Mesh* m = new Mesh();
	m->primitive = GL_TRIANGLES;
	m->numVertices = 3;	//Número de vértices de la figura que dibujamos. 

	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(r*cos(radians(angIni)), r*sin(angIni), 0.0);
	m->vertices[1] = dvec3(r*cos(radians(angIni + incrAng )), r*sin(radians(angIni + incrAng)), 0.0);
	m->vertices[2] = dvec3(r*cos(radians(angIni + incrAng*2)), r*sin(radians(angIni + incrAng * 2)), 0.0);

	return m;
}

Mesh* Mesh::generaTrianguloRGB(GLdouble r) { //Ejercicio 3: crea un triangulo RGB
	Mesh* m = generaTriangulo(r);

	m->colors = new dvec4[m->numVertices];
	m->colors[0] = dvec4(1, 0, 0, 0);
	m->colors[1] = dvec4(0, 1, 0, 0);
	m->colors[2] = dvec4(0, 0, 1, 0);

	return m;
}


Mesh* Mesh::generaRectangulo(GLdouble w, GLdouble h) {
	 Mesh* m = new Mesh();
	 m->primitive = GL_TRIANGLE_STRIP;
	 m->numVertices = 4;	//Número de vértices de la figura que dibujamos. 4 porque es un rectángulo. 

	 m->vertices = new dvec3[m->numVertices];

	 //Se supone que el centro está en (0.0,0.0,0.0).
	 m->vertices[0] = dvec3(-w/2,h/2,0.0);
	 m->vertices[1] = dvec3(-w/2,-h/2,0.0);
	 m->vertices[2] = dvec3(w/2,h/2 , 0.0);
	 m->vertices[3] = dvec3(w/2, -h/2 , 0.0 );
	 

	 return m;

}

Mesh* Mesh::generaRectanguloRGB(GLdouble w, GLdouble h) { //Ejercicio 3: crea un triangulo RGB
	Mesh* m = generaRectangulo(w,h);

	m->colors = new dvec4[m->numVertices];
	m->colors[0] = dvec4(1, 0, 0, 0);
	m->colors[1] = dvec4(0, 1, 0, 0);
	m->colors[2] = dvec4(0, 0, 1, 0);
	m->colors[3] = dvec4(0,0,0,1);
	
	return m;
}


Mesh* Mesh::generaEstrella3D(GLdouble re, GLdouble np, GLdouble h, GLdouble ri) {  //Ejercicio 5: Estrella 3D.
	Mesh* m = new Mesh();
	m->primitive = GL_TRIANGLE_FAN;
	m->numVertices = 2*np+2;	//Número de vértices de la figura que dibujamos. 4 porque es un rectángulo. 

	m->vertices = new dvec3[m->numVertices];

	//Se supone que el centro está en (0.0,0.0,0.0).
	//AngIni es 90 y incrAng = 120.
	GLdouble angIni = 90;
	GLdouble incrAng = 180 / np;


	m->vertices[0] = dvec3(0,0,0);
	m->vertices[1] = dvec3(re*cos(radians(angIni)), re*sin(radians(angIni)),h);

	for (int i = 2; i <= m->numVertices-2; i+=2) {
		angIni += incrAng;
		m->vertices[i] = dvec3(ri*cos(radians(angIni)), ri*sin(radians(angIni)), h);
		angIni += incrAng;
		m->vertices[i+1] = dvec3(re*cos(radians(angIni)), re*sin(radians(angIni)), h);
	}

	//m->vertices[m->numVertices-1]= dvec3(re*cos(radians(90)), re*sin(radians(90)), h);


	return m;

}

Mesh* Mesh::generaContCubo(GLdouble l) {  //Ejercicio 6: Caja.
	Mesh* m = new Mesh();
	m->primitive = GL_TRIANGLE_STRIP;
	m->numVertices = 10;	//Él numero de vertices de la caja. 

	m->vertices = new dvec3[m->numVertices];

	//Se supone que el centro está en (0.0,0.0,0.0).


	GLdouble dist = l / 2;

	m->vertices[0] = dvec3(-dist,dist,dist);
	m->vertices[1] = dvec3(-dist, -dist, dist);

	m->vertices[2] = dvec3(dist, dist, dist);
	m->vertices[3] = dvec3(dist, -dist, dist);
	m->vertices[4] = dvec3(dist, dist, -dist);
	m->vertices[5] = dvec3(dist, -dist, -dist);
	m->vertices[6] = dvec3(-dist, dist, -dist);
	m->vertices[7] = dvec3(-dist, -dist, -dist);

	m->vertices[8] = m->vertices[0];
	m->vertices[9] = m->vertices[1];


	return m;


}