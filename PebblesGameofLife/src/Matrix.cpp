/*
 * toolbar.h
 *
 *  Created on: Nov 24, 2017
 *      Author: Omid Ghiyasian
 *      		Nicholas Hallman
 *
 *
 */

#include "Matrix.hpp"

namespace peb {

Matrix::Matrix() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				this->matrix[i][j] = 1;
			else
				this->matrix[i][j] = 0;
		}
	}
}

void Matrix::matrix_pre_multiply(Matrix* m) {
	Matrix* temp = new Matrix();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			GLfloat sum = 0;
			for (int k = 0; k < 4; k++) {
				sum += m->matrix[i][k] * this->matrix[k][j];
			}
			temp->matrix[i][j] = sum;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->matrix[i][j] = temp->matrix[i][j];
		}
	}
	delete temp;
	return;
}

void Matrix::translate(GLfloat tx, GLfloat ty, GLfloat tz) {
	this->matrix[0][3] += tx;
	this->matrix[1][3] += ty;
	this->matrix[2][3] += tz;
	this->matrix[3][3] = 1;
	return;
}

void Matrix::transpose() {
	GLint i, j;
	GLint temp;
	for (i=0; i<3; i++) {
		for (j=0; j<4; j++) {
			temp = this->matrix[i][j];
			this->matrix[i][j] = this->matrix[j][i];
			this->matrix[j][i] = temp;
		}
	}
	return;
}

void Matrix::normalize() {
	GLfloat norm;
	norm = sqrt(this->matrix[0][0]*this->matrix[0][0]+this->matrix[1][0]*this->matrix[1][0]+this->matrix[2][0]*this->matrix[2][0]);

	this->matrix[0][0] = this->matrix[0][0]/norm;
	this->matrix[1][0] = this->matrix[1][0]/norm;
	this->matrix[2][0] = this->matrix[2][0]/norm;

	this->matrix[0][2] = this->matrix[1][0]*this->matrix[2][1] - this->matrix[2][0]*this->matrix[1][1];
	this->matrix[1][2] = this->matrix[2][0]*this->matrix[0][1] - this->matrix[0][0]*this->matrix[2][1];
	this->matrix[2][2] = this->matrix[0][0]*this->matrix[1][1] - this->matrix[1][0]*this->matrix[0][1];

	norm = sqrt(this->matrix[0][2]*this->matrix[0][2]+this->matrix[1][2]*this->matrix[1][2]+this->matrix[2][2]*this->matrix[2][2]);

	this->matrix[0][2] = this->matrix[0][2]/norm;
	this->matrix[1][2] = this->matrix[1][2]/norm;
	this->matrix[2][2] = this->matrix[2][2]/norm;

	this->matrix[0][1] = this->matrix[1][2]*this->matrix[2][0] - this->matrix[1][0]*this->matrix[2][2];
	this->matrix[1][1] = this->matrix[2][2]*this->matrix[0][0] - this->matrix[2][0]*this->matrix[0][2];
	this->matrix[2][1] = this->matrix[0][2]*this->matrix[1][0] - this->matrix[0][0]*this->matrix[1][2];

	this->matrix[3][0] = 0;
	this->matrix[3][1] = 0;
	this->matrix[3][2] = 0;
	this->matrix[3][3] = 1;

	return;
}

void Matrix::multiply_vector(GLfloat* v) {
	GLfloat sum_row_vec = 0;
	GLint i;
	GLint j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			sum_row_vec += v[j] * this->matrix[j][i];
		}
		v[i] = sum_row_vec;
		sum_row_vec = 0;
	}
	return;
}

void Matrix::rotate(GLfloat x, GLfloat y, GLfloat z, GLfloat angle) {
	angle = angle * 3.1415926/180;
	float oneC = 1 - cos(angle);
	float COS = cos(angle);
	float SIN = sin(angle);

	Matrix* m = new Matrix();

	m->matrix[0][0] = x * x * oneC + COS;
	m->matrix[0][1] = x * y * oneC + z * SIN;
	m->matrix[0][2] = x * z * oneC - y * SIN;
	m->matrix[0][3] = 0;
	m->matrix[1][0] = y * x * oneC - z * SIN;
	m->matrix[1][1] = y * y * oneC + COS;
	m->matrix[1][2] = y * z * oneC + x * SIN;
	m->matrix[1][3] = 0;
	m->matrix[2][0] = z * x * oneC + y * SIN;
	m->matrix[2][1] = z * y * oneC - x * SIN;
	m->matrix[2][2] = z * z * oneC + COS;
	m->matrix[2][3] = 0;
	m->matrix[3][0] = 0;
	m->matrix[3][1] = 0;
	m->matrix[3][2] = 0;
	m->matrix[3][3] = 1;

	this->matrix_pre_multiply(m);
	delete m;
}

}
