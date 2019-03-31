# CSE 165/ENGR 140: Introduction to Object-Oriented Programming

## Lab 4

### Inheritance

1. Download the InheritanceDemo.zip file and study the code in that project.
2. In it, there is a super-class called `Shape`, and several children classes, including `Circle`, `Rect`, and `Point`.
3. There is a new class definition for a `TextBox` starting on line 96, but it has not been completed. Your task is to complete it.
4. A `TextBox` object should be just a string positioned at a particular point on the screen. Your constructor should allow me to specify the string in `TextBox`, the position of it, the font, and the color.
5. There is a function called `renderText`, which demonstrates how to produce text on the screen. Experiment with this function a lot so you can learn how it works.
6. There is not a large font section. Valid font values are:
   > GLUT_BITMAP_TIMES_ROMAN_24
   > GLUT_BITMAP_TIMES_ROMAN_10
   > GLUT_BITMAP_HELVETICA_18
   > GLUT_BITMAP_HELVETICA_12
   > GLUT_BITMAP_HELVETICA_10
   > GLUT_BITMAP_8_BY_13
   > GLUT_BITMAP_9_BY_15
7. Your `TextBox` object should be designed in such a way that when we un-comment line 295, it should just work, without the need for any extra steps.