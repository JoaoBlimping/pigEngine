#ifndef IMAGE_H
#define IMAGE_H


#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>


/**
 * Wraps around SDL's Textures to give it nice features and make it into a class and that
 */
class Image
{
public:
	/**
	 * Destroys the Image and deallocates the underlying SDL_Texture
	 * deallocates all the data
	 */
	~Image();

	/**
	 * Loads the specified Image file into this image
	 * Frees any currently held SDL_Texture, then creates a new one from the specified
	 * Image file. Returns true iff the load was successful.
	 */
	bool loadFromFile(SDL_Renderer * renderer,char const * filename);

	/**
	 * Deallocates the Image's data without deleting it
	 * I guess this is useful if you have Images on the stack and you want to get their
	 * memory back before the program ends.
	 */
	void free();

	/**
	 * Render the texture to the screen with the given details
	 * x is horizontal position, y is vertical position, clip is a rectangle which decides
	 * which part of the image is displayed, if NULL, the whole image is used
	 */
	void render(SDL_Renderer * renderer,int x,int y,SDL_Rect * clip = NULL);

	/**
	 * Image width accessor
	 */
	int getWidth();
	
	/**
	 * Image Height accessor
	 */
	int getHeight();

private:
	/**
	 * The SDL texture used under the hood
	 */
	SDL_Texture * texture;

	/**
	 * The texture's width in pixels
	 */
	int width;
	
	/**
	 * The texture's height in pixels
	 */
	int height;
};


#endif
