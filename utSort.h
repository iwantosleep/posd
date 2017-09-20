#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"
//需編輯
using namespace std;
#include <list>



TEST (Sort, sortByIncreasingPerimeter)
{
    list<Shape *> shapeList ;//
	
    Circle cir(0,0,2);		 //Perimeter=12.56		area=12.56
	Rectangle rect(0,0,3,4); //		    =14.....		=12
	
	vertex vertex_1 = {1, 4};//		    =20				=4
	vertex vertex_2 = {2, 1};
	vertex vertex_3 = {4, 3};
	Triangle tri(vertex_1, vertex_2, vertex_3);

	shapeList.push_back(&cir);
	shapeList.push_back(&rect);
    shapeList.push_back(&tri);
    
	Sort::sortByIncreasingPerimeter(&shapeList);// compare the address
	//ASSERT_EQ(val1, val2); EXPECT_EQ(val1, val2);val1 == val2
	//failure時, goon-> expect
    list<Shape*>::iterator i = shapeList.begin();//i is do function
	ASSERT_EQ(tri.toString() ,(*i)->toString());i++;
    ASSERT_EQ(cir.toString() ,(*i)->toString());i++;
    ASSERT_EQ(rect.toString(),(*i)->toString());

}
	

TEST (Sort, sortByDecreasingPerimeter) {
	list<Shape *> shapeList ;//
	
    Circle cir(0,0,2);		
	Rectangle rect(0,0,3,4);
	
	vertex vertex_1 = {1, 4};	
	vertex vertex_2 = {2, 1};
	vertex vertex_3 = {4, 3};
	Triangle tri(vertex_1, vertex_2, vertex_3);

    shapeList.push_back(&rect);
    shapeList.push_back(&cir);
	shapeList.push_back(&tri);
    
	Sort::sortByDecreasingPerimeter(&shapeList);
    list<Shape*>::iterator i = shapeList.begin();
	ASSERT_EQ(rect.toString(),(*i)->toString());i++;
    ASSERT_EQ(cir.toString() ,(*i)->toString());i++;
    ASSERT_EQ(tri.toString() ,(*i)->toString());


}

TEST (Sort, sortByIncreasingArea) {	
	list<Shape *> shapeList ;//
	
    Circle cir(0,0,2);		
	Rectangle rect(0,0,3,4);
	
	vertex vertex_1 = {1, 4};	
	vertex vertex_2 = {2, 1};
	vertex vertex_3 = {4, 3};
	Triangle tri(vertex_1, vertex_2, vertex_3);

	shapeList.push_back(&cir);
	shapeList.push_back(&rect);
    shapeList.push_back(&tri);
   
	Sort::sortByIncreasingArea(&shapeList);
	
	list<Shape*>::iterator i = shapeList.begin();
    
	ASSERT_EQ(tri.toString() ,(*i)->toString());i++;
	ASSERT_EQ(rect.toString(),(*i)->toString());i++;
	ASSERT_EQ(cir.toString() ,(*i)->toString());
	

}

TEST (Sort, sortByDecreasingArea) {
	list<Shape *> shapeList ;//
	

    Circle cir(0,0,2);		
	Rectangle rect(0,0,3,4);
	
	vertex vertex_1 = {1, 4};	
	vertex vertex_2 = {2, 1};
	vertex vertex_3 = {4, 3};
	Triangle tri(vertex_1, vertex_2, vertex_3);

    shapeList.push_back(&tri);
    shapeList.push_back(&rect);
    shapeList.push_back(&cir);
    Sort::sortByDecreasingArea(&shapeList);
	
	list<Shape*>::iterator i = shapeList.begin();

	ASSERT_EQ(cir.toString() ,(*i)->toString());i++;
	ASSERT_EQ(rect.toString(),(*i)->toString());i++;
	ASSERT_EQ(tri.toString() ,(*i)->toString());
    


}

TEST (Sort, sortByIncreasingCompactness) {
	list<Shape *> shapeList ;//
	

    Circle cir(0,0,2);		
	Rectangle rect(0,0,3,4);
	
	vertex vertex_1 = {1, 4};	
	vertex vertex_2 = {2, 1};
	vertex vertex_3 = {4, 3};
	Triangle tri(vertex_1, vertex_2, vertex_3);

    shapeList.push_back(&tri);
    shapeList.push_back(&rect);
    shapeList.push_back(&cir);
   
	
	list<Shape*>::iterator i = shapeList.begin();
	Sort::sortByIncreasingCompactness(&shapeList);
    ASSERT_EQ(tri.toString() ,(*i)->toString());i++;
	ASSERT_EQ(rect.toString(),(*i)->toString());i++;
    ASSERT_EQ(cir.toString() ,(*i)->toString());
   

}

#endif
