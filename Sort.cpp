#include "include/Sort.h"


//
void Sort::sortByIncreasingPerimeter(std::list<Shape *> * shapeList)
{
    shapeList->sort([](const Shape *a,const Shape *b) 
			 -> bool{return a->perimeter()<b->perimeter(); }
				   );
}
void Sort::sortByDecreasingPerimeter(std::list<Shape *> * shapeList)
{
    shapeList->sort([](const Shape *a,const Shape *b) 
			 -> bool{return a->perimeter()>b->perimeter(); }
            );
}
void Sort::sortByIncreasingArea(std::list<Shape *> * shapeList)
{
    shapeList->sort([](const Shape *a,const Shape *b) 
			 -> bool{return a->area()<b->area(); }
            );
}
void Sort::sortByDecreasingArea(std::list<Shape *> * shapeList)
{
    shapeList->sort([](const Shape *a,const Shape *b) 
	 	  	 -> bool{return a->area()>b->area(); }
            );
}
void Sort::sortByIncreasingCompactness(std::list<Shape *> * shapeList)
{
    shapeList->sort([](const Shape *a,const Shape *b) 
		     -> bool{return a->Compactness()<b->Compactness(); }
            );
}

//Compactness=area/perimeter^2
