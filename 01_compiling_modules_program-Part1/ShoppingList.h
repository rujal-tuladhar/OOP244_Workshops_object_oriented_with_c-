//i have done this on my own and only uesd the code provided in the wowrkshop
//name: Rujal Tuladhar
//senecaid: 154594188
//email: rtuladhar@myseneca.ca
#ifndef SDDS_ShoppingList_h
#define SDDS_ShoppingList_H

namespace sdds
{


	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();

}


#endif
