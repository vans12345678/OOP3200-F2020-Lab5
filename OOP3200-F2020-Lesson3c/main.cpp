#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <iterator>
#include "Vector2D.h"


int main()
{

	std::map<std::string, Vector2D<int>*> vectorObjects;
	std::string keyFind;
	const std::string fileName = "MockDataForTesting.txt";
	std::ifstream infile;
	
	
	try
	{
		/************************
		 *	DECLARATIONS
		 ************************/
		

		/******************************************************************************
		 *	Reading Labels/Points into the Map:
		 *	Attempt to open the data file.  If the data file opens, read a label,
		 *	followed by a point and insert them into the map using the label as the key.
		 *	Repeat until all the data is read and close the file. If the data file did
		 *	not open, tell the user and remind them to check that the file exists. If
		 *	the file opened but the map is empty after the input loop, report that to
		 *	the user and remind them to check that the file contains valid data in
		 *	the correct format. Only continue processing if the file was opened and the
		 *	map is not empty.
		 ******************************************************************************/
		
		infile.open(fileName.c_str());
		if(!infile)
		{
			throw std::runtime_error("Cannot open file specified.");
		}
		
		if (infile.is_open())
		{
			std::string key;
			int x, y = 0;

			while (!infile.fail())
			{
				infile >> key;
				infile.ignore(1, ' ');
				infile.ignore(1, '(');
				infile >> x;
				infile.ignore(1, ',');
				infile >> y;
				infile.ignore(1, ')');
				
				//If cannot take in any information
				if(infile.fail())
				{
					std::cout << "It appears no information can be taken in..." << std::endl;
				}
				//If there is information to take in
				else
				{
					auto* tempObject = new Vector2D<int>(x, y);
					vectorObjects[key] = tempObject;
				}
				
			}

			//Close input file stream
			infile.close();
			
			//If there is no objects in map
			if (vectorObjects.empty())
			{
				throw std::runtime_error("Map is empty, does file have valid data in correct format?");
			}
		}

		infile.close();
		//For every vector2D in vectorObjects loop
		float totalDistance = 0;
		
	
			// if()
			// {
			// 	it = vectorObjects.erase(it);
			// 	next = vectorObjects.erase(next);
			// }

		for(auto it = vectorObjects.begin(); it !=vectorObjects.end(); ++it)
		{
			auto next = it;
			
			std::cout << "---------------------------------" << std::endl;
			std::cout << "Key:" << it->first << std::endl;
			std::cout << "Value: " << std::endl;			
			std::cout << it->second->ToString() << std::endl;

			if(std::next(it) != vectorObjects.end())
			{
				++next;
				float distance = Vector2D<float>::Distance(vectorObjects[it->first]->GetMagnitude(), vectorObjects[next->first]->GetMagnitude());
				std::cout << "Distance between: " << it->first << " and " << next->first << " is: " << distance << std::endl;
			}
			
			
		}
		

			
		// //Calculate distance
		// const auto next= std::next(it.first.begin(), 1)d
			

		
		std::cout << "There are " << vectorObjects.size() << " amount of vectorObjects in map." << std::endl;
		std::cout << "Enter a key to search for in the map: ";
		std::cin >> keyFind;

		std::cout << "---------------------------------" << std::endl;
		std::cout << "Key:" << keyFind << std::endl;
		std::cout << "Value: " << std::endl;
		std::cout << vectorObjects[keyFind]->ToString() << std::endl;

		
		

		/******************************************************************************
		 *	Determine the Total Distance Between All Points in Order:
		 *	Use an iterator and a loop to traverse each label/point in the map. For
		 *	each label/point, determine the distance from that point to the previous
		 *	point (or next point depending on how you implement this) and add that
		 *	distance to a total.  Note that the Vector2D class includes a static 
		 *	distance function to determine the distance between two Vector2D
		 *	objects, so you should not need to use any complicated math here.  Report
		 *	to the user how many points the map contains and what the total distance is.
		 ******************************************************************************/

				

		/******************************************************************************
		 *	Determine the Distance Between the Start Point and a User Selected Point:
		 *	Prompt the user to enter a label or to enter "quit" to end.  If the user
		 *	entered anything other than "quit", attempt to find the label they entered
		 *	in the map. If it was found, report the distance between the point for the
		 *	label they entered and the start point (i.e. the point labeled "AA").
		 *	Otherwise, tell the user that the label they entered is not in the map.
		 *	Repeat these steps until the user enters "quit".
		 ******************************************************************************/
		
	}
	/******************************************************************************
	 *	Exception Handling:
	 *	Catch any std::exception thrown. Report to the user that a run-time error
	 *	occurred and show what exception was thrown.
	 ******************************************************************************/
	catch(std::exception& e)  // an exception was thrown
	{	
		std::cout << "ERROR "<< e.what();
	}

	// END-OF-PROGRAM
	
	return 0;
}

