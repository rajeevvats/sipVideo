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

#include<stdint.h>
#include<libraw1394/raw1394.h>
#include<libdc1394/dc1394_control.h>
#include<libmutil/Mutex.h>
#include"Grabber.h"

#define MAX_PORTS   4
#define MAX_CAMERAS 8



class ImageHandler;

class Dc1394Grabber : public Grabber{
	public:
		Dc1394Grabber( uint32_t portId, uint32_t cameraId );

		void open();
		void getCapabilities();
		void printCapabilities();
		void printImageFormat();
		void getImageFormat();
		bool setImageChroma( uint32_t chroma );


		void read( ImageHandler * );
		//void read();
		virtual void run();
		virtual void stop();

		virtual void close();

		uint32_t getHeight(){ return height; };
		uint32_t getWidth(){ return width; };

		void setHandler( ImageHandler * handler );

	private:
		dc1394_cameracapture camera;
		raw1394handle_t cameraHandle;
		uint32_t portId;
		uint32_t cameraId;

		uint32_t height;
		uint32_t width;

		bool stopped;

		Mutex grabberLock;
		ImageHandler * handler;
		bool handlerProvidesImage;

		MImage * oldImage;

};

