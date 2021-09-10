//Name-RUjal Tuladhar
//seneca_id -154594188
//this assignment was done by me using the workshop instruction provided by my proffesor
#include <iostream>
#ifndef _SDDS_SEARCHNLIST_H
#define _SDDS_SEARCHNLIST_H
#include "Collection.h"

namespace sdds {
	template<typename C, typename K>
	bool search(Collection<C>& results, const C dataSet[], unsigned int maxIndex, K key) {
		// Checks if an element inside collectionArr matches key. Call add() using the index if it matches.
		// Also changes found to true if a match was found.

		bool found = false;
		for (unsigned int i = 0; i < maxIndex; i++) {
			if (dataSet[i] == key) {
				results.add(dataSet[i]);
				found = true;
			}
		}
		return found;
	}

	template<typename C>
	void listArrayElements(const char* title, const C dataSet[], unsigned int maxIndex) {
		// Prints the title of the list, and lists each item inside collectionArr one by one.

		std::cout << title << std::endl;
		for (unsigned int i = 0; i < maxIndex; i++) {
			std::cout << i + 1 << ": " << dataSet[i] << std::endl;
		}
	}
}
#endif // !_SDDS_SEARCHNLIST_H