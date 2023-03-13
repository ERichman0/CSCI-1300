#include "Racetrack.h"

RaceTrack::RaceTrack()
{
	name = "NASCAR";
}

RaceTrack::RaceTrack(string raceName)
{
	name = raceName;
}

bool RaceTrack::addCar(double topSpeed, string carModel)
{
	if (models.size() < 100)
	{
		speeds.push_back(topSpeed);
		models.push_back(carModel);
		return true;
	}

	return false;
}

double RaceTrack::calcAvgSpeed()
{   
	int count=0; 
	double sum=0;
	for (int i=0 ; i < speeds.size() ; i++) 
		if (speeds[i] > 0.) 
		{
			sum += speeds[i]; 
			count++;
		}
	
	if (count > 0)
		return sum / count;
	else
		return 0;
}

int RaceTrack::countAvailable(double minSpeed)
{   int count=0; 
	for (int i=0 ; i < speeds.size() ; i++) 
		if (speeds[i] >= minSpeed) 
			count++;
	return count;
}

int RaceTrack::countAvailableModels(string model)
{   
	int count=0; 
	for (int i=0 ; i < models.size() ; i++) 
		if (models[i] == model) 
			count++;
	return count;
}