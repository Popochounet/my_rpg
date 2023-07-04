/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for vector folder
*/
#ifndef MY_GRAPHICS_VECTOR
    #define MY_GRAPHICS_VECTOR
    #include <SFML/System.h>
    /*
    ** ============================== VECTOR ===============================
    */
    //create a vector
    sfVector2f set_2vector(float x, float y);
    sfVector3f set_3vector(float x, float y, float z);

    //add the term value to each member of the given vector
    sfVector2f increment_2vector(sfVector2f vector, float term);
    sfVector3f increment_3vector(sfVector3f vector, float term);

    //multiply the factor to each member of the given vector
    sfVector2f scale_2vector(sfVector2f vector, float factor);
    sfVector3f scale_3vector(sfVector3f vector, float factor);
#endif
