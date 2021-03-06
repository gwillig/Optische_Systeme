//Includes

#pragma once
#include <windows.h>
#include <stdio.h>
#include <stddef.h>
#include <opencv2/core/core.hpp>
#include "targetver.h"
#include <tchar.h>
#include <opencv2/imgproc/imgproc.hpp> //für cvtColor
#include <iostream>
#include <stdint.h>
#include"Objekt.h"
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>       /* sin */


using namespace cv;
using namespace std;

//------------------------------------------------------------------------------------------------------
//defines zur besseren Lesbarkeit des Codes
#define snapshot 0
#define videostream 1
#define saved_frame 2
#define cam_int 0
#define cam_ext 1
#define template_height 69//Höhe der Templates: 69
#define template_width 74//Breite der Templates: 74
#define AUTOBAHNSCHILD "Autobahnschild"
#define ORTSSCHILD_PFEILWEGWEISER "OrtsschildPfeilwegweiser"
#define INNERORTS "Innerorts"
#define PI 3.14159265

//Structs-----------------------------------------------------------------------------------------------
struct object {
	unsigned short Contour_ID;
	unsigned short Object_ID;
	vector<Vec4i> aiHierarchy;
	float  angle;
	int n_childs;
	double contour_length;
	double area;
	double form_factor;
	string plate_type;
	Rect box;
	int x;
	int y;
};

struct templates_letter {
	char letter;
	Mat template_letter_Mat;
};


//Funktionen--------------------------------------------------------------------------------------------
Mat dilatieren(Mat input, int dilation_element, int dilation_size); //Eigene Funktion zum Dilatieren
Mat erodieren(Mat input, int erosion_element, int erosion_size); //Eigene Funktion zum Erodieren
int count_childs(vector<Vec4i> aiHierarchy, int i); //Funktion: Anzahl der Childs zählen
char recognize_letter(Mat binary_frame, Rect box, string plate_type, int correlation_coeff_maximum, templates_letter temp[],int number_loop, float angle); //Funktion zum Buchstaben erkennen
string maximum(double blue, double yellow, double white);//Art des Schildes unterscheiden
Mat rotate_eigene(Mat src, double angle);//Um Bild zu rotieren
void test(templates_letter temp[]);

