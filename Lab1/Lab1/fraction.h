#pragma once


class fraction
{
private:
	double first;
	int second;

public:
	bool Init(double f, int s);
	void Read();
	void Show() const;
	double Power() const;
	double element(int j) const;

	double getFirst() const
	{
		return first;
	}
	int getSecond() const
	{
		return second;
	}
};