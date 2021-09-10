//i have done this on my own and only uesd the code provided in the wowrkshop
//name: Rujal Tuladhar
//senecaid: 154594188
//email: rtuladhar@myseneca.ca
#ifndef SDDS_File_h
#define SDDS_File_h
#include"ShoppingRec.h"




namespace sdds
{
	
	const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}



#endif