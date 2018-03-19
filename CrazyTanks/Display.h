#ifndef DISPLAY_H_
#define DISPLAY_H_

class Display
{
public:
	Display();
	~Display();

	const int fourthDisplay = 15;
	const int secondsInHour = 3600;
	const int secondsInMinute = 60;

	const void setTimer(int time);
	
	int getTimer();

	const std::pair<short, short>windowSize = { 50,54 };

	static void drawScore(const std::pair<short, short> &elementPos, int currentScore);

private:
	clock_t firstTimer_;
	int timer_;
};


#endif // !DISPLAY_H_
