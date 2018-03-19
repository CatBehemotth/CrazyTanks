#ifndef UPDATEDISPLAY_H_
#define UPDATEDISPLAY_H_

class UpdateDisplay
{
public:
	static void drowElemnt(const std::pair<short, short>& elementPos, char element);
	static void cleanDisplay(const std::pair<short, short>& boardSize, char element);
};
#endif // !UPDATEDISPLAY_H_