#include <chrono>
#include "sorts.h"

void selectionSort(std::vector<long> &vec);
void insertionSort(std::vector<long> &vec);

int main(int argc, char **argv)
{
	// value of the vector/array
	long value;
	bool firstEntry = true;
	std::ifstream fileIn(argv[2], std::ios::in); // ./program number example.in
	std::vector<long> vec;

	// read the file
	while (fileIn >> value)
	{
		// firstentry/firstvalue = size of the vector
		if (firstEntry == true)
		{
			vec.reserve(value);
			firstEntry = false;
		}
		// insert the other values in the vector
		else
			vec.push_back(value);
	}
	fileIn.close();

	switch (atoi(argv[1]))
	{ //convert number string in long
	case 1:
	{ //Selection Sort

		std::cout << "Selection Sort selected, please wait a moment" << std::endl;

		// Start counting Time
		const auto start_time = std::chrono::steady_clock::now();
		selectionSort(vec);
		double time_in_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();
		// End counting Time

		std::cout << "Selection Sort Time Elapsed: " << time_in_milliseconds << " milliseconds" << std::endl;
		break;
	}
	case 2:
	{ //Insertion Sort

		std::cout << "Insertion Sort selected, please wait a moment" << std::endl;

		// Start counting Time
		const auto start_time = std::chrono::steady_clock::now();
		insertionSort(vec);
		double time_in_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();
		// End counting Time

		std::cout << "Insertion Sort Time Elapsed: " << time_in_milliseconds << " milliseconds" << std::endl;
		break;
	}
	default:
	{
		return EXIT_FAILURE;
	}
	}

	std::ofstream output_file(argv[3]); //create an output file
	std::ostream_iterator<long> output_iterator(output_file, "\n");
	std::copy(vec.begin(), vec.end(), output_iterator); //copy the ordered values of the vector in the file

	return 0;
}
