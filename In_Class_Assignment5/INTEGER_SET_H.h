#pragma once
class IntegerSet {
public:
	IntegerSet(); // constructor

	void unionOfSets(IntegerSet,IntegerSet);

	void intersectionOfSets(IntegerSet, IntegerSet);

	void inputSet(); // read values from user

	void printSet() const;

private:
	int set[101]; // range of 0 - 100

	// determines a valid entry to the set
	int validEntry(int x) const
	{
		return (x >= 0 && x <= 100);
	} // end function validEntry

};