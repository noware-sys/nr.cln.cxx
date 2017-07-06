#pragma once

//#include <sstream>
//#include <ctime>
//#include <random>
#include <unistd.h>	// For read (,,) in tool::pause ().
//#include <cctype>
#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__))
	#include <conio.h>
//#else
////	#include <conio.h>
//	#include <fcntl.h>
#endif
/*
#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <sys/io.h>
#include <sys/types.h>
#include <fcntl.h>
*/
//#include "./nix/unistd.h"

//#include "name.h++"
#include "pause.hxx"
//#include "containers/variable.h++"

namespace noware
{
	// intended to be portable. 
	void pause (const std::string & prompt)
	{
		//std::string input;
		
		std::cout << prompt;

		std::cout.flush ();


		#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__))
			/*::*/_getch ();
		#else
			//getch ();
			
			signed long int i;
			char c;
			
			do
			{
				i = read (0, &c, 1);
			}
			while (i <= 0);
			
			//std::cout << "Pressed [" << i << "] (" << c << ")" << std::endl;
			
			
			////std::getchar ();
			//std::getline (std::cin, input);
		#endif
		// Wait for any keys to be released, if they are still pressed.
		//do
		//{
		//	//std::cout << ::_kbhit () << std::endl;
		//}
		//while (::_kbhit () != 0);

		//std::cout << "PASS(2)";
		//::std::cin >> c;
		//::std::cin.ignore ();

		//std::cout.flush ();
	}
}
