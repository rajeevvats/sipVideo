/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/* Copyright (C) 2004 
 *
 * Authors: Erik Eliasson <eliasson@it.kth.se>
 *          Johan Bilien <jobi@via.ecp.fr>
*/

#ifndef SDL_DISPLAY_H
#define SDL_DISPLAY_H
#include"VideoDisplay.h"

#include<SDL/SDL.h>
#include<X11/Xlib.h>

#include<libmutil/Thread.h>
#include<libmutil/Mutex.h>
#include<libmutil/CondVar.h>



class SdlDisplay: public VideoDisplay{
	public: 
		SdlDisplay( uint32_t width, uint32_t height );
		virtual void init( uint32_t height,  uint32_t width );
		virtual bool handlesChroma( uint32_t chroma );

	private:

		uint32_t height;
		uint32_t width;


		void openDisplay();
                virtual void createWindow();
                virtual void destroyWindow();

		virtual void displayImage( MImage * image );

                virtual MImage * allocateImage();
                virtual void deallocateImage( MImage * image );

		Window window;
		Display * display;

		SDL_Surface * surface;

};
#endif
