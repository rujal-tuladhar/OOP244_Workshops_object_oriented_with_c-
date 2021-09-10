//i have done this on my own and only uesd the code provided in the wowrkshop
//name: Rujal Tuladhar
//senecaid: 154594188
//email: rtuladhar@myseneca.ca
#ifndef SDDS_ShoppingRec_h
#define SDDS_ShoppingRec_h



namespace sdds
{
	const int MAX_TITLE_LENGTH = 50;
	struct ShoppingRec
	{
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};


	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);



}
#endif // !SDDS_ShoppingRec_h

