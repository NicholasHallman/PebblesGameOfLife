/*
 * Vertex.h
 *
 *  Created on: Nov 3, 2017
 *      Author: Advanderar
 */

#ifndef SRC_VERTEX_HPP_
#define SRC_VERTEX_HPP_



namespace peb {

class Vertex {

public:
	double x;
	double y;
	double z;
	void setVertex(double newX, double newY, double newZ);
	void setVertex(Vertex& v);
	void changeVertex(double newX, double newY, double newZ);
	Vertex();
	Vertex(double x,double y,double z);
	virtual ~Vertex();
	void printValues();
	void drawVertex();

};

} /* namespace hall7790 */

#endif /* SRC_VERTEX_HPP_ */
