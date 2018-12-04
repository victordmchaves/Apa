#include <chrono>
#include "sorts.h"

void selectionSort(std::vector<long> &vec);
void insertionSort(std::vector<long> &vec);

int main(int argc, char **argv)
{

	long value;
	bool firstEntry = true;
	std::ifstream fileIn(argv[2], std::ios::in); // ./program number example.in
	std::vector<long> vec;

	// Ler arquivo
	while (fileIn >> value)
	{
		if (firstEntry == true)
		{
			vec.reserve(value);
			firstEntry = false;
		}

		else
			vec.push_back(value);
	}
	fileIn.close();

	switch (atoi(argv[1]))
	{ //converter em long
	case 1:
	{ //Selection Sort

		std::cout << "Selection Sort selected, please wait a moment" << std::endl;

		// Iniciar contador
		const auto start_time = std::chrono::steady_clock::now();
		selectionSort(vec);
		double time_in_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();
		// Fim contador

		std::cout << "Selection Sort Time Elapsed: " << time_in_milliseconds << " milliseconds" << std::endl;
		break;
	}
	case 2:
	{ //Insertion Sort

		std::cout << "Insertion Sort selected, please wait a moment" << std::endl;

		// Iniciar contador
		const auto start_time = std::chrono::steady_clock::now();
		insertionSort(vec);
		double time_in_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();
		// Fim contador

		std::cout << "Insertion Sort Time Elapsed: " << time_in_milliseconds << " milliseconds" << std::endl;
		break;
	}
	default:
	{
		return EXIT_FAILURE;
	}
	}

	std::ofstream output_file(argv[3]); //cria o arquivo de saida
	std::ostream_iterator<long> output_iterator(output_file, "\n");
	std::copy(vec.begin(), vec.end(), output_iterator); //copia os valores pro arquivo

	return 0;
}
