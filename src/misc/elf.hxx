#pragma once

#include <map>

#include "../unsigned_string.hxx"

namespace noware
{
	//namespace misc
	//{
		class elf
		{
			public:
				#include ".elf/.hxx"
				
				elf (void);
				virtual ~elf (void);
				
				virtual const bool load (const noware::unsigned_string &/* content*/);
				virtual const noware::unsigned_string read (const std::string &/* file_name*/);
				//virtual const bool loaded (void) const;
				//virtual const bool clear (void);
				
				// concatenate a char array of hex ints to one int
				virtual const unsigned long int str_int (const noware::unsigned_string &/* block*/, const bool &/* swap the ends of the array (for endianness) */ = false) const;
			//protected:
			//	header _header;
				header hdr;
				//body data;
				// the program header table
				std::map <unsigned int, program> prog;
				// the section header table
				std::map <unsigned int, section> sect;
			protected:
				//bool _loaded;
				//virtual const bool load_file_header_x86 (std::ifstream &/* file*/, const std::streampos &/* size*/);
				//virtual const bool load_file_header_x64 (std::ifstream &/* file*/, const std::streampos &/* size*/);
		};
	//}
}
