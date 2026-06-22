#pragma once

template <typename T>
void	swap(T& parameter1, T& parameter2)
{
	T	temp;

	temp = parameter1;
	parameter1 = parameter2;
	parameter2 = temp;
}

template <typename T>
T	min(T& parameter1, T& parameter2)
{
	return (parameter1 < parameter2 ? parameter1 : parameter2);
}

template <typename T>
T	max(T& parameter1, T& parameter2)
{
	return (parameter1 > parameter2 ? parameter1 : parameter2);
}
