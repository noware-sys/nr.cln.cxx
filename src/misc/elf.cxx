#pragma once

#include "elf.hxx"

noware::elf::elf (void)
{
	_loaded = false;
}

noware::elf::~elf (void)
{
}

const bool load_file_x86 (std::ifstream & file, const std::streampos & size)
{
	// we left 'load_file()' at 'e_version'.
	// the next field to load is 'e_entry'
	
	return false;
}

const bool load_file_header_x64 (std::ifstream & file, const std::streampos & size)
{
	char * block;
	
	// we left 'load_file()' at 'e_version'.
	// the next field to load is 'e_entry'
	
	// e_entry
	// the entry point of the program
	file.seekg (4 /* 'e_version' is this many bytes in size; skip it */, std::ios::cur);
	block = new char [8];
	file.read (block, 8);
	if (!hdr.entry.load (block, 8))
		return false;
	
	// e_phoff
	// the program header table location
	file.seekg (8, std::ios::cur);
	block = new char [8];
	file.read (block, 8);
	if (!hdr.phoff.load (block, 8))
		return false;
	
	// e_shoff
	// the section header table location
	file.seekg (8, std::ios::cur);
	block = new char [8];
	file.read (block, 8);
	if (!hdr.shoff.load (block, 8))
		return false;
	
	// e_flags
	file.seekg (8, std::ios::cur);
	block = new char [4];
	file.read (block, 4);
	if (!hdr.flag.load (block, 4))
		return false;
	
	
	// the remainder of the ELF header is common
	// between 32 and 64 bits.
	// it is read in the 'load_file' function
	
	return true;
}

const bool noware::elf::load_file (const std::string & file_name)
{
	std::ifstream file;
	std::streampos size;
	char * block;
	// 32 or 64 bits
	bool x64;
	
	file.open (argv [1], std::ios::in | std::ios::binary | std::ios::ate);
	
	if (!file.is_open ())
		return false;
	
	size = file.tellg ();
	
	// there should be at least the magic number
	// 0x7F E L F
	if (size < 4)
		return false;
	
	// read the file fields and save them
	// in the appropriate class fields
	// 
	// the class shold free them as needed
	// so we do not need to worry about freeing them here
	
	// e_ident[EI_MAG]
	// the magic number
	file.seekg (0, std::ios::beg);
	block = new char [4];
	file.read (block, 4);
	//if (!hdr.id_sign.load (block, 4))
	//	return false;
	hdr.id_sign.data = block;
	
	// e_ident[EI_CLASS]
	// the processing architecture's number of bits
	file.seekg (4, std::ios::cur);
	block = new char [1];
	file.read (block, 1);
	//if (!hdr.id_class.load (block, 1))
	//	return false;
	hdr.id_class.data = block;
	
	// save the architecture bits
	x64 = hdr.id_class [1] == 0x2;
	
	// e_ident[EI_DATA]
	// the endianness
	file.seekg (1, std::ios::cur);
	block = new char [1];
	file.read (block, 1);
	//if (!hdr.id_data.load (block, 1))
	//	return false;
	hdr.id_data.data = block;
	
	// e_ident[EI_VERSION]
	// the version of the ELF
	file.seekg (1, std::ios::cur);
	block = new char [1];
	file.read (block, 1);
	//if (!hdr.id_version.load (block, 1))
	//	return false;
	hdr.id_version.data = block;
	
	// e_ident[EI_OSABI]
	// the target OS ABI
	file.seekg (1, std::ios::cur);
	block = new char [1];
	file.read (block, 1);
	//if (!hdr.id_osabi.load (block, 1))
	//	return false;
	hdr.id_osabi.data = block;
	
	// e_ident[EI_ABIVERSION]
	// the ABI version
	file.seekg (1, std::ios::cur);
	block = new char [1];
	file.read (block, 1);
	//if (!hdr.id_abiversion.load (block, 1))
	//	return false;
	hdr.id_abiversion.data = block;
	
	// e_ident[EI_PAD]
	// unused
	file.seekg (1, std::ios::cur);
	block = new char [7];
	file.read (block, 7);
	//if (!hdr.id_pad.load (block, 7))
	//	return false;
	hdr.id_pad.data = block;
	
	// e_type
	file.seekg (7, std::ios::cur);
	block = new char [2];
	file.read (block, 2);
	//if (!hdr.type.load (block, 2))
	//	return false;
	hdr.type.data = block;
	
	// e_machine
	file.seekg (2, std::ios::cur);
	block = new char [2];
	file.read (block, 2);
	//if (!hdr.mach.load (block, 2))
	//	return false;
	hdr.mach.data = block;
	
	// e_version
	file.seekg (2, std::ios::cur);
	block = new char [4];
	file.read (block, 4);
	//if (!hdr.version.load (block, 4))
	//	return false;
	hdr.version.data = block;
	
	if (!x64)
	{
		//if (!load_file_header_x86 (file, size))
		//	return false;
		
		// e_entry
		// the entry point of the program
		file.seekg (4 /* 'e_version' is this many bytes in size; skip it */, std::ios::cur);
		block = new char [8];
		file.read (block, 8);
		//if (!hdr.entry.load (block, 8))
		//	return false;
		hdr.entry.data = block;
		
		// e_phoff
		// the program header table location
		file.seekg (8, std::ios::cur);
		block = new char [8];
		file.read (block, 8);
		//if (!hdr.phoff.load (block, 8))
		//	return false;
		hdr.phoff.data = block;
		
		// e_shoff
		// the section header table location
		file.seekg (8, std::ios::cur);
		block = new char [8];
		file.read (block, 8);
		//if (!hdr.shoff.load (block, 8))
		//	return false;
		hdr.shoff.data = block;
		
		// e_flags
		file.seekg (8, std::ios::cur);
		block = new char [4];
		file.read (block, 4);
		//if (!hdr.flag.load (block, 4))
		//	return false;
		hdr.flag.data = block;
	}
	else
	{
		//if (!load_file_header_x64 (file, size))
		//	return false;
	}
	
	// e_ehsize
	file.seekg (4, std::ios::cur);
	block = new char [2];
	file.read (block, 2);
	//if (!hdr.ehsize.load (block, 2))
	//	return false;
	hdr.ehsize.ehsize.data = block;
	
	// e_phentsize
	file.seekg (2, std::ios::cur);
	block = new char [2];
	file.read (block, 2);
	//if (!hdr.phentsize.load (block, 2))
	//	return false;
	hdr.phentsize.data = block;
	
	// e_phnum
	file.seekg (2, std::ios::cur);
	block = new char [2];
	file.read (block, 2);
	//if (!hdr.phnum.load (block, 2))
	//	return false;
	hdr.phnum.data = block;
	
	// e_shentsize
	file.seekg (2, std::ios::cur);
	block = new char [2];
	file.read (block, 2);
	//if (!hdr.shentsize.load (block, 2))
	//	return false;
	hdr.shentsize.data = block;
	
	// e_shnum
	file.seekg (2, std::ios::cur);
	block = new char [2];
	file.read (block, 2);
	//if (!hdr.shnum.load (block, 2))
	//	return false;
	hdr.shnum.data = block;
	
	// e_shstrndx
	file.seekg (2, std::ios::cur);
	block = new char [2];
	file.read (block, 2);
	//if (!hdr.shstrndx.load (block, 2))
	//	return false;
	hdr.shstrndx.data = block;
	
	
	// now, the program header table
	
	
	return true;
}

const unsigned int noware::elf::str_int (const std::string & block, const bool & swap) const
{
	unsigned int val;
	unsigned int size;
	std::stringstream ss;
	
	//val = 0;
	size = block.size ();
	ss << std::hex;
	
	if (swap)
	{
		for (signed int ndx = size; ndx >= 0; --ndx)
		{
			//std::cout << "ndx:" << ndx << std::endl;
			ss << int (block [ndx]);
		}
	}
	else
	{
		for (unsigned int ndx = 0; ndx < size; ++ndx)
		{
			//std::cout << "ndx:" << ndx << std::endl;
			ss << int (block [ndx]);
		}
	}
	
	ss >> val;
	
	return val;
}

const bool noware::elf::loaded (void) const
{
	return _loaded;
}

const bool noware::elf::clear (void)
{
	return false;
}
