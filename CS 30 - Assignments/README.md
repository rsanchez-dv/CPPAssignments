
# CS 02 - Assignments
  
This course presents an advanced coverage of the C++ programming language. Topics include templates; the Standard Template Library; data abstraction; operator overloading; inheritance; friend functions; virtual functions; multiple inheritance; and virtual base classes. An emphasis will be placed on object-oriented programming.
[Syllabus](http://www.curricunet.com/elcamino/reports/course_outline_html.cfm?courses_id=12906)

## Assignments

Each of the following assignments are as follows:

 - **Assignment 00** - Develop a program that will assign a pointer to a pointer to a pointer to a double. You will need to model what happens when you would create a three dimensional like:

		const int dim1=4, dim2=2, dim3=3;

What you will use instead (actually in addition to, in order to do a comparison) will be something like:

    const int dim1=4, dim2=2, dim3=3;
    double ***p3d;

Think of this as an array of 4 two by three matrices (two rows, three columns)
 - **Assignment 01** - You will begin to create your own version of the vector class, MyVector, by creating your class MyVector as a template class, overloading the subscript operator, creating the size function, creating the capacity function, creating the push_back function, and creating the insert function (version that takes the location in the vector where the object is to be inserted, and the object). Related to the insert and push_back functions, you should come up with some algorithm for creating additional memory when the current capacity of the vector would be exceeded by the addition of an object to the vector.
 - **Assignment 02** - In this assignment, we will start to consider some of the aspects of class inheritance. We will start with a base class Person.
 - **Assignment 03** - In this assignment, we will finish our Person class hierarchy by adding the StudentVoter class. No additional data will be included specifically in the StudentVoter class. StudentVoter will inherit from
both the Student class and the Voter class. It will require small changes to the Student class, the Voter class, and the Person class. Use the work of the Vehicle class hierarchy as a model to complete you Person class hierarchy changes.

## Release History
These assignments where done around 2012-2014.

## Built With

* Visual Studio 2012

## Authors
* **Roberto Sanchez** - *Initial work* - [Zyxel-1](https://github.com/Zyxel-1)

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/mit-license.php)

## Acknowledgments
* None at the moment
